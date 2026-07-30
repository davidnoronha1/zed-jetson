#!/bin/bash
set -e

# setup ros environment
source "/opt/ros/$ROS_DISTRO/setup.bash"
source "$ROS_WS/install/setup.bash"
exec "$@"
