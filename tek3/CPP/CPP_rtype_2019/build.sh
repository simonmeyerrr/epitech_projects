#!/bin/bash

mkdir -p build && cd build && conan install .. --build=missing && cmake .. -DCMAKE_BUILD_TYPE=Debug -G "Unix Makefiles" && cmake --build .