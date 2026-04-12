// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from custom_msgs:msg/Telemetry.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "custom_msgs/msg/telemetry.h"


#ifndef CUSTOM_MSGS__MSG__DETAIL__TELEMETRY__STRUCT_H_
#define CUSTOM_MSGS__MSG__DETAIL__TELEMETRY__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

// Constants defined in the message

/// Struct defined in msg/Telemetry in the package custom_msgs.
typedef struct custom_msgs__msg__Telemetry
{
  float x;
  float y;
  float z;
  float roll;
  float pitch;
  float yaw;
} custom_msgs__msg__Telemetry;

// Struct for a sequence of custom_msgs__msg__Telemetry.
typedef struct custom_msgs__msg__Telemetry__Sequence
{
  custom_msgs__msg__Telemetry * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} custom_msgs__msg__Telemetry__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // CUSTOM_MSGS__MSG__DETAIL__TELEMETRY__STRUCT_H_
