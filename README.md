# Atom_fan_controller
Repository of platformio environment to control fan and relay from m5atom matrix

# usage
```
 # Terminal 1
 rosrun rosserial_python serial_node.py _port:=/dev/fan0 _baud:=57600
 # Terminal 2
 rostopic pub toggle_fan std_msgs/Bool "True" --once #Turn on Green LED and fan start
 rostopic pub toggle_fan std_msgs/Bool "False" --once #Turn off LED and fan stop
```
# udev file setup if needed (E.g. /dev/fan0)
```
rosrun Atom_fan_controller fan_udev_setup.sh              
```

# For development
Link the library following http://wiki.ros.org/rosserial_arduino/Tutorials/Arduino%20IDE%20Setup
```
cd Atom_fan_controller/lib/
rosrun rosserial_arduino make_libraries.py .
```

