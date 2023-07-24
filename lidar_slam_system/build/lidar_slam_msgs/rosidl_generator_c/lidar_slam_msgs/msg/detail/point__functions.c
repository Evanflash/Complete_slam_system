// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from lidar_slam_msgs:msg/Point.idl
// generated code does not contain a copyright notice
#include "lidar_slam_msgs/msg/detail/point__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


bool
lidar_slam_msgs__msg__Point__init(lidar_slam_msgs__msg__Point * msg)
{
  if (!msg) {
    return false;
  }
  // x
  // y
  // z
  // i
  return true;
}

void
lidar_slam_msgs__msg__Point__fini(lidar_slam_msgs__msg__Point * msg)
{
  if (!msg) {
    return;
  }
  // x
  // y
  // z
  // i
}

bool
lidar_slam_msgs__msg__Point__are_equal(const lidar_slam_msgs__msg__Point * lhs, const lidar_slam_msgs__msg__Point * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // x
  if (lhs->x != rhs->x) {
    return false;
  }
  // y
  if (lhs->y != rhs->y) {
    return false;
  }
  // z
  if (lhs->z != rhs->z) {
    return false;
  }
  // i
  if (lhs->i != rhs->i) {
    return false;
  }
  return true;
}

bool
lidar_slam_msgs__msg__Point__copy(
  const lidar_slam_msgs__msg__Point * input,
  lidar_slam_msgs__msg__Point * output)
{
  if (!input || !output) {
    return false;
  }
  // x
  output->x = input->x;
  // y
  output->y = input->y;
  // z
  output->z = input->z;
  // i
  output->i = input->i;
  return true;
}

lidar_slam_msgs__msg__Point *
lidar_slam_msgs__msg__Point__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  lidar_slam_msgs__msg__Point * msg = (lidar_slam_msgs__msg__Point *)allocator.allocate(sizeof(lidar_slam_msgs__msg__Point), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(lidar_slam_msgs__msg__Point));
  bool success = lidar_slam_msgs__msg__Point__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
lidar_slam_msgs__msg__Point__destroy(lidar_slam_msgs__msg__Point * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    lidar_slam_msgs__msg__Point__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
lidar_slam_msgs__msg__Point__Sequence__init(lidar_slam_msgs__msg__Point__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  lidar_slam_msgs__msg__Point * data = NULL;

  if (size) {
    data = (lidar_slam_msgs__msg__Point *)allocator.zero_allocate(size, sizeof(lidar_slam_msgs__msg__Point), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = lidar_slam_msgs__msg__Point__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        lidar_slam_msgs__msg__Point__fini(&data[i - 1]);
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
lidar_slam_msgs__msg__Point__Sequence__fini(lidar_slam_msgs__msg__Point__Sequence * array)
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
      lidar_slam_msgs__msg__Point__fini(&array->data[i]);
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

lidar_slam_msgs__msg__Point__Sequence *
lidar_slam_msgs__msg__Point__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  lidar_slam_msgs__msg__Point__Sequence * array = (lidar_slam_msgs__msg__Point__Sequence *)allocator.allocate(sizeof(lidar_slam_msgs__msg__Point__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = lidar_slam_msgs__msg__Point__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
lidar_slam_msgs__msg__Point__Sequence__destroy(lidar_slam_msgs__msg__Point__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    lidar_slam_msgs__msg__Point__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
lidar_slam_msgs__msg__Point__Sequence__are_equal(const lidar_slam_msgs__msg__Point__Sequence * lhs, const lidar_slam_msgs__msg__Point__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!lidar_slam_msgs__msg__Point__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
lidar_slam_msgs__msg__Point__Sequence__copy(
  const lidar_slam_msgs__msg__Point__Sequence * input,
  lidar_slam_msgs__msg__Point__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(lidar_slam_msgs__msg__Point);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    lidar_slam_msgs__msg__Point * data =
      (lidar_slam_msgs__msg__Point *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!lidar_slam_msgs__msg__Point__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          lidar_slam_msgs__msg__Point__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!lidar_slam_msgs__msg__Point__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
