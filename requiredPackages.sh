#!/bin/bash

#installing OpenCV requirements , links : https://docs.opencv.org/master/d7/d9f/tutorial_linux_install.html
sudo apt-get install build-essential cmake git libgtk2.0-dev libgtk-3-0 libgtk-3-dev pkg-config libavcodec-dev libavformat-dev libswscale-dev python-dev python-numpy libtbb2 libtbb-dev libjpeg-dev libpng-dev libtiff-dev libjasper-dev libdc1394-22-dev git

#clone OpenCV from git
git clone https://github.com/opencv/opencv.git
cd opencv
mkdir build
cd build

#compiling git
cmake -D CMAKE_BUILD_TYPE=Release -D CMAKE_INSTALL_PREFIX=/usr/local ..
make -j $(nproc)
sudo make install

