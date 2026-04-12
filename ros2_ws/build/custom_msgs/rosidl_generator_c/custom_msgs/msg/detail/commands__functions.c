// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from custom_msgs:msg/Commands.idl
// generated code does not contain a copyright notice
#include "custom_msgs/msg/detail/commands__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `mode`
#include "rosidl_runtime_c/string_functions.h"

bool
custom_msgs__msg__Commands__init(custom_msgs__msg__Commands * msg)
{
  if (!msg) {
    return false;
  }
  // mode
  if (!rosidl_runtime_c__String__init(&msg->mode)) {
    custom_msgs__msg__Commands__fini(msg);
    return false;
  }
  // arm
  // pitch
  // roll
  // thrust
  // yaw
  // forward
  // lateral
  return true;
}

void
custom_msgs__msg__Commands__fini(custom_msgs__msg__Commands * msg)
{
  if (!msg) {
    return;
  }
  // mode
  rosidl_runtime_c__String__fini(&msg->mode);
  // arm
  // pitch
  // roll
  // thrust
  // yaw
  // forward
  // lateral
}

bool
custom_msgs__msg__Commands__are_equal(const custom_msgs__msg__Commands * lhs, const custom_msgs__msg__Commands * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // mode
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->mode), &(rhs->mode)))
  {
    return false;
  }
  // arm
  if (lhs->arm != rhs->arm) {
    return false;
  }
  // pitch
  if (lhs->pitch != rhs->pitch) {
    return false;
  }
  // roll
  if (lhs->roll != rhs->roll) {
    return false;
  }
  // thrust
  if (lhs->thrust != rhs->thrust) {
    return false;
  }
  // yaw
  if (lhs->yaw != rhs->yaw) {
    return false;
  }
  // forward
  if (lhs->forward != rhs->forward) {
    return false;
  }
  // lateral
  if (lhs->lateral != rhs->lateral) {
    return false;
  }
  return true;
}

bool
custom_msgs__msg__Commands__copy(
  const custom_msgs__msg__Commands * input,
  custom_msgs__msg__Commands * output)
{
  if (!input || !output) {
    return false;
  }
  // mode
  if (!rosidl_runtime_c__String__copy(
      &(input->mode), &(output->mode)))
  {
    return false;
  }
  // arm
  output->arm = input->arm;
  // pitch
  output->pitch = input->pitch;
  // roll
  output->roll = input->roll;
  // thrust
  output->thrust = input->thrust;
  // yaw
  output->yaw = input->yaw;
  // forward
  output->forward = input->forward;
  // lateral
  output->lateral = input->lateral;
  return true;
}

custom_msgs__msg__Commands *
custom_msgs__msg__Commands__create(void)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  custom_msgs__msg__Commands * msg = (custom_msgs__msg__Commands *)allocator.allocate(sizeof(custom_msgs__msg__Commands), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(custom_msgs__msg__Commands));
  bool success = custom_msgs__msg__Commands__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
custom_msgs__msg__Commands__destroy(custom_msgs__msg__Commands * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    custom_msgs__msg__Commands__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
custom_msgs__msg__Commands__Sequence__init(custom_msgs__msg__Commands__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  custom_msgs__msg__Commands * data = NULL;

  if (size) {
    data = (custom_msgs__msg__Commands *)allocator.zero_allocate(size, sizeof(custom_msgs__msg__Commands), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = custom_msgs__msg__Commands__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        custom_msgs__msg__Commands__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
custom_msgs__msg__Commands__Sequence__fini(custom_msgs__msg__Commands__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      custom_msgs__msg__Commands__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

custom_msgs__msg__Commands__Sequence *
custom_msgs__msg__Commands__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  custom_msgs__msg__Commands__Sequence * array = (custom_msgs__msg__Commands__Sequence *)allocator.allocate(sizeof(custom_msgs__msg__Commands__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = custom_msgs__msg__Commands__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
custom_msgs__msg__Commands__Sequence__destroy(custom_msgs__msg__Commands__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    custom_msgs__msg__Commands__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
custom_msgs__msg__Commands__Sequence__are_equal(const custom_msgs__msg__Commands__Sequence * lhs, const custom_msgs__msg__Commands__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!custom_msgs__msg__Commands__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
custom_msgs__msg__Commands__Sequence__copy(
  const custom_msgs__msg__Commands__Sequence * input,
  custom_msgs__msg__Commands__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(custom_msgs__msg__Commands);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    custom_msgs__msg__Commands * data =
      (custom_msgs__msg__Commands *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!custom_msgs__msg__Commands__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          custom_msgs__msg__Commands__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!custom_msgs__msg__Commands__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
