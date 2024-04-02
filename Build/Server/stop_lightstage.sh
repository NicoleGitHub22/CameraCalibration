#!/bin/bash

# Beende den Prozess Lightstageserver
pkill -f "Lightstage_Server"

# Beende die Prozesse Lightstage 0 und Lightstage 1
pkill -f "DISPLAY=:1.0 ./Lightstage 0"
pkill -f "DISPLAY=:1.1 ./Lightstage 1"

