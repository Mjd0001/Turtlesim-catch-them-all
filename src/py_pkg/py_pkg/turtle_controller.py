#!/usr/bin/env python3
import math
import rclpy
from rclpy.node import Node
from turtlesim.msg import Pose
from geometry_msgs.msg import Twist
from my_turtle_interfaces.msg import TurtleInfo
from turtlesim.srv import Kill


class turtleControllerNode(Node): 
    def __init__(self):
        super().__init__('turtle_controller') 
        self.declare_parameter('catch_closest_turtle_first',True)
        
        self.catch_closest_turtle_first = self.get_parameter('catch_closest_turtle_first').value
        self.turtle_pose_subscriber_ = self.create_subscription(Pose, "turtle1/pose" ,
                                                                self.callback_turtle_pose,10)
        self.pose_ = None
        self.turtle_cmd_vel_publisher_ = self.create_publisher(Twist,"turtle1/cmd_vel",10)
        
        
        self.alive_turtle_subscriber_ = self.create_subscription(TurtleInfo, "alive_turtles",
                                                                 self.callback_turtle_info, 10)
        self.alive_turtles_ = []
        self.target_turtle_ = None
        
        
        self.move_turtle_timer_ = self.create_timer(0.01 , self.move_turtle)
        self.get_logger().info("turtle controller has been started... ")



    def callback_turtle_info(self,newturtle):
        self.alive_turtles_.append(newturtle) 
        
    def callback_turtle_pose(self, pose):
        self.pose_ = pose           
    
    def turtle_to_catch(self, alive_turtles):
        if self.catch_closest_turtle_first:
            distance = 100
            targent_turlte = None
            for turtle in alive_turtles:
                dist_x = turtle.x - self.pose_.x
                dist_y = turtle.y - self.pose_.y
                dis = math.sqrt((dist_x)**2 + (dist_y)**2)
                if dis < distance:
                    distance = dis
                    targent_turlte = turtle
        else:
            targent_turlte = alive_turtles[0]
            
        return targent_turlte
    
    
    def move_turtle(self):
        if self.pose_ == None:
            return
        if not self.alive_turtles_:
            return
        
        self.target_turtle_ = self.turtle_to_catch(self.alive_turtles_)

        self.target_x = self.target_turtle_.x
        self.target_y = self.target_turtle_.y
        
        dist_x = self.target_x - self.pose_.x
        dist_y = self.target_y - self.pose_.y
        
        distance_to_target = math.sqrt(  (dist_x)**2 + (dist_y)**2   )  
        
         
        self.move_commend_ = Twist()
        
        if distance_to_target > 0.5 :
            self.move_commend_.linear.x =  2*distance_to_target
            
            goal_theta = math.atan2(dist_y,dist_x)
            diff = goal_theta - self.pose_.theta
            if diff > math.pi:
                diff -= 2*math.pi
            elif diff < -math.pi:
                diff += 2*math.pi
            
            self.move_commend_.angular.z = 6*diff
            
            self.turtle_cmd_vel_publisher_.publish(self.move_commend_)
        else:
            self.move_commend_.linear.x = 0.0
            self.move_commend_.angular.z =0.0   
            self.kill_turtle(self.target_turtle_.name)
            self.alive_turtles_.pop(self.alive_turtles_.index(self.target_turtle_))
            
        
         
        
            
    
    
    def kill_turtle(self, turtle_name):
        client = self.create_client(Kill, "kill")
        while not client.wait_for_service(1.0):
            self.get_logger().warn("Server not available yet ...")
    
        request = Kill.Request()
        request.name = turtle_name
        
        
        future = client.call_async(request)
        future.add_done_callback(self.callback_kill_turtle)
        
    def callback_kill_turtle(self ,future):
        try:
            future.result()
            
        except Exception as e:
            self.get_logger().error("Service call failed %r " % (e,))
             
    
    
def main(args=None):
    rclpy.init(args=args)#
    node = turtleControllerNode() 
    rclpy.spin(node)
    rclpy.shutdown()

if __name__ == "__main__":
    main()