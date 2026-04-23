#!/bin/bash

# Copy custom config files to zed-ros2-wrapper (overwrite if exists)
cp /home/ssen4/Projects/zed-jetson/common_stereo.yaml /home/ssen4/Projects/zed-jetson/src/zed-ros2-wrapper/zed_debug/config/common_stereo.yaml
cp /home/ssen4/Projects/zed-jetson/custom_object_detection_docking.yaml /home/ssen4/Projects/zed-jetson/src/zed-ros2-wrapper/zed_debug/config/custom_object_detection_docking.yaml

# Enable object detection service
ros2 service call /zed/zed_node/enable_obj_det std_srvs/srv/SetBool "data: true"

# Launch ZED camera with custom object detection
ros2 launch zed_debug zed_camera.launch.py \
  camera_model:=ZED2i \
  custom_object_detection_config_path:=/home/ssen4/Projects/zed-jetson/custom_object_detection_docking.yaml