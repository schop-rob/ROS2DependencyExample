#include <chrono>
#include <functional>
#include <memory>
#include <string>

#include "rclcpp/rclcpp.hpp"
#include "demo_messages/msg/int_string.hpp" 

using namespace std::chrono_literals;

class CppCustomPublisher : public rclcpp::Node
{
public:
  CppCustomPublisher()
  : Node("cpp_custom_publisher_node"), count_(0)
  {
    publisher_ = this->create_publisher<demo_messages::msg::IntString>("int_string_topic", 10);
    timer_ = this->create_wall_timer(
    1000ms, std::bind(&CppCustomPublisher::timer_callback, this));
    RCLCPP_INFO(this->get_logger(), "C++ Custom Publisher started.");
  }

private:
  void timer_callback()
  {
    auto message = demo_messages::msg::IntString();
    message.number = count_++;
    message.text = "Hello from C++! Message number: " + std::to_string(message.number);
    RCLCPP_INFO(this->get_logger(), "C++ Publishing: Number: %d, Text: '%s'", message.number, message.text.c_str());
    publisher_->publish(message);
  }
  rclcpp::TimerBase::SharedPtr timer_;
  rclcpp::Publisher<demo_messages::msg::IntString>::SharedPtr publisher_;
  size_t count_;
};

int main(int argc, char * argv[])
{
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<CppCustomPublisher>());
  rclcpp::shutdown();
  return 0;
}