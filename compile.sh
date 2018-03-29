#!/bin/bash

compile_and_link ()
{
	g++ -g $1 -o $2 `pkg-config --cflags --libs gtk+-3.0 opencv`
}


if compile_and_link videoPlayer.cpp videoPlayer; then
	echo "videoPlayer.cpp compiled, Okay."
else
	echo "videoPlayer.cpp not compiled, Error."
fi
		
if compile_and_link videoController.cpp videoController; then
	echo "videoController.cpp compiled, Okay."
else
	echo "videoController.cpp not compiled, Error."
fi
