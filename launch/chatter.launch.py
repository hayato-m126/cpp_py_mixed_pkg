import launch
from launch_ros.actions import Node


def generate_launch_description():
    # talker node

    # listener node
    listener_node = Node(
        package="cpp_py_mixed_pkg",
        executable="listener_node",
        output="screen",
        name="listner",
    )

    return launch.LaunchDescription(
        [
            listener_node,
        ]
    )
