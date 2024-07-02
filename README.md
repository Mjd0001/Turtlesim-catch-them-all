# Turtlesim-catch-them-all
In this project I used Turtlesim package to make a simple game. There is main turtle will to try to catch every new turtle in the screen, and when the turtle has been caught it will disappear and the main turte will start to go to catch another turtle.<br> 
![image](https://github.com/Mjd0001/Turtlesim-catch-them-all/assets/105239889/d021af3e-4bc1-4f49-a8f7-27d2c87d7635)
<br> <br> 

## About the project
There are three nodes:
- turtlesim_node from the turtlesim package
- turtle_controller: a custom node to control the main turlte (named "turtle1"). this node is subscriber to "turtle1/pose" topic to know the current position of the main turtle. And publishing in "turtle1/cmd_vel" topic to move the turtle toward the target. And subscribing in a custom topic named "alive_turtles" which contains the positions of the new targets turtles. And client to "kill" service that provided by turtlesim package.
- turtle_spawner: this node act as a client to "spawn" service to spawn a new turtles in the screen in a random position, and then will publish this new turtle to "alive_turtles" topic.

In the launch file we can control the spawn_frequency of turtles, also to determine whether you want the main turtle to catch the closest turtle or to catch the turtles in order.

## the rqt_graph
![image](https://github.com/Mjd0001/Turtlesim-catch-them-all/assets/105239889/53597d13-4a53-40c2-9c67-99a1e0300e82)

