import rclpy
from rclpy.node import Node
from http.server import BaseHTTPRequestHandler, HTTPServer
import time
from communication_interfaces.srv import TimeSinceStart 

from std_msgs.msg import Int16MultiArray, Int16, Empty

class Platform(Node):
    x = 9
    y = 9
    rotation = 1

    def __init__(self):
        super().__init__('platform')
        self.get_logger().info('Starting platform')

        self.publisher_x = self.create_publisher(Int16, 'robot_x', 10)
        self.publisher_y = self.create_publisher(Int16, 'robot_y', 10)
        self.publisher_rotation = self.create_publisher(Int16, 'robot_rotation', 10)

        self.subscription_forward = self.create_subscription(Empty, 'move_forward', self.forward, 10)
        self.subscription_left = self.create_subscription(Empty, 'rotate_left', self.left, 10)
        self.subscription_right = self.create_subscription(Empty, 'rotate_right', self.right, 10)
        self.subscription_up = self.create_subscription(Empty, 'rotate_up', self.up, 10)
        self.subscription_down = self.create_subscription(Empty, 'rotate_down', self.down, 10)


        self.time_started = time.time()
        self.service_time_since_start = self.create_service(TimeSinceStart, 'time_since_start', self.time_since_start_callback)

        self.timer = self.create_timer(0.5, self.emit_all)
        self.emit_all()

    def time_since_start_callback(self, request, response):
        response.result = int(time.time() - self.time_started)

        return response

    def forward(self, msg):
        if self.rotation == 1:
            self.x += 1
        elif self.rotation == 2:
            self.y -= 1
        elif self.rotation == 3:
            self.x -= 1
        elif self.rotation == 4:
            self.y += 1

        self.emit_all()

    def left(self, msg):
        self.rotation = 3
        self.emit_all()

    def right(self, msg):
        self.rotation = 1
        self.emit_all()

    def down(self, msg):
        self.rotation = 2
        self.emit_all()

    def up(self, msg):
        self.rotation = 4
        self.emit_all()

    def emit_all(self):
        self.emit_x()
        self.emit_y()
        self.emit_rotation()

    def emit_x(self):
        msg = Int16()
        msg.data = self.x
        self.publisher_x.publish(msg)

    def emit_y(self):
        msg = Int16()
        msg.data = self.y
        self.publisher_y.publish(msg)

    def emit_rotation(self):
        msg = Int16()
        msg.data = self.rotation
        self.publisher_rotation.publish(msg)


def main(args=None):
    rclpy.init(args=args)

    platform = Platform()

    rclpy.spin(platform)

    # Destroy the node explicitly
    # (optional - otherwise it will be done automatically
    # when the garbage collector destroys the node object)
    minimal_publisher.destroy_node()
    rclpy.shutdown()


if __name__ == '__main__':
    main()