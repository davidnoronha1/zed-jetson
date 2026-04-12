// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from custom_msgs:msg/Commands.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "custom_msgs/msg/commands.hpp"


#ifndef CUSTOM_MSGS__MSG__DETAIL__COMMANDS__STRUCT_HPP_
#define CUSTOM_MSGS__MSG__DETAIL__COMMANDS__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__custom_msgs__msg__Commands __attribute__((deprecated))
#else
# define DEPRECATED__custom_msgs__msg__Commands __declspec(deprecated)
#endif

namespace custom_msgs
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct Commands_
{
  using Type = Commands_<ContainerAllocator>;

  explicit Commands_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->mode = "";
      this->arm = 0l;
      this->pitch = 0l;
      this->roll = 0l;
      this->thrust = 0l;
      this->yaw = 0l;
      this->forward = 0l;
      this->lateral = 0l;
    }
  }

  explicit Commands_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : mode(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->mode = "";
      this->arm = 0l;
      this->pitch = 0l;
      this->roll = 0l;
      this->thrust = 0l;
      this->yaw = 0l;
      this->forward = 0l;
      this->lateral = 0l;
    }
  }

  // field types and members
  using _mode_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _mode_type mode;
  using _arm_type =
    int32_t;
  _arm_type arm;
  using _pitch_type =
    int32_t;
  _pitch_type pitch;
  using _roll_type =
    int32_t;
  _roll_type roll;
  using _thrust_type =
    int32_t;
  _thrust_type thrust;
  using _yaw_type =
    int32_t;
  _yaw_type yaw;
  using _forward_type =
    int32_t;
  _forward_type forward;
  using _lateral_type =
    int32_t;
  _lateral_type lateral;

  // setters for named parameter idiom
  Type & set__mode(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->mode = _arg;
    return *this;
  }
  Type & set__arm(
    const int32_t & _arg)
  {
    this->arm = _arg;
    return *this;
  }
  Type & set__pitch(
    const int32_t & _arg)
  {
    this->pitch = _arg;
    return *this;
  }
  Type & set__roll(
    const int32_t & _arg)
  {
    this->roll = _arg;
    return *this;
  }
  Type & set__thrust(
    const int32_t & _arg)
  {
    this->thrust = _arg;
    return *this;
  }
  Type & set__yaw(
    const int32_t & _arg)
  {
    this->yaw = _arg;
    return *this;
  }
  Type & set__forward(
    const int32_t & _arg)
  {
    this->forward = _arg;
    return *this;
  }
  Type & set__lateral(
    const int32_t & _arg)
  {
    this->lateral = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    custom_msgs::msg::Commands_<ContainerAllocator> *;
  using ConstRawPtr =
    const custom_msgs::msg::Commands_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<custom_msgs::msg::Commands_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<custom_msgs::msg::Commands_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      custom_msgs::msg::Commands_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<custom_msgs::msg::Commands_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      custom_msgs::msg::Commands_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<custom_msgs::msg::Commands_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<custom_msgs::msg::Commands_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<custom_msgs::msg::Commands_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__custom_msgs__msg__Commands
    std::shared_ptr<custom_msgs::msg::Commands_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__custom_msgs__msg__Commands
    std::shared_ptr<custom_msgs::msg::Commands_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const Commands_ & other) const
  {
    if (this->mode != other.mode) {
      return false;
    }
    if (this->arm != other.arm) {
      return false;
    }
    if (this->pitch != other.pitch) {
      return false;
    }
    if (this->roll != other.roll) {
      return false;
    }
    if (this->thrust != other.thrust) {
      return false;
    }
    if (this->yaw != other.yaw) {
      return false;
    }
    if (this->forward != other.forward) {
      return false;
    }
    if (this->lateral != other.lateral) {
      return false;
    }
    return true;
  }
  bool operator!=(const Commands_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct Commands_

// alias to use template instance with default allocator
using Commands =
  custom_msgs::msg::Commands_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace custom_msgs

#endif  // CUSTOM_MSGS__MSG__DETAIL__COMMANDS__STRUCT_HPP_
