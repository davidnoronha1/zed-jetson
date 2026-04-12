// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from custom_msgs:msg/Commands.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "custom_msgs/msg/commands.hpp"


#ifndef CUSTOM_MSGS__MSG__DETAIL__COMMANDS__BUILDER_HPP_
#define CUSTOM_MSGS__MSG__DETAIL__COMMANDS__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "custom_msgs/msg/detail/commands__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace custom_msgs
{

namespace msg
{

namespace builder
{

class Init_Commands_lateral
{
public:
  explicit Init_Commands_lateral(::custom_msgs::msg::Commands & msg)
  : msg_(msg)
  {}
  ::custom_msgs::msg::Commands lateral(::custom_msgs::msg::Commands::_lateral_type arg)
  {
    msg_.lateral = std::move(arg);
    return std::move(msg_);
  }

private:
  ::custom_msgs::msg::Commands msg_;
};

class Init_Commands_forward
{
public:
  explicit Init_Commands_forward(::custom_msgs::msg::Commands & msg)
  : msg_(msg)
  {}
  Init_Commands_lateral forward(::custom_msgs::msg::Commands::_forward_type arg)
  {
    msg_.forward = std::move(arg);
    return Init_Commands_lateral(msg_);
  }

private:
  ::custom_msgs::msg::Commands msg_;
};

class Init_Commands_yaw
{
public:
  explicit Init_Commands_yaw(::custom_msgs::msg::Commands & msg)
  : msg_(msg)
  {}
  Init_Commands_forward yaw(::custom_msgs::msg::Commands::_yaw_type arg)
  {
    msg_.yaw = std::move(arg);
    return Init_Commands_forward(msg_);
  }

private:
  ::custom_msgs::msg::Commands msg_;
};

class Init_Commands_thrust
{
public:
  explicit Init_Commands_thrust(::custom_msgs::msg::Commands & msg)
  : msg_(msg)
  {}
  Init_Commands_yaw thrust(::custom_msgs::msg::Commands::_thrust_type arg)
  {
    msg_.thrust = std::move(arg);
    return Init_Commands_yaw(msg_);
  }

private:
  ::custom_msgs::msg::Commands msg_;
};

class Init_Commands_roll
{
public:
  explicit Init_Commands_roll(::custom_msgs::msg::Commands & msg)
  : msg_(msg)
  {}
  Init_Commands_thrust roll(::custom_msgs::msg::Commands::_roll_type arg)
  {
    msg_.roll = std::move(arg);
    return Init_Commands_thrust(msg_);
  }

private:
  ::custom_msgs::msg::Commands msg_;
};

class Init_Commands_pitch
{
public:
  explicit Init_Commands_pitch(::custom_msgs::msg::Commands & msg)
  : msg_(msg)
  {}
  Init_Commands_roll pitch(::custom_msgs::msg::Commands::_pitch_type arg)
  {
    msg_.pitch = std::move(arg);
    return Init_Commands_roll(msg_);
  }

private:
  ::custom_msgs::msg::Commands msg_;
};

class Init_Commands_arm
{
public:
  explicit Init_Commands_arm(::custom_msgs::msg::Commands & msg)
  : msg_(msg)
  {}
  Init_Commands_pitch arm(::custom_msgs::msg::Commands::_arm_type arg)
  {
    msg_.arm = std::move(arg);
    return Init_Commands_pitch(msg_);
  }

private:
  ::custom_msgs::msg::Commands msg_;
};

class Init_Commands_mode
{
public:
  Init_Commands_mode()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Commands_arm mode(::custom_msgs::msg::Commands::_mode_type arg)
  {
    msg_.mode = std::move(arg);
    return Init_Commands_arm(msg_);
  }

private:
  ::custom_msgs::msg::Commands msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::custom_msgs::msg::Commands>()
{
  return custom_msgs::msg::builder::Init_Commands_mode();
}

}  // namespace custom_msgs

#endif  // CUSTOM_MSGS__MSG__DETAIL__COMMANDS__BUILDER_HPP_
