#!/usr/bin/env bash
# ROS2 build from source - standalone version (no jetson-containers infra needed)
set -euo pipefail

export CUDA_HOME="/usr/local/cuda"
export NVCC_PATH="$CUDA_HOME/bin/nvcc"
SKIP_KEYS=${SKIP_KEYS:-""}
SKIP_KEYS="$SKIP_KEYS image_proc"
SEPARATOR="********************************************************"

print_log() { printf "\n$SEPARATOR\n$1\n$SEPARATOR\n\n"; }

print_log "ROS2 $ROS_DISTRO installer ($(uname -m))
   ROS_DISTRO=$ROS_DISTRO
   ROS_PACKAGE=$ROS_PACKAGE
   ROS_ROOT=$ROS_ROOT
   VENV_PATH=$VENV_PATH"

# ── Apt repos & base tools ───────────────────────────────────────────────────
apt-get update
apt-get install -y --no-install-recommends \
  curl wget gnupg2 lsb-release ca-certificates libssl-dev python3-venv git git-lfs

curl -sSL https://raw.githubusercontent.com/ros/rosdistro/master/ros.key \
  -o /usr/share/keyrings/ros-archive-keyring.gpg
echo "deb [arch=$(dpkg --print-architecture) signed-by=/usr/share/keyrings/ros-archive-keyring.gpg] \
http://packages.ros.org/ros2/ubuntu $(lsb_release -cs) main" |
  tee /etc/apt/sources.list.d/ros2.list >/dev/null
apt-get update

maybe_install() {
  local pkg="$1"
  local cand
  cand="$(apt-cache policy "$pkg" | awk '/Candidate:/ {print $2}')"
  if [ "${cand:-"(none)"}" != "(none)" ]; then
    apt-get install -y --no-install-recommends "$pkg"
  else
    echo ">> Skipping $pkg: not available"
  fi
}

# ── System dev libs ──────────────────────────────────────────────────────────
apt-get install -y --no-install-recommends \
  build-essential cmake pkg-config \
  libeigen3-dev libbullet-dev libpython3-dev \
  libasio-dev libtinyxml2-dev libcunit1-dev \
  libacl1-dev libssl-dev libxaw7-dev libfreetype-dev 

maybe_install "rti-connext-dds-6.0.1"

# ── Create virtualenv ────────────────────────────────────────────────────────
python3 -m venv "$VENV_PATH" --system-site-packages
touch "$VENV_PATH/COLCON_IGNORE" || true
source "$VENV_PATH/bin/activate"

# Detect Python version dynamically
PYTHON_VERSION=$(python3 -c 'import sys; print(f"{sys.version_info.major}.{sys.version_info.minor}")')
export PYTHONPATH="$VENV_PATH/lib/python${PYTHON_VERSION}/site-packages:/usr/lib/python3/dist-packages${PYTHONPATH:+:$PYTHONPATH}"

# ── Install uv, then Python tooling ─────────────────────────────────────────
pip install --upgrade pip uv

uv pip install --upgrade \
  colcon-common-extensions \
  vcstool rosinstall_generator rosdep \
  pytest pytest-cov pytest-repeat pytest-rerunfailures \
  flake8 \
  flake8-blind-except flake8-builtins flake8-class-newline \
  flake8-comprehensions flake8-deprecated flake8-docstrings \
  flake8-import-order flake8-quotes \
  argcomplete \
  lark scikit-build

# EmPy 3.x pin (rosidl breaks on 4+)
uv pip uninstall em empy || true
uv pip install --no-cache-dir "empy==3.3.4"

# ── cmake / numpy (copy scripts in if you have them, else install directly) ──
if [ -f /tmp/cmake/install.sh ]; then
  bash /tmp/cmake/install.sh
else
  uv pip install "cmake>=3.26"
fi

if [ -f /tmp/numpy/install.sh ]; then
  bash /tmp/numpy/install.sh
else
  uv pip install "numpy<2"
fi

# ── Remove python3.9 if present (CMake NumPy discovery conflicts) ────────────
apt purge -y python3.9 libpython3.9* 2>/dev/null || echo "python3.9 not found, skipping"

# ── Build from source ────────────────────────────────────────────────────────
print_log "BUILDING ROS2 $ROS_DISTRO from source ($ROS_PACKAGE)"
mkdir -p "${ROS_ROOT}/src"
cd "${ROS_ROOT}"

# rosdep extras
ROSDEP_DIR="/etc/ros/rosdep/sources.list.d"
mkdir -p "$ROSDEP_DIR"
if [ -f "$TMP/rosdeps.yml" ]; then
  cp "$TMP/rosdeps.yml" "$ROSDEP_DIR/extra-rosdeps.yml"
  echo "yaml file://$ROSDEP_DIR/extra-rosdeps.yml" | tee "$ROSDEP_DIR/00-extras.list"
fi

# Humble/Iron on bionic patches
if { [ "$ROS_DISTRO" = "humble" ] || [ "$ROS_DISTRO" = "iron" ]; } &&
  [ "$(lsb_release --codename --short)" = "bionic" ]; then
  SKIP_KEYS="$SKIP_KEYS rti-connext-dds-6.0.1 ignition-cmake2 ignition-math6"
  apt-get install -y --no-install-recommends gcc-8 g++-8
  export CC="/usr/bin/gcc-8" CXX="/usr/bin/g++-8"
  git -C /tmp clone -b yaml-cpp-0.6.0 https://github.com/jbeder/yaml-cpp.git
  cmake -S /tmp/yaml-cpp -B /tmp/yaml-cpp/BUILD -DBUILD_SHARED_LIBS=ON
  cmake --build /tmp/yaml-cpp/BUILD --parallel "$(nproc --ignore=1)"
  cmake --install /tmp/yaml-cpp/BUILD
  rm -rf /tmp/yaml-cpp
fi

rosinstall_generator --deps --rosdistro "${ROS_DISTRO}" "${ROS_PACKAGE}" \
  launch_xml launch_yaml launch_testing launch_testing_ament_cmake \
  demo_nodes_cpp demo_nodes_py example_interfaces \
  camera_calibration_parsers camera_info_manager \
  cv_bridge v4l2_camera vision_opencv vision_msgs \
  image_geometry image_pipeline image_transport \
  compressed_image_transport compressed_depth_image_transport \
  rosbag2_storage_mcap rmw_fastrtps \
  >"ros2.${ROS_DISTRO}.${ROS_PACKAGE}.rosinstall"

vcs import src <"ros2.${ROS_DISTRO}.${ROS_PACKAGE}.rosinstall"

rm -rf "${ROS_ROOT}/src/ament_cmake"
git -C "${ROS_ROOT}/src" clone https://github.com/ament/ament_cmake -b "${ROS_DISTRO}"

find src -name setup.cfg -type f -print0 | while IFS= read -r -d '' f; do
  grep -q '^\[build\]' "$f" || {
    printf '\n[build]\nexecutable=/usr/bin/env python3\n' >>"$f"
  }
done

rosdep init || true
rosdep update

rosdep keys \
  --from-paths src \
  --ignore-src \
  --rosdistro "$ROS_DISTRO" |
  xargs rosdep resolve |
  grep -v '#' |
  grep -v opencv |
  grep -v pybind11 \
    >rosdeps.txt

xargs -a rosdeps.txt apt-get install -y --no-install-suggests --no-install-recommends

colcon build \
  --merge-install \
  --packages-skip image_proc image_rotate depth_image_proc \
  --cmake-args \
  -Wno-dev \
  -DCMAKE_BUILD_TYPE=Release \
  -DCMAKE_POLICY_DEFAULT_CMP0148=OLD \
  -DCMAKE_POLICY_VERSION_MINIMUM=3.5 \
  -DSECURITY=ON || true

# ── Cleanup ──────────────────────────────────────────────────────────────────
rm -rf "${ROS_ROOT}/src" "${ROS_ROOT}/log" "${ROS_ROOT}/build"
rm -f "${ROS_ROOT}"/*.rosinstall
rm -rf /var/lib/apt/lists/*
apt-get clean

print_log "ROS2 $ROS_DISTRO build complete"
