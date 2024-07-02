// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from my_turtle_interfaces:msg/TurtleInfo.idl
// generated code does not contain a copyright notice
#include "my_turtle_interfaces/msg/detail/turtle_info__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `name`
#include "rosidl_runtime_c/string_functions.h"

bool
my_turtle_interfaces__msg__TurtleInfo__init(my_turtle_interfaces__msg__TurtleInfo * msg)
{
  if (!msg) {
    return false;
  }
  // x
  // y
  // name
  if (!rosidl_runtime_c__String__init(&msg->name)) {
    my_turtle_interfaces__msg__TurtleInfo__fini(msg);
    return false;
  }
  return true;
}

void
my_turtle_interfaces__msg__TurtleInfo__fini(my_turtle_interfaces__msg__TurtleInfo * msg)
{
  if (!msg) {
    return;
  }
  // x
  // y
  // name
  rosidl_runtime_c__String__fini(&msg->name);
}

bool
my_turtle_interfaces__msg__TurtleInfo__are_equal(const my_turtle_interfaces__msg__TurtleInfo * lhs, const my_turtle_interfaces__msg__TurtleInfo * rhs)
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
  // name
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->name), &(rhs->name)))
  {
    return false;
  }
  return true;
}

bool
my_turtle_interfaces__msg__TurtleInfo__copy(
  const my_turtle_interfaces__msg__TurtleInfo * input,
  my_turtle_interfaces__msg__TurtleInfo * output)
{
  if (!input || !output) {
    return false;
  }
  // x
  output->x = input->x;
  // y
  output->y = input->y;
  // name
  if (!rosidl_runtime_c__String__copy(
      &(input->name), &(output->name)))
  {
    return false;
  }
  return true;
}

my_turtle_interfaces__msg__TurtleInfo *
my_turtle_interfaces__msg__TurtleInfo__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  my_turtle_interfaces__msg__TurtleInfo * msg = (my_turtle_interfaces__msg__TurtleInfo *)allocator.allocate(sizeof(my_turtle_interfaces__msg__TurtleInfo), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(my_turtle_interfaces__msg__TurtleInfo));
  bool success = my_turtle_interfaces__msg__TurtleInfo__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
my_turtle_interfaces__msg__TurtleInfo__destroy(my_turtle_interfaces__msg__TurtleInfo * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    my_turtle_interfaces__msg__TurtleInfo__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
my_turtle_interfaces__msg__TurtleInfo__Sequence__init(my_turtle_interfaces__msg__TurtleInfo__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  my_turtle_interfaces__msg__TurtleInfo * data = NULL;

  if (size) {
    data = (my_turtle_interfaces__msg__TurtleInfo *)allocator.zero_allocate(size, sizeof(my_turtle_interfaces__msg__TurtleInfo), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = my_turtle_interfaces__msg__TurtleInfo__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        my_turtle_interfaces__msg__TurtleInfo__fini(&data[i - 1]);
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
my_turtle_interfaces__msg__TurtleInfo__Sequence__fini(my_turtle_interfaces__msg__TurtleInfo__Sequence * array)
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
      my_turtle_interfaces__msg__TurtleInfo__fini(&array->data[i]);
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

my_turtle_interfaces__msg__TurtleInfo__Sequence *
my_turtle_interfaces__msg__TurtleInfo__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  my_turtle_interfaces__msg__TurtleInfo__Sequence * array = (my_turtle_interfaces__msg__TurtleInfo__Sequence *)allocator.allocate(sizeof(my_turtle_interfaces__msg__TurtleInfo__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = my_turtle_interfaces__msg__TurtleInfo__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
my_turtle_interfaces__msg__TurtleInfo__Sequence__destroy(my_turtle_interfaces__msg__TurtleInfo__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    my_turtle_interfaces__msg__TurtleInfo__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
my_turtle_interfaces__msg__TurtleInfo__Sequence__are_equal(const my_turtle_interfaces__msg__TurtleInfo__Sequence * lhs, const my_turtle_interfaces__msg__TurtleInfo__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!my_turtle_interfaces__msg__TurtleInfo__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
my_turtle_interfaces__msg__TurtleInfo__Sequence__copy(
  const my_turtle_interfaces__msg__TurtleInfo__Sequence * input,
  my_turtle_interfaces__msg__TurtleInfo__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(my_turtle_interfaces__msg__TurtleInfo);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    my_turtle_interfaces__msg__TurtleInfo * data =
      (my_turtle_interfaces__msg__TurtleInfo *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!my_turtle_interfaces__msg__TurtleInfo__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          my_turtle_interfaces__msg__TurtleInfo__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!my_turtle_interfaces__msg__TurtleInfo__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
