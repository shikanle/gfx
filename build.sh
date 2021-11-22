#!/bin/bash

set -e

if [ ! -d "./build" ];then
    mkdir ./build
fi

cmake -B ./build
make -C ./build

if [ ! -d "./bin" ];then
    mkdir ./bin
fi

cp -r ./build/gfx_main ./bin
