// generated from rosidl_generator_c/resource/idl__description.c.em
// with input from custom_msgs:msg/Commands.idl
// generated code does not contain a copyright notice

#include "custom_msgs/msg/detail/commands__functions.h"

ROSIDL_GENERATOR_C_PUBLIC_custom_msgs
const rosidl_type_hash_t *
custom_msgs__msg__Commands__get_type_hash(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0x2f, 0x2b, 0x83, 0xb0, 0xc0, 0x57, 0xc1, 0xc1,
      0x0b, 0xd8, 0x6c, 0xc3, 0xc1, 0xa1, 0x63, 0xc3,
      0x62, 0xea, 0xc0, 0xd3, 0x52, 0xfe, 0x7e, 0xcf,
      0x2f, 0x88, 0xb4, 0xa0, 0xea, 0xd7, 0xd7, 0xef,
    }};
  return &hash;
}

#include <assert.h>
#include <string.h>

// Include directives for referenced types

// Hashes for external referenced types
#ifndef NDEBUG
#endif

static char custom_msgs__msg__Commands__TYPE_NAME[] = "custom_msgs/msg/Commands";

// Define type names, field names, and default values
static char custom_msgs__msg__Commands__FIELD_NAME__mode[] = "mode";
static char custom_msgs__msg__Commands__FIELD_NAME__arm[] = "arm";
static char custom_msgs__msg__Commands__FIELD_NAME__pitch[] = "pitch";
static char custom_msgs__msg__Commands__FIELD_NAME__roll[] = "roll";
static char custom_msgs__msg__Commands__FIELD_NAME__thrust[] = "thrust";
static char custom_msgs__msg__Commands__FIELD_NAME__yaw[] = "yaw";
static char custom_msgs__msg__Commands__FIELD_NAME__forward[] = "forward";
static char custom_msgs__msg__Commands__FIELD_NAME__lateral[] = "lateral";

static rosidl_runtime_c__type_description__Field custom_msgs__msg__Commands__FIELDS[] = {
  {
    {custom_msgs__msg__Commands__FIELD_NAME__mode, 4, 4},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_STRING,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {custom_msgs__msg__Commands__FIELD_NAME__arm, 3, 3},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_INT32,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {custom_msgs__msg__Commands__FIELD_NAME__pitch, 5, 5},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_INT32,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {custom_msgs__msg__Commands__FIELD_NAME__roll, 4, 4},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_INT32,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {custom_msgs__msg__Commands__FIELD_NAME__thrust, 6, 6},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_INT32,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {custom_msgs__msg__Commands__FIELD_NAME__yaw, 3, 3},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_INT32,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {custom_msgs__msg__Commands__FIELD_NAME__forward, 7, 7},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_INT32,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {custom_msgs__msg__Commands__FIELD_NAME__lateral, 7, 7},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_INT32,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
};

const rosidl_runtime_c__type_description__TypeDescription *
custom_msgs__msg__Commands__get_type_description(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {custom_msgs__msg__Commands__TYPE_NAME, 24, 24},
      {custom_msgs__msg__Commands__FIELDS, 8, 8},
    },
    {NULL, 0, 0},
  };
  if (!constructed) {
    constructed = true;
  }
  return &description;
}

static char toplevel_type_raw_source[] =
  "string mode\n"
  "int32 arm\n"
  "\n"
  "int32 pitch\n"
  "int32 roll\n"
  "int32 thrust\n"
  "int32 yaw\n"
  "int32 forward\n"
  "int32 lateral\n"
  "";

static char msg_encoding[] = "msg";

// Define all individual source functions

const rosidl_runtime_c__type_description__TypeSource *
custom_msgs__msg__Commands__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {custom_msgs__msg__Commands__TYPE_NAME, 24, 24},
    {msg_encoding, 3, 3},
    {toplevel_type_raw_source, 98, 98},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
custom_msgs__msg__Commands__get_type_description_sources(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[1];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 1, 1};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *custom_msgs__msg__Commands__get_individual_type_description_source(NULL),
    constructed = true;
  }
  return &source_sequence;
}
