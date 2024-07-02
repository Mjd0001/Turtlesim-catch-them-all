#!/usr/bin/env python3
import rclpy
from rclpy.node import Node
from turtlesim.srv import Spawn
import random
import math
from my_turtle_interfaces.msg import TurtleInfo
from functools import partial


class turtleSpawnerNode(Node): 
    def __init__(self):
        super().__init__('turtle_spawner') 
        self.declare_parameter("spawn_frequency",1.0)
        
        self.spawn_frequency = self.get_parameter("spawn_frequency").value
        self.spawner_timer_ = self.create_timer(self.spawn_frequency, self.call_spawner_server)
        self.get_logger().info("turtle spawner has been started.")
        
        self.alive_turtle_publisher_ = self.create_publisher(TurtleInfo, "alive_turtles",10)
     
        
    def call_spawner_server(self):
        client = self.create_client(Spawn, "spawn" )
        while not client.wait_for_service(1.0):
            self.get_logger().warn("Server not available yet ...")
    
        request = Spawn.Request()
        request.x = random.uniform(0.0,11.0)
        request.y = random.uniform(0.0,11.0)
        request.theta = random.uniform(0.0, 2 * math.pi)
        
        self.newturtle = TurtleInfo()
        self.newturtle.x = request.x
        self.newturtle.y = request.y
        
        future = client.call_async(request)
        future.add_done_callback(partial(self.callback_call_spawner, x = request.x, y = request.y , theta = request.theta))
        
        
    def callback_call_spawner(self ,future, x , y , theta):
        try:
            response = future.result()
            if response != "":
                self.get_logger().info(response.name + " is now alive")
                self.newturtle.name = response.name
                self.alive_turtle_publisher_.publish(self.newturtle)
        
            
            
    
        except Exception as e:
            self.get_logger().error("Service call failed %r " % (e,))

def main(args=None):
    rclpy.init(args=args)#
    node = turtleSpawnerNode()
    rclpy.spin(node)
    rclpy.shutdown()

if __name__ == "__main__":
    main()