#!/bin/bash
g++ -g $1 -o $2 `pkg-config --cflags --libs gtk+-3.0 opencv`
