// generated from rosidl_generator_c/resource/idl__description.c.em
// with input from custom_msgs:msg/Telemetry.idl
// generated code does not contain a copyright notice

#include "custom_msgs/msg/detail/telemetry__functions.h"

ROSIDL_GENERATOR_C_PUBLIC_custom_msgs
const rosidl_type_hash_t *
custom_msgs__msg__Telemetry__get_type_hash(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0xa1, 0x47, 0x4f, 0x4f, 0x34, 0x44, 0x0f, 0xa7,
      0xb2, 0xb4, 0x02, 0x44, 0x61, 0x2c, 0xb9, 0x7d,
      0xa8, 0x93, 0x3a, 0xaf, 0xba, 0xeb, 0x58, 0xe3,
      0xa1, 0x6a, 0xf5, 0xac, 0xe3, 0xf3, 0x1c, 0x41,
    }};
  return &hash;
}

#include <assert.h>
#include <string.h>

// Include directives for referenced types

// Hashes for external referenced types
#ifndef NDEBUG
#endif

static char custom_msgs__msg__Telemetry__TYPE_NAME[] = "custom_msgs/msg/Telemetry";

// Define type names, field names, and default values
static char custom_msgs__msg__Telemetry__FIELD_NAME__x[] = "x";
static char custom_msgs__msg__Telemetry__FIELD_NAME__y[] = "y";
static char custom_msgs__msg__Telemetry__FIELD_NAME__z[] = "z";
static char custom_msgs__msg__Telemetry__FIELD_NAME__roll[] = "roll";
static char custom_msgs__msg__Telemetry__FIELD_NAME__pitch[] = "pitch";
static char custom_msgs__msg__Telemetry__FIELD_NAME__yaw[] = "yaw";

static rosidl_runtime_c__type_description__Field custom_msgs__msg__Telemetry__FIELDS[] = {
  {
    {custom_msgs__msg__Telemetry__FIELD_NAME__x, 1, 1},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_FLOAT,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {custom_msgs__msg__Telemetry__FIELD_NAME__y, 1, 1},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_FLOAT,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {custom_msgs__msg__Telemetry__FIELD_NAME__z, 1, 1},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_FLOAT,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {custom_msgs__msg__Telemetry__FIELD_NAME__roll, 4, 4},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_FLOAT,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {custom_msgs__msg__Telemetry__FIELD_NAME__pitch, 5, 5},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_FLOAT,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {custom_msgs__msg__Telemetry__FIELD_NAME__yaw, 3, 3},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_FLOAT,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
};

const rosidl_runtime_c__type_description__TypeDescription *
custom_msgs__msg__Telemetry__get_type_description(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {custom_msgs__msg__Telemetry__TYPE_NAME, 25, 25},
      {custom_msgs__msg__Telemetry__FIELDS, 6, 6},
    },
    {NULL, 0, 0},
  };
  if (!constructed) {
    constructed = true;
  }
  return &description;
}

static char toplevel_type_raw_source[] =
  "float32 x\n"
  "float32 y\n"
  "float32 z\n"
  "float32 roll\n"
  "float32 pitch\n"
  "float32 yaw";

static char msg_encoding[] = "msg";

// Define all individual source functions

const rosidl_runtime_c__type_description__TypeSource *
custom_msgs__msg__Telemetry__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {custom_msgs__msg__Telemetry__TYPE_NAME, 25, 25},
    {msg_encoding, 3, 3},
    {toplevel_type_raw_source, 69, 69},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
custom_msgs__msg__Telemetry__get_type_description_sources(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[1];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 1, 1};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *custom_msgs__msg__Telemetry__get_individual_type_description_source(NULL),
    constructed = true;
  }
  return &source_sequence;
}
