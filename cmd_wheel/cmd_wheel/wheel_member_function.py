import rclpy
from rclpy.node import Node

from std_msgs.msg import Bool


class CmdWheel(Node):

    def __init__(self):
        super().__init__('cmd_wheel')

        self.get_logger().info('Starting CMD wheel.')

        self.subscription_left = self.create_subscription(
            Bool,
            'left',
            self.action_left,
            10)

        self.subscription_right = self.create_subscription(
            Bool,
            'right',
            self.action_right,
            10)

        self.subscription_left
        self.subscription_right

        self.max = 80
        self.pos = 0

    def action_left(self, msg):
        self.pos = max(0, self.pos - 1)
        self.print_state()

    def action_right(self, msg):
        self.pos = min(self.max, self.pos + 1)
        self.print_state()
        
    def print_state(self):
        result = ""

        for x in range(0, self.max):
            if x == self.pos:
                result = result + "X"
            else:
                result = result + "O"

        self.get_logger().info(result)



def main(args=None):
    rclpy.init(args=args)

    minimal_subscriber = CmdWheel()

    rclpy.spin(minimal_subscriber)

    # Destroy the node explicitly
    # (optional - otherwise it will be done automatically
    # when the garbage collector destroys the node object)
    minimal_subscriber.destroy_node()
    rclpy.shutdown()


if __name__ == '__main__':
    main()