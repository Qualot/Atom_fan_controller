#!/bin/sh

echo "#udev id for fan
SUBSYSTEM==\"tty\", ATTRS{idVendor}==\"0403\", ATTRS{idProduct}==\"6001\", SYMLINK+=\"fan0\"" > /tmp/80-fan-udev.rules

sudo sh -c "cat /tmp/80-fan-udev.rules > /etc/udev/rules.d/80-fan-udev.rules"

sudo udevadm control --reload-rules
sudo adduser $USER dialout

echo ""
echo "fan udev setup has finished."

