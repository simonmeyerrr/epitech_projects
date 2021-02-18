cmake_minimum_required(VERSION 3.11)
project("CPP_rtype_2019")

# Set c++ version
set(CMAKE_CXX_STANDARD 17)
#add_definitions("-std=c++17")

# Get libraries from conan
include(${PROJECT_SOURCE_DIR}/build/conanbuildinfo.cmake)
conan_basic_setup()

# Path to assets
set(ASSETS_PATH ${CMAKE_SOURCE_DIR}/assets/)

# Build type: Debug, RelWithDebInfo, MinSizeRel or Release
# Debug: print debug messages and use -g for valgrind
# RelWithDebInfo: print debug messages and don't use -g
# Release: no debug message and no -g
if (WIN32)
    set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -DDEBUG")
    set(CMAKE_CXX_FLAGS_RELWITHDEBINFO "${CMAKE_CXX_FLAGS_RELWITHDEBINFO} -DDEBUG")
    set(CMAKE_CXX_FLAGS_MINSIZEREL "${CMAKE_CXX_FLAGS_MINSIZEREL}")
    set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE}")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -DASSETS_PATH=${ASSETS_PATH}")
else (WIN32)
    set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -DDEBUG -g")
    set(CMAKE_CXX_FLAGS_RELWITHDEBINFO "${CMAKE_CXX_FLAGS_RELWITHDEBINFO} -DDEBUG")
    set(CMAKE_CXX_FLAGS_MINSIZEREL "${CMAKE_CXX_FLAGS_MINSIZEREL}")
    set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE}")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -DASSETS_PATH=${ASSETS_PATH} -W -Wall -Wextra -Werror -Wno-unused-variable -Wno-unused-parameter")
endif (WIN32)



# Client
add_executable(r-type_client
        src/client/main.cpp
        src/client/Config.hpp

        src/socket/SocketError.hpp
        src/socket/ISocket.hpp
        src/socket/ASocket.hpp
        src/socket/Utils.hpp
        src/socket/Utils.cpp

        src/socket/socket_c/SocketTCP.cpp
        src/socket/socket_c/SocketTCP.hpp
        src/socket/socket_c/SocketUDP.cpp
        src/socket/socket_c/SocketUDP.hpp
        src/socket/socket_c/Includes.hpp

        src/client/Graphic/Graphic.cpp
        src/client/Graphic/Graphic.hpp

        src/client/ClientGame/IClientGame.hpp
        src/client/ClientGame/AClientGame.hpp
        src/client/ClientGame/MyClientGame.cpp
        src/client/ClientGame/MyClientGame.hpp

        src/client/ClientLauncher/IClientLauncher.hpp
        src/client/ClientLauncher/AClientLauncher.hpp
        src/client/ClientLauncher/MyClientLauncher.cpp
        src/client/ClientLauncher/MyClientLauncher.hpp


        src/client/SFML/Components/IComponent.hpp
        src/client/SFML/Components/AComponent.hpp
        src/client/SFML/Components/Button/Button.cpp
        src/client/SFML/Components/Button/Button.hpp
        src/client/SFML/Components/InputField/InputField.cpp
        src/client/SFML/Components/InputField/InputField.hpp
        src/client/SFML/Components/Rooms/Rooms.cpp
        src/client/SFML/Components/Rooms/Rooms.hpp

        src/client/SFML/Scenes/IScene.hpp
        src/client/SFML/Scenes/AScene.hpp
        src/client/SFML/Scenes/SceneConnected/SceneConnected.cpp
        src/client/SFML/Scenes/SceneConnected/SceneConnected.hpp
        src/client/SFML/Scenes/SceneConnecting/SceneConnecting.cpp
        src/client/SFML/Scenes/SceneConnecting/SceneConnecting.hpp
        src/client/SFML/Scenes/SceneGame/SceneGame.cpp
        src/client/SFML/Scenes/SceneGame/SceneGame.hpp
        src/client/SFML/Components/AComponent.hpp
        src/client/SFML/Components/Rooms/Rooms.cpp
        src/client/SFML/Components/Rooms/Rooms.hpp
        src/client/SFML/Components/Background/Background.cpp
        src/client/SFML/Components/Background/Background.hpp
        src/client/SFML/Scenes/SceneGame/TextureLoader/TextureLoader.cpp
        src/client/SFML/Scenes/SceneGame/TextureLoader/TextureLoader.hpp
        src/client/SFML/Scenes/SceneGame/TextureLoader/GameObjects/IGameObject.hpp
        src/client/SFML/Scenes/SceneGame/TextureLoader/GameObjects/Players/Players.cpp
        src/client/SFML/Scenes/SceneGame/TextureLoader/GameObjects/Players/Players.hpp

        src/ProtocolTCP.hpp
        src/ProtocolUDP.hpp
        src/client/SFML/Scenes/SceneGame/TextureLoader/TextureLoader.cpp
        src/client/SFML/Scenes/SceneGame/TextureLoader/TextureLoader.hpp
        src/client/SFML/Scenes/SceneGame/TextureLoader/GameObjects/IGameObject.hpp
        src/client/SFML/Scenes/SceneGame/TextureLoader/GameObjects/Players/Players.cpp
        src/client/SFML/Scenes/SceneGame/TextureLoader/GameObjects/Players/Players.hpp
        src/client/SFML/Scenes/SceneGame/TextureLoader/GameObjects/Rocket/Rocket.cpp
        src/client/SFML/Scenes/SceneGame/TextureLoader/GameObjects/Rocket/Rocket.hpp
        src/client/SFML/Scenes/SceneGame/TextureLoader/GameObjects/Monsters/LowMonsters.cpp
        src/client/SFML/Scenes/SceneGame/TextureLoader/GameObjects/Monsters/LowMonsters.hpp
        src/client/SFML/Scenes/SceneGame/TextureLoader/GameObjects/Monsters/FastMonster.cpp src/client/SFML/Scenes/SceneGame/TextureLoader/GameObjects/Monsters/FastMonster.hpp)

if (WIN32)
    target_link_libraries(r-type_client ${CONAN_LIBS})
else (WIN32)
    #target_link_libraries(r-type_client pthread -lsfml-graphics -lsfml-window -lsfml-system)
    target_link_libraries(r-type_client pthread ${CONAN_LIBS})
endif (WIN32)

# Server
add_executable(r-type_server
        src/server/main.cpp

        src/server/core/Core.cpp
        src/server/core/Core.hpp

        src/socket/SocketError.hpp
        src/socket/ASocket.hpp
        src/socket/IServer.hpp
        src/socket/AServerTCP.hpp
        src/socket/AServerUDP.hpp

        src/socket/Utils.hpp
        src/socket/Utils.cpp

        src/socket/socket_c/SocketTCP.cpp
        src/socket/socket_c/SocketTCP.hpp
        src/socket/socket_c/SocketUDP.cpp
        src/socket/socket_c/SocketUDP.hpp
        src/socket/socket_c/ServerUDP.cpp
        src/socket/socket_c/ServerUDP.hpp
        src/socket/socket_c/ServerTCP.cpp
        src/socket/socket_c/ServerTCP.hpp
        src/socket/AServerTCP.hpp
        src/socket/AServerUDP.hpp

        src/socket/socket_c/ServerTCP.cpp
        src/socket/socket_c/ServerTCP.hpp
        src/socket/socket_c/ServerUDP.cpp
        src/socket/socket_c/ServerUDP.hpp

        src/server/BackEndGame.cpp
        src/server/BackEndGame.hpp
        src/server/BackEndLauncher.cpp
        src/server/BackEndLauncher.hpp
        src/server/User.cpp
        src/server/User.hpp
        src/server/GameRoom.cpp
        src/server/GameRoom.hpp

        src/LibLoader.hpp

        src/server/BackEndGame.cpp
        src/server/BackEndGame.cpp
        src/server/BackEndLauncher.cpp
        src/server/BackEndLauncher.cpp

        src/ProtocolTCP.hpp
        src/ProtocolUDP.hpp

        src/server/core/Entities/IEntity.hpp
        src/server/core/Entities/AEntity.hpp
        src/server/core/Entities/FriendShots.cpp
        src/server/core/Entities/FriendShots.hpp
        src/server/core/Entities/Player.cpp
        src/server/core/Entities/Player.hpp
        src/Utils/Vector2s.hpp
        )

# Libs
SET(MonsterSRCS
        src/server/core/Entities/IEntity.hpp
        src/server/core/Entities/AEntity.hpp
        src/Utils/Vector2s.hpp
        )

ADD_LIBRARY(SlowMonster MODULE ${MonsterSRCS} src/monsters/SlowMonster.cpp  src/monsters/SlowMonster.hpp)
ADD_LIBRARY(FastMonster MODULE ${MonsterSRCS} src/monsters/FastMonster.cpp src/monsters/FastMonster.hpp)

if (WIN32)
    target_link_libraries(r-type_server)
else (WIN32)
    target_link_libraries(r-type_server pthread dl stdc++fs)
endif (WIN32)

# Copy executables
add_custom_command(TARGET r-type_client POST_BUILD
    COMMAND ${CMAKE_COMMAND}
    ARGS -E copy $<TARGET_FILE:r-type_client> ${CMAKE_SOURCE_DIR}/)
add_custom_command(TARGET r-type_server POST_BUILD
    COMMAND ${CMAKE_COMMAND}
    ARGS -E copy $<TARGET_FILE:r-type_server> ${CMAKE_SOURCE_DIR}/)

# Copy libraries
file(MAKE_DIRECTORY ${CMAKE_SOURCE_DIR}/lib)
add_custom_command(TARGET SlowMonster POST_BUILD
    COMMAND ${CMAKE_COMMAND}
    ARGS -E copy $<TARGET_FILE:SlowMonster> ${CMAKE_SOURCE_DIR}/lib/)
add_custom_command(TARGET FastMonster POST_BUILD
    COMMAND ${CMAKE_COMMAND}
    ARGS -E copy $<TARGET_FILE:FastMonster> ${CMAKE_SOURCE_DIR}/lib/)