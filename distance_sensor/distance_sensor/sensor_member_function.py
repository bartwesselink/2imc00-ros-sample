import rclpy
from rclpy.node import Node
from http.server import BaseHTTPRequestHandler, HTTPServer
import time

from std_msgs.msg import Float64

class SimpleDistanceSensor(Node):
    def __init__(self):
        super().__init__('simple_distance_sensor')
        self.publisher_value = self.create_publisher(Float64, 'distance', 10)
        self.values = [1000.0,
            9000.0,
            8000.0,
            7000.0,
            5000.0,
            1000.0,
            500.0,
            100.0
        ]

        self.start_timer()

    def start_timer(self):
        self.get_logger().info('Start emitting values')

        timer_period = 0.5  # seconds
        self.timer = self.create_timer(timer_period, self.timer_callback)
        self.i = 0

    def timer_callback(self):
        self.emit_value(self.values[min(len(self.values) - 1, self.i)])
        self.i += 1


    def emit_value(self, value):
        msg = Float64()
        msg.data = value
        self.publisher_value.publish(msg)

def main(args=None):
    rclpy.init(args=args)

    distance_sensor = SimpleDistanceSensor()

    rclpy.spin(distance_sensor)

    # Destroy the node explicitly
    # (optional - otherwise it will be done automatically
    # when the garbage collector destroys the node object)
    minimal_publisher.destroy_node()
    rclpy.shutdown()


if __name__ == '__main__':
    main()