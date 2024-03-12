#!/bin/sh


# Open new terminal window, change path, and run Lightstageserver
gnome-terminal -e "bash -c 'cd /home/bretznic/Documents/Lightstage/Build/Server/ && ./Lightstage_Server; exec bash'"

# Wait for 2 seconds to ensure the server starts properly before starting the clients
sleep 2

# Open new terminal window, change path, and run Lightstage client 0
gnome-terminal -e "bash -c 'cd /home/bretznic/Documents/Lightstage/Build/Client/ && DISPLAY=:1.0 ./Lightstage 0; exec bash'"

# Open new terminal window, change path, and run Lightstage client 1
gnome-terminal -e "bash -c 'cd /home/bretznic/Documents/Lightstage/Build/Client/ && DISPLAY=:1.1 ./Lightstage 1; exec bash'"

