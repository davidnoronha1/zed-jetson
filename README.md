# zed-jetson

Docker image for running the [ZED ROS 2 wrapper](https://github.com/stereolabs/zed-ros2-wrapper)
on NVIDIA Jetson (JetPack 6.2.2 / L4T 36.5, Orin), with ROS 2 Jazzy built from source and the
ZED SDK 5.2 layered on top.

## Why build ROS 2 from source

There is no official ROS 2 Jazzy apt distribution for L4T/Jetson, so the image builds it from
source against the L4T JetPack base image (`nvcr.io/nvidia/l4t-jetpack:r36.4.0`). The ZED SDK is
then installed in a second stage on top of that ROS 2 layer.

## Layout

- `Dockerfile` — two-stage build: `ros2_build` (ROS 2 Jazzy from source) → `final` (+ ZED SDK,
  workspace build).
- `ros2_build.sh` — builds ROS 2 Jazzy (`ros_base`) from source via `rosinstall_generator` +
  `vcs` + `colcon`. Runs once during the image build.
- `rosdeps.yml` — extra rosdep keys not covered by the upstream rosdistro index.
- `ros_environment.sh` / `ros_entrypoint.sh` — sourced at container start to bring the ROS 2
  install and workspace overlay onto `PATH`/`AMENT_PREFIX_PATH`.
- `ros2_install.sh` — standalone helper for pulling in and building extra ROS 2 packages
  (from rosdistro or a git URL) inside a running container or a derived image, without needing
  the full `ros2_build.sh` bootstrap.
- `src/` — git submodules for the ROS 2 workspace built into `/ros_ws` in the final image
  (ZED wrapper/interfaces/description, plus supporting packages: `angles`, `backward_ros`,
  `diagnostics`, `geographic_info`, `nmea_msgs`, `xacro`).
- `config/` — project-local override configs (not part of any submodule), e.g. custom object
  detection models/classes. Copied into the `zed_debug` package config at runtime by
  `object_detection_launch.sh`.

## Object detection demo

`object_detection_launch.sh` copies `config/common_stereo.yaml` and
`config/custom_object_detection_docking.yaml` into `src/zed-ros2-wrapper/zed_debug/config/`
(rewriting the ONNX model path to the current checkout), enables the object detection service,
and launches `zed_debug`'s debug camera launch file with the custom ONNX model (`docking.onnx`)
configured. Requires a `colcon build` (or rebuild) of the workspace afterward to pick up the
copied config, since the image is built without `--symlink-install`.

## Building

Submodules must be checked out before building, since the workspace sources are copied straight
from `src/` into the image:

```bash
git submodule update --init --recursive
docker build -t zed-jetson .
```

The image must be built `linux/arm64` on a Jetson (or an arm64 builder) — the base image is
Jetson-specific and the ZED SDK download is fetched for L4T 36.5. CI (`.github/workflows/build-push.yaml`)
does this on `ubuntu-24.04-arm` runners.

Build args (see `Dockerfile` for defaults): `ROS_PACKAGE`, `ROS_VERSION`, `L4T_MAJOR_VERSION`,
`L4T_MINOR_VERSION`, `L4T_PATCH_VERSION`, `ZED_URL`.

## Running

```bash
docker run --runtime nvidia -it --network host --privileged \
  -v /dev:/dev \
  zed-jetson \
  ros2 launch zed_wrapper zed_camera.launch.py camera_model:=zed2i
```

`--runtime nvidia` and `--privileged -v /dev:/dev` are required for GPU and camera (USB/CSI)
access on Jetson.

## Adding workspace packages

Add new source packages as git submodules under `src/` (see `.gitmodules`) rather than cloning
them ad hoc — anything under `src/` is picked up automatically by the workspace `colcon build`
in the final image stage.
