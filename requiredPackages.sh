#!/bin/bash

# check if root access is provided by user
if [ "$EUID" -ne 0 ]; 
then
    echo "This bash file will install some required packages on your device. Please provide root access by executing \"sudo ./requiredPackages.sh\"."
    exit
fi

echo "Do you want to install some optional packages too? (yes/no) "
read install_optional_packages

# determine required packages to be installed
packages=""
if (( "$install_optional_packages" == "yes" )); 
then
    $packages="cmake git libgtk2.0-dev libgtk-3-dev pkg-config libavcodec-dev libavformat-dev libswscale-dev python-dev python-numpy libtbb2 libtbb-dev libjpeg-dev libpng-dev libtiff-dev libjasper-dev libdc1394-22-dev"
else
    $packages="cmake git libgtk2.0-dev libgtk-3-dev pkg-config libavcodec-dev libavformat-dev libswscale-dev"
fi

sudo apt-get install $packages

# If you are interested in openCV installation process you may want to visit: https://docs.opencv.org/master/d7/d9f/tutorial_linux_install.html
# clone OpenCV from git
git clone https://github.com/opencv/opencv.git
cd opencv
mkdir build
cd build
cmake -D CMAKE_BUILD_TYPE=Release -D CMAKE_INSTALL_PREFIX=/usr/local ..

# determine available processing units
if (( $(nproc) > 1 ); 
    then 
        nprocVar=$(( $(nproc) - 1 ))
    else
        nprocVar=1
fi

make -j$nprocVar # run in parallel
sudo make install
