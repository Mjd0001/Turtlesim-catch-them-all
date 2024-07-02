// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from my_turtle_interfaces:msg/TurtleInfo.idl
// generated code does not contain a copyright notice

#ifndef MY_TURTLE_INTERFACES__MSG__DETAIL__TURTLE_INFO__BUILDER_HPP_
#define MY_TURTLE_INTERFACES__MSG__DETAIL__TURTLE_INFO__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "my_turtle_interfaces/msg/detail/turtle_info__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace my_turtle_interfaces
{

namespace msg
{

namespace builder
{

class Init_TurtleInfo_name
{
public:
  explicit Init_TurtleInfo_name(::my_turtle_interfaces::msg::TurtleInfo & msg)
  : msg_(msg)
  {}
  ::my_turtle_interfaces::msg::TurtleInfo name(::my_turtle_interfaces::msg::TurtleInfo::_name_type arg)
  {
    msg_.name = std::move(arg);
    return std::move(msg_);
  }

private:
  ::my_turtle_interfaces::msg::TurtleInfo msg_;
};

class Init_TurtleInfo_y
{
public:
  explicit Init_TurtleInfo_y(::my_turtle_interfaces::msg::TurtleInfo & msg)
  : msg_(msg)
  {}
  Init_TurtleInfo_name y(::my_turtle_interfaces::msg::TurtleInfo::_y_type arg)
  {
    msg_.y = std::move(arg);
    return Init_TurtleInfo_name(msg_);
  }

private:
  ::my_turtle_interfaces::msg::TurtleInfo msg_;
};

class Init_TurtleInfo_x
{
public:
  Init_TurtleInfo_x()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_TurtleInfo_y x(::my_turtle_interfaces::msg::TurtleInfo::_x_type arg)
  {
    msg_.x = std::move(arg);
    return Init_TurtleInfo_y(msg_);
  }

private:
  ::my_turtle_interfaces::msg::TurtleInfo msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::my_turtle_interfaces::msg::TurtleInfo>()
{
  return my_turtle_interfaces::msg::builder::Init_TurtleInfo_x();
}

}  // namespace my_turtle_interfaces

#endif  // MY_TURTLE_INTERFACES__MSG__DETAIL__TURTLE_INFO__BUILDER_HPP_
