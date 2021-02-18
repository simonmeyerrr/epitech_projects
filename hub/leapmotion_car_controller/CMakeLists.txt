cmake_minimum_required(VERSION 3.11)
project("leapmotion_car_controller")

# Library required

# Build type: Debug, RelWithDebInfo, MinSizeRel or Release
# Debug: print debug messages and use -g for valgrind
# RelWithDebInfo: print debug messages and don't use -g
# Release: no debug message and no -g
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -DDEBUG -g")
set(CMAKE_CXX_FLAGS_RELWITHDEBINFO "${CMAKE_CXX_FLAGS_RELWITHDEBINFO} -DDEBUG")
set(CMAKE_CXX_FLAGS_MINSIZEREL "${CMAKE_CXX_FLAGS_MINSIZEREL}")
set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE}")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -W -Wall -Wextra -Werror -Wno-unused-variable -Wno-unused-parameter")

find_package(Threads REQUIRED)
include_directories(lib)
add_library(sumo
        lib/decode.cpp
        lib/control.cpp
        lib/common.cpp
        lib/realtime.cpp
        lib/image.cpp
        )
target_link_libraries(sumo ${CMAKE_THREAD_LIBS_INIT})

if(UNIX AND NOT APPLE)
    find_library(RT rt)
    target_link_libraries(sumo ${RT})
endif()

# Babel server
add_executable(leapmotion_car_controller
        src/main.cpp

        src/Sfml.cpp
        src/Sfml.hpp
        src/LeapMotion.cpp
        src/LeapMotion.hpp
        src/Drone.cpp
        src/Drone.hpp
        src/MyListener.cpp
        src/MyListener.hpp
        )

# Link libraries
target_link_libraries(leapmotion_car_controller Leap sumo sfml-system sfml-window sfml-graphics)

# Copy executable
add_custom_command(TARGET leapmotion_car_controller POST_BUILD
            COMMAND ${CMAKE_COMMAND}
            ARGS -E copy leapmotion_car_controller ${CMAKE_SOURCE_DIR}/)
