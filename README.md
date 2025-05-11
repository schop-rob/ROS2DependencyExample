# ROS2 dependency example

This repo demonstrates how dependencies work in ROS2. 

Check colcon graph for a view on dependencies:
```
> colcon graph
demo_messages  +**
cpp_publisher   + 
py_publisher     +
```

## Usage
Copy each of the packages ('cpp_publisher'. 'demo_messages' and 'py_publisher') into your ros workspace's `src` directory.
Then, run `colcon build` before using `source install/setup.bash`.

You can start the C++ based publisher via `ros2 run cpp_publisher cpp_talker`.
To start the Python based publisher, use `ros2 run py_publisher py_talker`.

You can observe the output using `ros2 topic echo /int_string_topic`. It should look something like this:

```
number: 12
text: 'Hello from Python! Message number: 12'
---
number: 18
text: 'Hello from C++! Message number: 18'
---
number: 13
text: 'Hello from Python! Message number: 13'
---
number: 19
text: 'Hello from C++! Message number: 19'
---
number: 14
text: 'Hello from Python! Message number: 14'
---
...
```