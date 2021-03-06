// Copyright 2014 Open Source Robotics Foundation, Inc.
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#include "cpp_py_mixed_pkg/listener_component.hpp"

#include <string>

#include "rclcpp/rclcpp.hpp"
#include "rclcpp_components/register_node_macro.hpp"
#include "std_msgs/msg/string.hpp"

namespace cpp_py_mixed_pkg
{
// Create a Listener class that subclasses the generic rclcpp::Node base class.
// The main function below will instantiate the class as a ROS node.
class Listener : public rclcpp::Node
{
public:
  CPP_PY_MIXED_PKG_LISTENER_COMPONENT_PUBLIC
  explicit Listener(const rclcpp::NodeOptions & options) : Node("listener", options)
  {
    RCLCPP_ERROR(get_logger(), "initialize");
    sub_ = create_subscription<std_msgs::msg::String>(
      "chatter", 1, std::bind(&Listener::chatterCallback, this, std::placeholders::_1));
  }

  void chatterCallback(const std_msgs::msg::String::SharedPtr msg)
  {
    RCLCPP_INFO_STREAM(get_logger(), msg->data);
  }

private:
  rclcpp::Subscription<std_msgs::msg::String>::SharedPtr sub_;
};

}  // namespace cpp_py_mixed_pkg

RCLCPP_COMPONENTS_REGISTER_NODE(cpp_py_mixed_pkg::Listener)
