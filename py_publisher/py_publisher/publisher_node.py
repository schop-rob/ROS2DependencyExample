import rclpy
from rclpy.node import Node
from demo_messages.msg import IntString

class PythonCustomPublisher(Node):
    def __init__(self):
        super().__init__('python_custom_publisher_node')
        self.publisher_ = self.create_publisher(IntString, 'int_string_topic', 10)
        self.timer_period = 1.0
        self.timer = self.create_timer(self.timer_period, self.timer_callback)
        self.count = 0
        self.get_logger().info('Python Custom Publisher started.')

    def timer_callback(self):
        msg = IntString()
        msg.number = self.count
        msg.text = f"Hello from Python! Message number: {self.count}"
        self.publisher_.publish(msg)
        self.get_logger().info(f'Python Publishing: Number: {msg.number}, Text: "{msg.text}"')
        self.count += 1

def main(args=None):
    rclpy.init(args=args)
    python_custom_publisher = PythonCustomPublisher()
    rclpy.spin(python_custom_publisher)
    python_custom_publisher.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()