import rclpy
from rclpy.node import Node
from http.server import BaseHTTPRequestHandler, HTTPServer
import time
import os
import json
import threading

from std_msgs.msg import Int16MultiArray, Int16
from bottle import Bottle, route, run, get, static_file, template

class Server:
    def __init__(self, host, port, controller):
        self._host = host
        self._port = port
        self._controller = controller
        self._root = os.path.dirname(os.path.realpath(__file__)) + "/../../../../static"
        self._app = Bottle()
        self._route()

    def _route(self):
        self._app.route('/', method="GET", callback=self._index)
        self._app.route('/api/map', method="GET", callback=self._map)
        self._app.route('/assets/<filepath:re:.*\.(jpg|png|gif|ico|svg|css|js|html)>', method="GET", callback=self._assets)

    def start(self):
        t = threading.Thread(target=self._run)
        t.setDaemon(True)
        t.start()
    
    def _run(self):
        self._app.run(host=self._host, port=self._port, quiet=True)

    def _index(self):
        return static_file("index.html", root=self._root)

    def _map(self):
        return json.dumps(dict({ 'environment': self._controller.current_environment, 'distance': self._controller.distance, 'robot': { 'x': self._controller.x, 'y': self._controller.y, 'rotation': self._controller.rotation } }))

    def _assets(self, filepath):
        return static_file(filepath, root=self._root + '/assets/')

class WebController(Node):

    def __init__(self):
        super().__init__('web_controller')
        self.current_environment = []
        self.x = 0
        self.y = 0
        self.rotation = 0
        self.distance = -1

        self.environment_subscription = self.create_subscription(
            Int16MultiArray,
            'environment',
            self.handle_environment,
            10)

        self.x_subscription = self.create_subscription(Int16, 'robot_x', self.handle_x, 10)
        self.y_subscription = self.create_subscription(Int16, 'robot_y', self.handle_y, 10)
        self.rotation_subscription = self.create_subscription(Int16, 'robot_rotation', self.handle_rotation, 10)
        self.distance_subscription = self.create_subscription(Int16, 'distance', self.handle_distance, 10)

        self.start_server()

    def handle_x(self, msg):
        self.x = msg.data

    def handle_y(self, msg):
        self.y = msg.data

    def handle_distance(self, msg):
        self.distance = msg.data

    def handle_rotation(self, msg):
        self.rotation = msg.data

    def handle_environment(self, msg):
        self.current_environment = list(msg.data)

    def start_server(self):
        self.get_logger().info('Starting web server')
        
        server = Server(host='0.0.0.0', port=8080, controller=self)
        server.start()

def main(args=None):
    rclpy.init(args=args)

    web_controller = WebController()

    rclpy.spin(web_controller)

    # Destroy the node explicitly
    # (optional - otherwise it will be done automatically
    # when the garbage collector destroys the node object)
    minimal_publisher.destroy_node()
    rclpy.shutdown()


if __name__ == '__main__':
    main()