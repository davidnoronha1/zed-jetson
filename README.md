# zed-jetson

Docker image for running the [ZED ROS 2 wrapper](https://github.com/stereolabs/zed-ros2-wrapper)
on NVIDIA Jetson (JetPack 6.2.2 / L4T 36.5, Orin), with ROS 2 Jazzy built from source and the
ZED SDK 5.2 layered on top.

## Quick Start

### Using Docker Compose (Recommended)

```bash
git submodule update --init --recursive

# Pull pre-built image from ghcr.io (falls back to local build if unavailable)
docker-compose -f docker/docker-compose.yml up -it

# Or force a local build
docker-compose -f docker/docker-compose.yml up --build -it

# Use a specific image tag
IMAGE_TAG=master docker-compose -f docker/docker-compose.yml up -it
```

Once in the container:

```bash
ros2 launch zed_wrapper zed_camera.launch.py camera_model:=zed2i
```

### Using Docker CLI

```bash
docker run --runtime nvidia -it --network host --privileged \
  -v /dev:/dev \
  ghcr.io/davidnoronha1/zed-jetson:latest \
  ros2 launch zed_wrapper zed_camera.launch.py camera_model:=zed2i
```

## Why build ROS 2 from source

There is no official ROS 2 Jazzy apt distribution for L4T/Jetson, so the image builds it from
source against the L4T JetPack base image (`nvcr.io/nvidia/l4t-jetpack:r36.4.0`). The ZED SDK is
then installed in a second stage on top of that ROS 2 layer.

## Project Layout

```
.
├── docker/                    # Docker configuration
│   ├── Dockerfile            # Two-stage build: ROS 2 → ZED SDK + workspace
│   ├── docker-compose.yml    # Compose config with ghcr fallback
│   ├── ros2_build.sh         # Bootstrap script for ROS 2 from source
│   ├── ros2_install.sh       # Helper for adding packages to workspace
│   ├── rosdeps.yml           # Custom rosdep keys
│   ├── ros_entrypoint.sh     # Container entry point
│   └── ros_environment.sh    # ROS environment setup
├── src/                      # ROS 2 workspace (git submodules)
│   ├── zed-ros2-wrapper/     # ZED camera wrapper and debugging tools
│   └── [other packages]      # Supporting packages: angles, diagnostics, etc.
├── scripts/                  # Utility scripts
│   └── object_detection_launch.sh  # Launch ZED debug with custom ONNX model
├── config/                   # Configuration files
│   ├── common_stereo.yaml
│   └── custom_object_detection_docking.yaml
├── docking.onnx             # Custom object detection model
└── README.md
```

## Building

Submodules must be checked out before building:

```bash
git submodule update --init --recursive
```

### Local Build

```bash
docker build -f docker/Dockerfile -t zed-jetson .
```

### Using Docker Compose

```bash
docker-compose -f docker/docker-compose.yml build
```

The image must be built for `linux/arm64` on a Jetson (or an arm64 builder) — the base image is
Jetson-specific and the ZED SDK download is fetched for L4T 36.5.

**Build args** (see `docker/Dockerfile` for defaults):
- `ROS_PACKAGE` — ROS metapackage (default: `ros_base`)
- `ROS_VERSION` — ROS distro (default: `jazzy`)
- `L4T_MAJOR_VERSION`, `L4T_MINOR_VERSION`, `L4T_PATCH_VERSION` — L4T version
- `ZED_URL` — ZED SDK download URL (can be set via build args or environment)

## Object Detection Demo

The `scripts/object_detection_launch.sh` script sets up and launches the ZED debug node with
a custom ONNX model for object detection:

```bash
# Inside the container:
/scripts/object_detection_launch.sh
```

This script:
1. Copies config files from `config/` into the ZED debug package
2. Updates ONNX model paths to point to `docking.onnx`
3. Enables object detection service
4. Launches the debug camera with the custom model
5. Requires a `colcon build` (or rebuild) of the workspace to pick up the copied config

## Container Runtime Requirements

`--runtime nvidia` — GPU access for CUDA operations

`--privileged -v /dev:/dev` — Camera access (USB/CSI) on Jetson

`--network host` — ROS 2 network communication

Docker Compose handles these automatically via the `docker-compose.yml` configuration.

## Adding Workspace Packages

Add new source packages as git submodules under `src/`:

```bash
git submodule add <repo-url> src/<package-name>
```

Anything under `src/` is automatically picked up by the `colcon build` in the Docker build process.
