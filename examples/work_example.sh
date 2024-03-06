#!/bin/bash

APPS_FOLDER=$1

x-terminal-emulator -e ${APPS_FOLDER}/shop-server &

x-terminal-emulator -e ${APPS_FOLDER}/shop-manager -h 127.0.0.1 -p 18080 &

x-terminal-emulator -e ${APPS_FOLDER}/shop-client -h 127.0.0.1 -p 18080 -n Clara &
x-terminal-emulator -e ${APPS_FOLDER}/shop-client -h 127.0.0.1 -p 18080 -n Anton &
x-terminal-emulator -e ${APPS_FOLDER}/shop-client -h 127.0.0.1 -p 18080 -n Ivan &
x-terminal-emulator -e ${APPS_FOLDER}/shop-client -h 127.0.0.1 -p 18080 -n Kate &
x-terminal-emulator -e ${APPS_FOLDER}/shop-client -h 127.0.0.1 -p 18080 -n Alex &
x-terminal-emulator -e ${APPS_FOLDER}/shop-client -h 127.0.0.1 -p 18080 -n John &
x-terminal-emulator -e ${APPS_FOLDER}/shop-client -h 127.0.0.1 -p 18080 -n Karl &
x-terminal-emulator -e ${APPS_FOLDER}/shop-client -h 127.0.0.1 -p 18080 -n Felix &
x-terminal-emulator -e ${APPS_FOLDER}/shop-client -h 127.0.0.1 -p 18080 -n Eva &
x-terminal-emulator -e ${APPS_FOLDER}/shop-client -h 127.0.0.1 -p 18080 -n Peter &