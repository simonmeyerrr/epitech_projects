#!/bin/bash
echo "Os type:" $OSTYPE
if [[ "msys" == "$OSTYPE" ]]
then
  echo "Creating 'build' directory" && mkdir -p build && cd build && echo "Installing conan dependencies" && conan install .. --build=missing && echo "Use visual studio to build this project with the CMakeLists.txt"
else
    if [[ $1 == "--clean" || $1 == "-c" ]]
    then
	echo "Cleaning build and temporary files" && rm -rf zia build vgcore*; find -name "*~" -type f -delete -or -name "#*#" -type f -delete
    else
	echo "Creating 'build' directory" && mkdir -p build && cd build && echo "Installing conan dependencies" && conan install .. --build=missing && echo "Running cmake" && [[ $1 == "--release" || $1 == "-r" ]] && cmake .. -DCMAKE_BUILD_TYPE=Release -G "Unix Makefiles" || [[ $1 == "--debug" || $1 == "-d" ]] && cmake .. -DCMAKE_BUILD_TYPE=Debug -G "Unix Makefiles" || cmake .. -G "Unix Makefiles" && echo "Building project" && cmake --build .
    fi
fi
