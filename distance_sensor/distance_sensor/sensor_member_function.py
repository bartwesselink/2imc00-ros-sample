import rclpy
from rclpy.node import Node
from http.server import BaseHTTPRequestHandler, HTTPServer
import time
import math

from std_msgs.msg import Int16MultiArray, Int16

class DistanceSensor(Node):
    def __init__(self):
        super().__init__('distance_sensor')
        self.publisher_value = self.create_publisher(Int16, 'distance', 10)
        self.start_timer()

        self.current_environment = []
        self.x = 0
        self.y = 0
        self.rotation = 0

        self.environment_subscription = self.create_subscription(
            Int16MultiArray,
            'environment',
            self.handle_environment,
            10)

        self.x_subscription = self.create_subscription(Int16, 'robot_x', self.handle_x, 10)
        self.y_subscription = self.create_subscription(Int16, 'robot_y', self.handle_y, 10)
        self.rotation_subscription = self.create_subscription(Int16, 'robot_rotation', self.handle_rotation, 10)

    def handle_x(self, msg):
        self.x = msg.data

    def handle_y(self, msg):
        self.y = msg.data

    def handle_rotation(self, msg):
        self.rotation = msg.data

    def handle_environment(self, msg):
        self.current_environment = list(msg.data)

    def start_timer(self):
        self.get_logger().info('Start emitting values')

        self.timer = self.create_timer(0.1, self.timer_callback)

    def compute_distance_of_array(self, parts):
        i = 0
        for x in parts:
            if x > 0: # if obstacle
                return i

            i = i + 1

        if i == 0:
            return -1 # appearantly, we are in front of a wall

        return i

    def distance_to_right(self):
        map = self.current_environment
        size = int(math.sqrt(len(map)))

        start = (size - self.y) * size + self.x # start 1 cell to the right
        end = int(size * math.ceil(start / size)) # round up to next multiple of 20

        return self.compute_distance_of_array(map[start:end])

    def distance_to_left(self):
        map = self.current_environment
        size = int(math.sqrt(len(map)))

        end = (size - self.y) * size + (self.x - 1) # start 1 cell to the left
        start = int(size * math.floor(end / size)) # round up to previous multiple of 20

        l = map[start:end]
        l.reverse()

        return self.compute_distance_of_array(l)

    def distance_to_top(self):
        map = self.current_environment
        size = int(math.sqrt(len(map)))

        robot_index = (size - self.y) * size + (self.x - 1)

        column = []
        for idx, val in enumerate(map):
            if idx < robot_index and (idx % size) == (self.x - 1):
                column.append(val)

        column.reverse()

        return self.compute_distance_of_array(column)

    def distance_to_bottom(self):
        map = self.current_environment
        size = int(math.sqrt(len(map)))

        robot_index = (size - self.y) * size + (self.x - 1)

        column = []
        for idx, val in enumerate(map):
            if idx > robot_index and (idx % size) == (self.x - 1):
                column.append(val)

        return self.compute_distance_of_array(column)

    def timer_callback(self):
        self.emit_value(self.calculate_distance())

    def calculate_distance(self):
        if self.x == 0 or self.y == 0 or len(self.current_environment) == 0:
            return -1

        if self.rotation == 1:
            return self.distance_to_right()

        if self.rotation == 2:
            return self.distance_to_bottom()

        if self.rotation == 3:
            return self.distance_to_left()

        if self.rotation == 4:
            return self.distance_to_top()

        # calculate distance
        return -1

    def emit_value(self, value):
        msg = Int16()
        msg.data = value
        self.publisher_value.publish(msg)

def main(args=None):
    rclpy.init(args=args)

    distance_sensor = DistanceSensor()

    rclpy.spin(distance_sensor)

    # Destroy the node explicitly
    # (optional - otherwise it will be done automatically
    # when the garbage collector destroys the node object)
    minimal_publisher.destroy_node()
    rclpy.shutdown()


if __name__ == '__main__':
    main()