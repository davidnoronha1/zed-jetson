#!/bin/bash
set -euo pipefail

REPO_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
CONFIG_DIR="$REPO_DIR/config"
ZED_DEBUG_CONFIG_DIR="$REPO_DIR/src/zed-ros2-wrapper/zed_debug/config"
CUSTOM_OD_CONFIG="$ZED_DEBUG_CONFIG_DIR/custom_object_detection_docking.yaml"

# Copy custom config files to zed-ros2-wrapper (overwrite if exists)
cp "$CONFIG_DIR/common_stereo.yaml" "$ZED_DEBUG_CONFIG_DIR/common_stereo.yaml"

# Rewrite the ONNX model path to this checkout's location (the checked-in yaml
# has a placeholder path that only worked on the original author's machine)
sed "s#custom_onnx_file: .*#custom_onnx_file: '$REPO_DIR/docking.onnx'#" \
  "$CONFIG_DIR/custom_object_detection_docking.yaml" > "$CUSTOM_OD_CONFIG"

# Enable object detection service
ros2 service call /zed/zed_node/enable_obj_det std_srvs/srv/SetBool "data: true"

# Launch ZED camera with custom object detection
ros2 launch zed_debug zed_camera_debug.launch.py \
  camera_model:=zed2i \
  custom_object_detection_config_path:="$CUSTOM_OD_CONFIG"
