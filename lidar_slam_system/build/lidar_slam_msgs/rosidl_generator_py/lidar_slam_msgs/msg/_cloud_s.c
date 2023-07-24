// generated from rosidl_generator_py/resource/_idl_support.c.em
// with input from lidar_slam_msgs:msg/Cloud.idl
// generated code does not contain a copyright notice
#define NPY_NO_DEPRECATED_API NPY_1_7_API_VERSION
#include <Python.h>
#include <stdbool.h>
#ifndef _WIN32
# pragma GCC diagnostic push
# pragma GCC diagnostic ignored "-Wunused-function"
#endif
#include "numpy/ndarrayobject.h"
#ifndef _WIN32
# pragma GCC diagnostic pop
#endif
#include "rosidl_runtime_c/visibility_control.h"
#include "lidar_slam_msgs/msg/detail/cloud__struct.h"
#include "lidar_slam_msgs/msg/detail/cloud__functions.h"

#include "rosidl_runtime_c/primitives_sequence.h"
#include "rosidl_runtime_c/primitives_sequence_functions.h"

// Nested array functions includes
#include "lidar_slam_msgs/msg/detail/point__functions.h"
// end nested array functions include
ROSIDL_GENERATOR_C_IMPORT
bool std_msgs__msg__header__convert_from_py(PyObject * _pymsg, void * _ros_message);
ROSIDL_GENERATOR_C_IMPORT
PyObject * std_msgs__msg__header__convert_to_py(void * raw_ros_message);
bool lidar_slam_msgs__msg__point__convert_from_py(PyObject * _pymsg, void * _ros_message);
PyObject * lidar_slam_msgs__msg__point__convert_to_py(void * raw_ros_message);
bool lidar_slam_msgs__msg__point__convert_from_py(PyObject * _pymsg, void * _ros_message);
PyObject * lidar_slam_msgs__msg__point__convert_to_py(void * raw_ros_message);
bool lidar_slam_msgs__msg__point__convert_from_py(PyObject * _pymsg, void * _ros_message);
PyObject * lidar_slam_msgs__msg__point__convert_to_py(void * raw_ros_message);
bool lidar_slam_msgs__msg__point__convert_from_py(PyObject * _pymsg, void * _ros_message);
PyObject * lidar_slam_msgs__msg__point__convert_to_py(void * raw_ros_message);
bool lidar_slam_msgs__msg__point__convert_from_py(PyObject * _pymsg, void * _ros_message);
PyObject * lidar_slam_msgs__msg__point__convert_to_py(void * raw_ros_message);
bool lidar_slam_msgs__msg__point__convert_from_py(PyObject * _pymsg, void * _ros_message);
PyObject * lidar_slam_msgs__msg__point__convert_to_py(void * raw_ros_message);

ROSIDL_GENERATOR_C_EXPORT
bool lidar_slam_msgs__msg__cloud__convert_from_py(PyObject * _pymsg, void * _ros_message)
{
  // check that the passed message is of the expected Python class
  {
    char full_classname_dest[33];
    {
      char * class_name = NULL;
      char * module_name = NULL;
      {
        PyObject * class_attr = PyObject_GetAttrString(_pymsg, "__class__");
        if (class_attr) {
          PyObject * name_attr = PyObject_GetAttrString(class_attr, "__name__");
          if (name_attr) {
            class_name = (char *)PyUnicode_1BYTE_DATA(name_attr);
            Py_DECREF(name_attr);
          }
          PyObject * module_attr = PyObject_GetAttrString(class_attr, "__module__");
          if (module_attr) {
            module_name = (char *)PyUnicode_1BYTE_DATA(module_attr);
            Py_DECREF(module_attr);
          }
          Py_DECREF(class_attr);
        }
      }
      if (!class_name || !module_name) {
        return false;
      }
      snprintf(full_classname_dest, sizeof(full_classname_dest), "%s.%s", module_name, class_name);
    }
    assert(strncmp("lidar_slam_msgs.msg._cloud.Cloud", full_classname_dest, 32) == 0);
  }
  lidar_slam_msgs__msg__Cloud * ros_message = _ros_message;
  {  // header
    PyObject * field = PyObject_GetAttrString(_pymsg, "header");
    if (!field) {
      return false;
    }
    if (!std_msgs__msg__header__convert_from_py(field, &ros_message->header)) {
      Py_DECREF(field);
      return false;
    }
    Py_DECREF(field);
  }
  {  // corner_sharp
    PyObject * field = PyObject_GetAttrString(_pymsg, "corner_sharp");
    if (!field) {
      return false;
    }
    PyObject * seq_field = PySequence_Fast(field, "expected a sequence in 'corner_sharp'");
    if (!seq_field) {
      Py_DECREF(field);
      return false;
    }
    Py_ssize_t size = PySequence_Size(field);
    if (-1 == size) {
      Py_DECREF(seq_field);
      Py_DECREF(field);
      return false;
    }
    if (!lidar_slam_msgs__msg__Point__Sequence__init(&(ros_message->corner_sharp), size)) {
      PyErr_SetString(PyExc_RuntimeError, "unable to create lidar_slam_msgs__msg__Point__Sequence ros_message");
      Py_DECREF(seq_field);
      Py_DECREF(field);
      return false;
    }
    lidar_slam_msgs__msg__Point * dest = ros_message->corner_sharp.data;
    for (Py_ssize_t i = 0; i < size; ++i) {
      if (!lidar_slam_msgs__msg__point__convert_from_py(PySequence_Fast_GET_ITEM(seq_field, i), &dest[i])) {
        Py_DECREF(seq_field);
        Py_DECREF(field);
        return false;
      }
    }
    Py_DECREF(seq_field);
    Py_DECREF(field);
  }
  {  // corner_less_sharp
    PyObject * field = PyObject_GetAttrString(_pymsg, "corner_less_sharp");
    if (!field) {
      return false;
    }
    PyObject * seq_field = PySequence_Fast(field, "expected a sequence in 'corner_less_sharp'");
    if (!seq_field) {
      Py_DECREF(field);
      return false;
    }
    Py_ssize_t size = PySequence_Size(field);
    if (-1 == size) {
      Py_DECREF(seq_field);
      Py_DECREF(field);
      return false;
    }
    if (!lidar_slam_msgs__msg__Point__Sequence__init(&(ros_message->corner_less_sharp), size)) {
      PyErr_SetString(PyExc_RuntimeError, "unable to create lidar_slam_msgs__msg__Point__Sequence ros_message");
      Py_DECREF(seq_field);
      Py_DECREF(field);
      return false;
    }
    lidar_slam_msgs__msg__Point * dest = ros_message->corner_less_sharp.data;
    for (Py_ssize_t i = 0; i < size; ++i) {
      if (!lidar_slam_msgs__msg__point__convert_from_py(PySequence_Fast_GET_ITEM(seq_field, i), &dest[i])) {
        Py_DECREF(seq_field);
        Py_DECREF(field);
        return false;
      }
    }
    Py_DECREF(seq_field);
    Py_DECREF(field);
  }
  {  // surf_flat
    PyObject * field = PyObject_GetAttrString(_pymsg, "surf_flat");
    if (!field) {
      return false;
    }
    PyObject * seq_field = PySequence_Fast(field, "expected a sequence in 'surf_flat'");
    if (!seq_field) {
      Py_DECREF(field);
      return false;
    }
    Py_ssize_t size = PySequence_Size(field);
    if (-1 == size) {
      Py_DECREF(seq_field);
      Py_DECREF(field);
      return false;
    }
    if (!lidar_slam_msgs__msg__Point__Sequence__init(&(ros_message->surf_flat), size)) {
      PyErr_SetString(PyExc_RuntimeError, "unable to create lidar_slam_msgs__msg__Point__Sequence ros_message");
      Py_DECREF(seq_field);
      Py_DECREF(field);
      return false;
    }
    lidar_slam_msgs__msg__Point * dest = ros_message->surf_flat.data;
    for (Py_ssize_t i = 0; i < size; ++i) {
      if (!lidar_slam_msgs__msg__point__convert_from_py(PySequence_Fast_GET_ITEM(seq_field, i), &dest[i])) {
        Py_DECREF(seq_field);
        Py_DECREF(field);
        return false;
      }
    }
    Py_DECREF(seq_field);
    Py_DECREF(field);
  }
  {  // surf_less_flat
    PyObject * field = PyObject_GetAttrString(_pymsg, "surf_less_flat");
    if (!field) {
      return false;
    }
    PyObject * seq_field = PySequence_Fast(field, "expected a sequence in 'surf_less_flat'");
    if (!seq_field) {
      Py_DECREF(field);
      return false;
    }
    Py_ssize_t size = PySequence_Size(field);
    if (-1 == size) {
      Py_DECREF(seq_field);
      Py_DECREF(field);
      return false;
    }
    if (!lidar_slam_msgs__msg__Point__Sequence__init(&(ros_message->surf_less_flat), size)) {
      PyErr_SetString(PyExc_RuntimeError, "unable to create lidar_slam_msgs__msg__Point__Sequence ros_message");
      Py_DECREF(seq_field);
      Py_DECREF(field);
      return false;
    }
    lidar_slam_msgs__msg__Point * dest = ros_message->surf_less_flat.data;
    for (Py_ssize_t i = 0; i < size; ++i) {
      if (!lidar_slam_msgs__msg__point__convert_from_py(PySequence_Fast_GET_ITEM(seq_field, i), &dest[i])) {
        Py_DECREF(seq_field);
        Py_DECREF(field);
        return false;
      }
    }
    Py_DECREF(seq_field);
    Py_DECREF(field);
  }
  {  // segment_cloud
    PyObject * field = PyObject_GetAttrString(_pymsg, "segment_cloud");
    if (!field) {
      return false;
    }
    PyObject * seq_field = PySequence_Fast(field, "expected a sequence in 'segment_cloud'");
    if (!seq_field) {
      Py_DECREF(field);
      return false;
    }
    Py_ssize_t size = PySequence_Size(field);
    if (-1 == size) {
      Py_DECREF(seq_field);
      Py_DECREF(field);
      return false;
    }
    if (!lidar_slam_msgs__msg__Point__Sequence__init(&(ros_message->segment_cloud), size)) {
      PyErr_SetString(PyExc_RuntimeError, "unable to create lidar_slam_msgs__msg__Point__Sequence ros_message");
      Py_DECREF(seq_field);
      Py_DECREF(field);
      return false;
    }
    lidar_slam_msgs__msg__Point * dest = ros_message->segment_cloud.data;
    for (Py_ssize_t i = 0; i < size; ++i) {
      if (!lidar_slam_msgs__msg__point__convert_from_py(PySequence_Fast_GET_ITEM(seq_field, i), &dest[i])) {
        Py_DECREF(seq_field);
        Py_DECREF(field);
        return false;
      }
    }
    Py_DECREF(seq_field);
    Py_DECREF(field);
  }
  {  // ground_cloud
    PyObject * field = PyObject_GetAttrString(_pymsg, "ground_cloud");
    if (!field) {
      return false;
    }
    PyObject * seq_field = PySequence_Fast(field, "expected a sequence in 'ground_cloud'");
    if (!seq_field) {
      Py_DECREF(field);
      return false;
    }
    Py_ssize_t size = PySequence_Size(field);
    if (-1 == size) {
      Py_DECREF(seq_field);
      Py_DECREF(field);
      return false;
    }
    if (!lidar_slam_msgs__msg__Point__Sequence__init(&(ros_message->ground_cloud), size)) {
      PyErr_SetString(PyExc_RuntimeError, "unable to create lidar_slam_msgs__msg__Point__Sequence ros_message");
      Py_DECREF(seq_field);
      Py_DECREF(field);
      return false;
    }
    lidar_slam_msgs__msg__Point * dest = ros_message->ground_cloud.data;
    for (Py_ssize_t i = 0; i < size; ++i) {
      if (!lidar_slam_msgs__msg__point__convert_from_py(PySequence_Fast_GET_ITEM(seq_field, i), &dest[i])) {
        Py_DECREF(seq_field);
        Py_DECREF(field);
        return false;
      }
    }
    Py_DECREF(seq_field);
    Py_DECREF(field);
  }

  return true;
}

ROSIDL_GENERATOR_C_EXPORT
PyObject * lidar_slam_msgs__msg__cloud__convert_to_py(void * raw_ros_message)
{
  /* NOTE(esteve): Call constructor of Cloud */
  PyObject * _pymessage = NULL;
  {
    PyObject * pymessage_module = PyImport_ImportModule("lidar_slam_msgs.msg._cloud");
    assert(pymessage_module);
    PyObject * pymessage_class = PyObject_GetAttrString(pymessage_module, "Cloud");
    assert(pymessage_class);
    Py_DECREF(pymessage_module);
    _pymessage = PyObject_CallObject(pymessage_class, NULL);
    Py_DECREF(pymessage_class);
    if (!_pymessage) {
      return NULL;
    }
  }
  lidar_slam_msgs__msg__Cloud * ros_message = (lidar_slam_msgs__msg__Cloud *)raw_ros_message;
  {  // header
    PyObject * field = NULL;
    field = std_msgs__msg__header__convert_to_py(&ros_message->header);
    if (!field) {
      return NULL;
    }
    {
      int rc = PyObject_SetAttrString(_pymessage, "header", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // corner_sharp
    PyObject * field = NULL;
    size_t size = ros_message->corner_sharp.size;
    field = PyList_New(size);
    if (!field) {
      return NULL;
    }
    lidar_slam_msgs__msg__Point * item;
    for (size_t i = 0; i < size; ++i) {
      item = &(ros_message->corner_sharp.data[i]);
      PyObject * pyitem = lidar_slam_msgs__msg__point__convert_to_py(item);
      if (!pyitem) {
        Py_DECREF(field);
        return NULL;
      }
      int rc = PyList_SetItem(field, i, pyitem);
      (void)rc;
      assert(rc == 0);
    }
    assert(PySequence_Check(field));
    {
      int rc = PyObject_SetAttrString(_pymessage, "corner_sharp", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // corner_less_sharp
    PyObject * field = NULL;
    size_t size = ros_message->corner_less_sharp.size;
    field = PyList_New(size);
    if (!field) {
      return NULL;
    }
    lidar_slam_msgs__msg__Point * item;
    for (size_t i = 0; i < size; ++i) {
      item = &(ros_message->corner_less_sharp.data[i]);
      PyObject * pyitem = lidar_slam_msgs__msg__point__convert_to_py(item);
      if (!pyitem) {
        Py_DECREF(field);
        return NULL;
      }
      int rc = PyList_SetItem(field, i, pyitem);
      (void)rc;
      assert(rc == 0);
    }
    assert(PySequence_Check(field));
    {
      int rc = PyObject_SetAttrString(_pymessage, "corner_less_sharp", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // surf_flat
    PyObject * field = NULL;
    size_t size = ros_message->surf_flat.size;
    field = PyList_New(size);
    if (!field) {
      return NULL;
    }
    lidar_slam_msgs__msg__Point * item;
    for (size_t i = 0; i < size; ++i) {
      item = &(ros_message->surf_flat.data[i]);
      PyObject * pyitem = lidar_slam_msgs__msg__point__convert_to_py(item);
      if (!pyitem) {
        Py_DECREF(field);
        return NULL;
      }
      int rc = PyList_SetItem(field, i, pyitem);
      (void)rc;
      assert(rc == 0);
    }
    assert(PySequence_Check(field));
    {
      int rc = PyObject_SetAttrString(_pymessage, "surf_flat", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // surf_less_flat
    PyObject * field = NULL;
    size_t size = ros_message->surf_less_flat.size;
    field = PyList_New(size);
    if (!field) {
      return NULL;
    }
    lidar_slam_msgs__msg__Point * item;
    for (size_t i = 0; i < size; ++i) {
      item = &(ros_message->surf_less_flat.data[i]);
      PyObject * pyitem = lidar_slam_msgs__msg__point__convert_to_py(item);
      if (!pyitem) {
        Py_DECREF(field);
        return NULL;
      }
      int rc = PyList_SetItem(field, i, pyitem);
      (void)rc;
      assert(rc == 0);
    }
    assert(PySequence_Check(field));
    {
      int rc = PyObject_SetAttrString(_pymessage, "surf_less_flat", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // segment_cloud
    PyObject * field = NULL;
    size_t size = ros_message->segment_cloud.size;
    field = PyList_New(size);
    if (!field) {
      return NULL;
    }
    lidar_slam_msgs__msg__Point * item;
    for (size_t i = 0; i < size; ++i) {
      item = &(ros_message->segment_cloud.data[i]);
      PyObject * pyitem = lidar_slam_msgs__msg__point__convert_to_py(item);
      if (!pyitem) {
        Py_DECREF(field);
        return NULL;
      }
      int rc = PyList_SetItem(field, i, pyitem);
      (void)rc;
      assert(rc == 0);
    }
    assert(PySequence_Check(field));
    {
      int rc = PyObject_SetAttrString(_pymessage, "segment_cloud", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // ground_cloud
    PyObject * field = NULL;
    size_t size = ros_message->ground_cloud.size;
    field = PyList_New(size);
    if (!field) {
      return NULL;
    }
    lidar_slam_msgs__msg__Point * item;
    for (size_t i = 0; i < size; ++i) {
      item = &(ros_message->ground_cloud.data[i]);
      PyObject * pyitem = lidar_slam_msgs__msg__point__convert_to_py(item);
      if (!pyitem) {
        Py_DECREF(field);
        return NULL;
      }
      int rc = PyList_SetItem(field, i, pyitem);
      (void)rc;
      assert(rc == 0);
    }
    assert(PySequence_Check(field));
    {
      int rc = PyObject_SetAttrString(_pymessage, "ground_cloud", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }

  // ownership of _pymessage is transferred to the caller
  return _pymessage;
}
