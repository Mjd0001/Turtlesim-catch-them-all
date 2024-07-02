// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from my_turtle_interfaces:msg/TurtleInfo.idl
// generated code does not contain a copyright notice

#ifndef MY_TURTLE_INTERFACES__MSG__DETAIL__TURTLE_INFO__TRAITS_HPP_
#define MY_TURTLE_INTERFACES__MSG__DETAIL__TURTLE_INFO__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "my_turtle_interfaces/msg/detail/turtle_info__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace my_turtle_interfaces
{

namespace msg
{

inline void to_flow_style_yaml(
  const TurtleInfo & msg,
  std::ostream & out)
{
  out << "{";
  // member: x
  {
    out << "x: ";
    rosidl_generator_traits::value_to_yaml(msg.x, out);
    out << ", ";
  }

  // member: y
  {
    out << "y: ";
    rosidl_generator_traits::value_to_yaml(msg.y, out);
    out << ", ";
  }

  // member: name
  {
    out << "name: ";
    rosidl_generator_traits::value_to_yaml(msg.name, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const TurtleInfo & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: x
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "x: ";
    rosidl_generator_traits::value_to_yaml(msg.x, out);
    out << "\n";
  }

  // member: y
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "y: ";
    rosidl_generator_traits::value_to_yaml(msg.y, out);
    out << "\n";
  }

  // member: name
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "name: ";
    rosidl_generator_traits::value_to_yaml(msg.name, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const TurtleInfo & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace msg

}  // namespace my_turtle_interfaces

namespace rosidl_generator_traits
{

[[deprecated("use my_turtle_interfaces::msg::to_block_style_yaml() instead")]]
inline void to_yaml(
  const my_turtle_interfaces::msg::TurtleInfo & msg,
  std::ostream & out, size_t indentation = 0)
{
  my_turtle_interfaces::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use my_turtle_interfaces::msg::to_yaml() instead")]]
inline std::string to_yaml(const my_turtle_interfaces::msg::TurtleInfo & msg)
{
  return my_turtle_interfaces::msg::to_yaml(msg);
}

template<>
inline const char * data_type<my_turtle_interfaces::msg::TurtleInfo>()
{
  return "my_turtle_interfaces::msg::TurtleInfo";
}

template<>
inline const char * name<my_turtle_interfaces::msg::TurtleInfo>()
{
  return "my_turtle_interfaces/msg/TurtleInfo";
}

template<>
struct has_fixed_size<my_turtle_interfaces::msg::TurtleInfo>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<my_turtle_interfaces::msg::TurtleInfo>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<my_turtle_interfaces::msg::TurtleInfo>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // MY_TURTLE_INTERFACES__MSG__DETAIL__TURTLE_INFO__TRAITS_HPP_
