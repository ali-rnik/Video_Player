#!/bin/bash
if [ -z "$1" ]
then
	echo "Pleaso also enter the video name you wanna play."
	echo "For example: ./videoApp.sh myvideo.format"
else
	./videoController &
	./videoPlayer $1
fi
