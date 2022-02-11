import rclpy
from rclpy.node import Node
from http.server import BaseHTTPRequestHandler, HTTPServer
import time

from std_msgs.msg import Bool

class SimpleServer(BaseHTTPRequestHandler):
    def __init__(self, controller):
        self.controller = controller

    def __call__(self, *args, **kwargs):
        """ Handle a request """
        super().__init__(*args, **kwargs)

    def do_GET(self):
        if self.path == '/api/left':
            self.controller.go_left()

        if self.path == '/api/right':
            self.controller.go_right()

        body = '<html><body><button onclick="fetch(\'/api/left\');">&lt;</button> <button onclick="fetch(\'/api/right\');">&gt;</button></body></html>'.encode('ascii')

        self.send_response(200)
        self.send_header("Content-Type", "text/html")
        self.send_header("Content-Length", str(len(body)))
        self.end_headers()
        self.wfile.write(body)

class SimpleWebController(Node):

    def __init__(self):
        super().__init__('simple_web_controller')
        self.publisher_left = self.create_publisher(Bool, 'left', 10)
        self.publisher_right = self.create_publisher(Bool, 'right', 10)

        self.start_server()

    def start_server(self):
        self.get_logger().info('Starting web server')
        self.web_server = HTTPServer(("0.0.0.0", 8080), SimpleServer(self))

        try:
            self.web_server.serve_forever()
        except KeyboardInterrupt:
            pass

        webServer.server_close()
        self.get_logger().info('Stopped server')

    def go_left(self):
        msg = Bool()
        msg.data = True
        self.publisher_left.publish(msg)

    def go_right(self):
        msg = Bool()
        msg.data = True
        self.publisher_right.publish(msg)

def main(args=None):
    rclpy.init(args=args)

    web_controller = SimpleWebController()

    rclpy.spin(web_controller)

    # Destroy the node explicitly
    # (optional - otherwise it will be done automatically
    # when the garbage collector destroys the node object)
    minimal_publisher.destroy_node()
    rclpy.shutdown()


if __name__ == '__main__':
    main()