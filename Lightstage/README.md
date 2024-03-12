# monitor-lightstage

## Contents:
"SphericalHarmonics"	Includes spherical harmonics to display in the lightstage.
"Lightstage_Client"	Client project folder.
"Lightstage_Server"	Server project folder.
"Lightstage-Stage2"	The project folder for the renderer. Which is stage 2 of the lightstage pipeline after the scanning-stage.

## Setting up the lightstage
Before you can use the lightstage properly, you have to change some NVIDIA-x-screen settings.

0. Open 'NVIDIA X Server Settings'.
1. Go into the 'X Server Display Configuration' tab.
2. Enable the deactivated monitors and set their configuration to 'X screen 1'.
3. Ctrl + drag one screen above the other one.
4. Screen 0: 
	- Change the order from HDMI-0, DP-2, DP-4, DP-0.
5. Screen 1:
	- Invert display DP-2(middle) under its 'Orientation' section.
	- Set the 'Position' of DP-4 to 'Absolute' and change its x-coordinate from '+3840+0 to '+3740+0'.

## How to operate the lightstage
After the object is placed inside the lightstage and the door is closed, open the terminal in the corresponding subfolder and...

 1. ...execute the server program 	'./Lightstage_Server'.

 2. ...execute the Client programs	
    - Client 0:	'./Lightstage_Client 0'
    - Client 1: 'DISPLAY=:0.1 ./Lightstage_Client 1'

 3. ...execute the renderer program	'./Lightstage-Stage2'
    (make sure that the first scanning process is finished).
    
## Frequent problems:
- Camera does not work when scanning. 
	-> restart server until it can connect to the camera.
- The clients can not read the server messages while scanning.
	-> 1: Try to scan with high delay for both monitors.
	-> 2: If 1 does not work, start the server in debug-mode and always break before scanning. 
	      This slows the process down and prevents stacked sockets from the server.
- The responses are not from the correct SH.
	-> see the solution above.
