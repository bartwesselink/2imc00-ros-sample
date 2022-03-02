import time

import rclpy
from rclpy.action import ActionServer
from rclpy.node import Node

from communication_interfaces.action import DestroyObstacle
from communication_interfaces.msg import DestroyProgress

class ObstacleDestroyerServer(Node):

    def __init__(self):
        super().__init__('obstacle_destroyer')
        self.get_logger().info('Starting obstacle destroyer')
        self.destroy_publisher = self.create_publisher(DestroyProgress, 'destroy', 10)
        self.action_server = ActionServer(
            self,
            DestroyObstacle,
            'destroy_obstacle',
            self.execute_callback)

    def execute_callback(self, goal_handle):
        feedback_msg = DestroyObstacle.Feedback()
        feedback_msg.progress = 0

        for i in range(1, 11):
            feedback_msg.progress = i * 10
            goal_handle.publish_feedback(feedback_msg)

            result = DestroyProgress()
            result.x = goal_handle.request.x
            result.y = goal_handle.request.y
            result.progress = feedback_msg.progress
            self.destroy_publisher.publish(result)

            time.sleep(0.5)

        goal_handle.succeed()

        result = DestroyObstacle.Result()
        result.succeeded = True
        return result


def main(args=None):
    rclpy.init(args=args)

    obstacle_destroyer_server = ObstacleDestroyerServer()

    rclpy.spin(obstacle_destroyer_server)


if __name__ == '__main__':
    main()
