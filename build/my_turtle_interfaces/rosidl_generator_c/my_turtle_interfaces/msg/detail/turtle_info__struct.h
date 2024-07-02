// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from my_turtle_interfaces:msg/TurtleInfo.idl
// generated code does not contain a copyright notice

#ifndef MY_TURTLE_INTERFACES__MSG__DETAIL__TURTLE_INFO__STRUCT_H_
#define MY_TURTLE_INTERFACES__MSG__DETAIL__TURTLE_INFO__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'name'
#include "rosidl_runtime_c/string.h"

/// Struct defined in msg/TurtleInfo in the package my_turtle_interfaces.
typedef struct my_turtle_interfaces__msg__TurtleInfo
{
  double x;
  double y;
  rosidl_runtime_c__String name;
} my_turtle_interfaces__msg__TurtleInfo;

// Struct for a sequence of my_turtle_interfaces__msg__TurtleInfo.
typedef struct my_turtle_interfaces__msg__TurtleInfo__Sequence
{
  my_turtle_interfaces__msg__TurtleInfo * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} my_turtle_interfaces__msg__TurtleInfo__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // MY_TURTLE_INTERFACES__MSG__DETAIL__TURTLE_INFO__STRUCT_H_
