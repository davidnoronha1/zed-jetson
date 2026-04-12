// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from custom_msgs:msg/Telemetry.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "custom_msgs/msg/telemetry.hpp"


#ifndef CUSTOM_MSGS__MSG__DETAIL__TELEMETRY__BUILDER_HPP_
#define CUSTOM_MSGS__MSG__DETAIL__TELEMETRY__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "custom_msgs/msg/detail/telemetry__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace custom_msgs
{

namespace msg
{

namespace builder
{

class Init_Telemetry_yaw
{
public:
  explicit Init_Telemetry_yaw(::custom_msgs::msg::Telemetry & msg)
  : msg_(msg)
  {}
  ::custom_msgs::msg::Telemetry yaw(::custom_msgs::msg::Telemetry::_yaw_type arg)
  {
    msg_.yaw = std::move(arg);
    return std::move(msg_);
  }

private:
  ::custom_msgs::msg::Telemetry msg_;
};

class Init_Telemetry_pitch
{
public:
  explicit Init_Telemetry_pitch(::custom_msgs::msg::Telemetry & msg)
  : msg_(msg)
  {}
  Init_Telemetry_yaw pitch(::custom_msgs::msg::Telemetry::_pitch_type arg)
  {
    msg_.pitch = std::move(arg);
    return Init_Telemetry_yaw(msg_);
  }

private:
  ::custom_msgs::msg::Telemetry msg_;
};

class Init_Telemetry_roll
{
public:
  explicit Init_Telemetry_roll(::custom_msgs::msg::Telemetry & msg)
  : msg_(msg)
  {}
  Init_Telemetry_pitch roll(::custom_msgs::msg::Telemetry::_roll_type arg)
  {
    msg_.roll = std::move(arg);
    return Init_Telemetry_pitch(msg_);
  }

private:
  ::custom_msgs::msg::Telemetry msg_;
};

class Init_Telemetry_z
{
public:
  explicit Init_Telemetry_z(::custom_msgs::msg::Telemetry & msg)
  : msg_(msg)
  {}
  Init_Telemetry_roll z(::custom_msgs::msg::Telemetry::_z_type arg)
  {
    msg_.z = std::move(arg);
    return Init_Telemetry_roll(msg_);
  }

private:
  ::custom_msgs::msg::Telemetry msg_;
};

class Init_Telemetry_y
{
public:
  explicit Init_Telemetry_y(::custom_msgs::msg::Telemetry & msg)
  : msg_(msg)
  {}
  Init_Telemetry_z y(::custom_msgs::msg::Telemetry::_y_type arg)
  {
    msg_.y = std::move(arg);
    return Init_Telemetry_z(msg_);
  }

private:
  ::custom_msgs::msg::Telemetry msg_;
};

class Init_Telemetry_x
{
public:
  Init_Telemetry_x()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Telemetry_y x(::custom_msgs::msg::Telemetry::_x_type arg)
  {
    msg_.x = std::move(arg);
    return Init_Telemetry_y(msg_);
  }

private:
  ::custom_msgs::msg::Telemetry msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::custom_msgs::msg::Telemetry>()
{
  return custom_msgs::msg::builder::Init_Telemetry_x();
}

}  // namespace custom_msgs

#endif  // CUSTOM_MSGS__MSG__DETAIL__TELEMETRY__BUILDER_HPP_
