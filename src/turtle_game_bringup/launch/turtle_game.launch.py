from launch import LaunchDescription
from launch_ros.actions import Node


def generate_launch_description():
    ld = LaunchDescription()
    turtlesim_node = Node(
        package="turtlesim",
        executable="turtlesim_node"
    )
    
    turtle_controller_node = Node(
        package="py_pkg",
        executable="turtle_controller",
        parameters=[
            {"catch_closest_turtle_first": False}
        ]
           
    )
    turtle_spawner_node = Node(
        package="py_pkg",
        executable="turtle_spawner",
        parameters=[
            {"spawn_frequency": 1.0 }
        ]    
    )
    
    ld.add_action(turtlesim_node)
    ld.add_action(turtle_controller_node)
    ld.add_action(turtle_spawner_node)
    return ld