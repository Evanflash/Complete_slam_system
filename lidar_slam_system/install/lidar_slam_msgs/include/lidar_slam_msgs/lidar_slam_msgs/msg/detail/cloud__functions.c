// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from lidar_slam_msgs:msg/Cloud.idl
// generated code does not contain a copyright notice
#include "lidar_slam_msgs/msg/detail/cloud__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `header`
#include "std_msgs/msg/detail/header__functions.h"
// Member `corner_sharp`
// Member `corner_less_sharp`
// Member `surf_flat`
// Member `surf_less_flat`
// Member `segment_cloud`
// Member `ground_cloud`
#include "lidar_slam_msgs/msg/detail/point__functions.h"

bool
lidar_slam_msgs__msg__Cloud__init(lidar_slam_msgs__msg__Cloud * msg)
{
  if (!msg) {
    return false;
  }
  // header
  if (!std_msgs__msg__Header__init(&msg->header)) {
    lidar_slam_msgs__msg__Cloud__fini(msg);
    return false;
  }
  // corner_sharp
  if (!lidar_slam_msgs__msg__Point__Sequence__init(&msg->corner_sharp, 0)) {
    lidar_slam_msgs__msg__Cloud__fini(msg);
    return false;
  }
  // corner_less_sharp
  if (!lidar_slam_msgs__msg__Point__Sequence__init(&msg->corner_less_sharp, 0)) {
    lidar_slam_msgs__msg__Cloud__fini(msg);
    return false;
  }
  // surf_flat
  if (!lidar_slam_msgs__msg__Point__Sequence__init(&msg->surf_flat, 0)) {
    lidar_slam_msgs__msg__Cloud__fini(msg);
    return false;
  }
  // surf_less_flat
  if (!lidar_slam_msgs__msg__Point__Sequence__init(&msg->surf_less_flat, 0)) {
    lidar_slam_msgs__msg__Cloud__fini(msg);
    return false;
  }
  // segment_cloud
  if (!lidar_slam_msgs__msg__Point__Sequence__init(&msg->segment_cloud, 0)) {
    lidar_slam_msgs__msg__Cloud__fini(msg);
    return false;
  }
  // ground_cloud
  if (!lidar_slam_msgs__msg__Point__Sequence__init(&msg->ground_cloud, 0)) {
    lidar_slam_msgs__msg__Cloud__fini(msg);
    return false;
  }
  return true;
}

void
lidar_slam_msgs__msg__Cloud__fini(lidar_slam_msgs__msg__Cloud * msg)
{
  if (!msg) {
    return;
  }
  // header
  std_msgs__msg__Header__fini(&msg->header);
  // corner_sharp
  lidar_slam_msgs__msg__Point__Sequence__fini(&msg->corner_sharp);
  // corner_less_sharp
  lidar_slam_msgs__msg__Point__Sequence__fini(&msg->corner_less_sharp);
  // surf_flat
  lidar_slam_msgs__msg__Point__Sequence__fini(&msg->surf_flat);
  // surf_less_flat
  lidar_slam_msgs__msg__Point__Sequence__fini(&msg->surf_less_flat);
  // segment_cloud
  lidar_slam_msgs__msg__Point__Sequence__fini(&msg->segment_cloud);
  // ground_cloud
  lidar_slam_msgs__msg__Point__Sequence__fini(&msg->ground_cloud);
}

bool
lidar_slam_msgs__msg__Cloud__are_equal(const lidar_slam_msgs__msg__Cloud * lhs, const lidar_slam_msgs__msg__Cloud * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // header
  if (!std_msgs__msg__Header__are_equal(
      &(lhs->header), &(rhs->header)))
  {
    return false;
  }
  // corner_sharp
  if (!lidar_slam_msgs__msg__Point__Sequence__are_equal(
      &(lhs->corner_sharp), &(rhs->corner_sharp)))
  {
    return false;
  }
  // corner_less_sharp
  if (!lidar_slam_msgs__msg__Point__Sequence__are_equal(
      &(lhs->corner_less_sharp), &(rhs->corner_less_sharp)))
  {
    return false;
  }
  // surf_flat
  if (!lidar_slam_msgs__msg__Point__Sequence__are_equal(
      &(lhs->surf_flat), &(rhs->surf_flat)))
  {
    return false;
  }
  // surf_less_flat
  if (!lidar_slam_msgs__msg__Point__Sequence__are_equal(
      &(lhs->surf_less_flat), &(rhs->surf_less_flat)))
  {
    return false;
  }
  // segment_cloud
  if (!lidar_slam_msgs__msg__Point__Sequence__are_equal(
      &(lhs->segment_cloud), &(rhs->segment_cloud)))
  {
    return false;
  }
  // ground_cloud
  if (!lidar_slam_msgs__msg__Point__Sequence__are_equal(
      &(lhs->ground_cloud), &(rhs->ground_cloud)))
  {
    return false;
  }
  return true;
}

bool
lidar_slam_msgs__msg__Cloud__copy(
  const lidar_slam_msgs__msg__Cloud * input,
  lidar_slam_msgs__msg__Cloud * output)
{
  if (!input || !output) {
    return false;
  }
  // header
  if (!std_msgs__msg__Header__copy(
      &(input->header), &(output->header)))
  {
    return false;
  }
  // corner_sharp
  if (!lidar_slam_msgs__msg__Point__Sequence__copy(
      &(input->corner_sharp), &(output->corner_sharp)))
  {
    return false;
  }
  // corner_less_sharp
  if (!lidar_slam_msgs__msg__Point__Sequence__copy(
      &(input->corner_less_sharp), &(output->corner_less_sharp)))
  {
    return false;
  }
  // surf_flat
  if (!lidar_slam_msgs__msg__Point__Sequence__copy(
      &(input->surf_flat), &(output->surf_flat)))
  {
    return false;
  }
  // surf_less_flat
  if (!lidar_slam_msgs__msg__Point__Sequence__copy(
      &(input->surf_less_flat), &(output->surf_less_flat)))
  {
    return false;
  }
  // segment_cloud
  if (!lidar_slam_msgs__msg__Point__Sequence__copy(
      &(input->segment_cloud), &(output->segment_cloud)))
  {
    return false;
  }
  // ground_cloud
  if (!lidar_slam_msgs__msg__Point__Sequence__copy(
      &(input->ground_cloud), &(output->ground_cloud)))
  {
    return false;
  }
  return true;
}

lidar_slam_msgs__msg__Cloud *
lidar_slam_msgs__msg__Cloud__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  lidar_slam_msgs__msg__Cloud * msg = (lidar_slam_msgs__msg__Cloud *)allocator.allocate(sizeof(lidar_slam_msgs__msg__Cloud), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(lidar_slam_msgs__msg__Cloud));
  bool success = lidar_slam_msgs__msg__Cloud__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
lidar_slam_msgs__msg__Cloud__destroy(lidar_slam_msgs__msg__Cloud * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    lidar_slam_msgs__msg__Cloud__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
lidar_slam_msgs__msg__Cloud__Sequence__init(lidar_slam_msgs__msg__Cloud__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  lidar_slam_msgs__msg__Cloud * data = NULL;

  if (size) {
    data = (lidar_slam_msgs__msg__Cloud *)allocator.zero_allocate(size, sizeof(lidar_slam_msgs__msg__Cloud), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = lidar_slam_msgs__msg__Cloud__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        lidar_slam_msgs__msg__Cloud__fini(&data[i - 1]);
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
lidar_slam_msgs__msg__Cloud__Sequence__fini(lidar_slam_msgs__msg__Cloud__Sequence * array)
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
      lidar_slam_msgs__msg__Cloud__fini(&array->data[i]);
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

lidar_slam_msgs__msg__Cloud__Sequence *
lidar_slam_msgs__msg__Cloud__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  lidar_slam_msgs__msg__Cloud__Sequence * array = (lidar_slam_msgs__msg__Cloud__Sequence *)allocator.allocate(sizeof(lidar_slam_msgs__msg__Cloud__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = lidar_slam_msgs__msg__Cloud__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
lidar_slam_msgs__msg__Cloud__Sequence__destroy(lidar_slam_msgs__msg__Cloud__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    lidar_slam_msgs__msg__Cloud__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
lidar_slam_msgs__msg__Cloud__Sequence__are_equal(const lidar_slam_msgs__msg__Cloud__Sequence * lhs, const lidar_slam_msgs__msg__Cloud__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!lidar_slam_msgs__msg__Cloud__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
lidar_slam_msgs__msg__Cloud__Sequence__copy(
  const lidar_slam_msgs__msg__Cloud__Sequence * input,
  lidar_slam_msgs__msg__Cloud__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(lidar_slam_msgs__msg__Cloud);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    lidar_slam_msgs__msg__Cloud * data =
      (lidar_slam_msgs__msg__Cloud *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!lidar_slam_msgs__msg__Cloud__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          lidar_slam_msgs__msg__Cloud__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!lidar_slam_msgs__msg__Cloud__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
