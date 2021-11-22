#!/bin/bash

set -e

./build.sh

echo -e "\033[32m\033[1mRunning gfx_main...\033[0m"

./bin/gfx_main
