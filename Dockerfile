#
# Dockerfile: ROS2 Jazzy (from source) + ZED SDK 5.2
# Target: JetPack 6.2.2 / L4T 36.5 / Jetson Orin
#

# ── Stage 1: ROS2 ────────────────────────────────────────────────────────────
FROM nvcr.io/nvidia/l4t-jetpack:r36.4.0 AS ros2_build

ARG ROS_PACKAGE=ros_base \
    ROS_VERSION=jazzy \
    TMP=/tmp/warp

ENV ROS_DISTRO=${ROS_VERSION} \
    ROS_ROOT=/opt/ros/${ROS_VERSION} \
    ROS_PYTHON_VERSION=3 \
    RMW_IMPLEMENTATION=rmw_fastrtps_cpp \
    RTI_NC_LICENSE_ACCEPTED=yes \
    DEBIAN_FRONTEND=noninteractive \
    SHELL=/bin/bash \
    CUDA_HOME="/usr/local/cuda" \
    NVCC_PATH="/usr/local/cuda/bin/nvcc" \
    VENV_PATH="/opt/venv" \
    PYTHONNOUSERSITE=1 \
    WGET_FLAGS="--quiet --show-progress --progress=bar:force:noscroll --no-check-certificate --timeout=60 --tries=3" \
    CMAKE_POLICY_VERSION_MINIMUM=3.5

SHELL ["/bin/bash", "-c"]

RUN update-alternatives --install /usr/bin/python python /usr/bin/python3 1

COPY ros2_build.sh rosdeps.yml $TMP/
RUN $TMP/ros2_build.sh || touch $TMP/.ros.build.failed

RUN if [ -f $TMP/.ros.build.failed ]; then \
      echo "ROS ${ROS_DISTRO} build failed!" && exit 1; \
    fi

RUN if [ "$(lsb_release -rs)" = '24.04' ]; then \
      echo "#!/usr/bin/env bash" > "/opt/venv/bin/register-python-argcomplete"; \
    fi

RUN /tmp/numpy/install.sh && /tmp/cmake/install.sh

COPY ros_entrypoint.sh ros_environment.sh ros2_install.sh /

# ── Stage 2: ZED SDK ─────────────────────────────────────────────────────────
FROM ros2_build AS final

ARG L4T_MAJOR_VERSION=36 \
    L4T_MINOR_VERSION=5 \
    L4T_PATCH_VERSION=0 \
    # ZED SDK 5.2 for JetPack 6.2.2 / L4T 36.5
    ZED_URL=https://download.stereolabs.com/zedsdk/5.2/l4t36.5/jetsons

ENV LOGNAME=root \
    DEBIAN_FRONTEND=noninteractive

RUN ln -sf /usr/lib/$(uname -m)-linux-gnu/tegra/libv4l2.so.0 \
           /usr/lib/$(uname -m)-linux-gnu/libv4l2.so

RUN apt-get update -y || true && \
    apt-get install --no-install-recommends \
        lsb-release wget less zstd udev sudo apt-transport-https -y && \
    wget --quiet -O ZED_SDK_Linux.run ${ZED_URL} && \
    chmod +x ZED_SDK_Linux.run && \
    ./ZED_SDK_Linux.run -- silent skip_drivers && \
    rm -rf /usr/local/zed/resources/* && \
    rm -f ZED_SDK_Linux.run && \
    rm -rf /var/lib/apt/lists/* && \
    apt-get clean

RUN wget --quiet download.stereolabs.com/zedsdk/pyzed -O /usr/local/zed/get_python_api.py && \
    python3 /usr/local/zed/get_python_api.py && \
    python3 -m pip install pyopengl *.whl && \
    rm -f *.whl && \
    rm -rf /usr/local/zed/resources

RUN mkdir -p /data/zed/resources && \
    mkdir -p /root/.cache/zed/resources && \
    ln -s /data/zed /root/.cache/zed && \
    ln -s /root/.cache/zed/resources /usr/local/zed/resources

ENTRYPOINT ["/ros_entrypoint.sh"]
CMD ["/bin/bash"]
