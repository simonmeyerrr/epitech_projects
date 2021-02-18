cmake_minimum_required(VERSION 3.11)
project("OOP_indie_studio_2018")
set(CMAKE_CXX_STANDARD 11)

# Call cmake files
set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake" ${CMAKE_MODULE_PATH})
# Set executable output path
if (WIN32)
    set(EXECUTABLE_OUTPUT_PATH ${CMAKE_SOURCE_DIR})
endif ()
# Set include directory
include_directories(${CMAKE_SOURCE_DIR}/include)

# Link libaries directories for Windows, MacOsX or Linux
# No way found to differenciate 32 and 64 for MacOsX and Linux...
if (WIN32)
    if (CMAKE_CL_64)
        link_directories(${CMAKE_SOURCE_DIR}/libs/win64)
    else (CMAKE_CL_64)
        link_directories(${CMAKE_SOURCE_DIR}/libs/win32)
    endif (CMAKE_CL_64)
endif (WIN32)

# Path to assets
set(ASSETS_PATH ${CMAKE_SOURCE_DIR}/assets/)

# Build type: Debug, RelWithDebInfo, MinSizeRel or Release
# Debug: print debug messages and use -g for valgrind
# RelWithDebInfo: print debug messages and don't use -g
# Release: no debug message and no -g
if (WIN32)
    set(CMAKE_CXX_FLAGS_DEBUG "-DDEBUG")
    set(CMAKE_CXX_FLAGS_RELWITHDEBINFO "-DDEBUG")
    set(CMAKE_CXX_FLAGS_MINSIZEREL "")
    set(CMAKE_CXX_FLAGS_RELEASE "")
    set(CMAKE_CXX_FLAGS "-DASSETS_PATH=${ASSETS_PATH} -DWIN32 -EHsc")
else (WIN32)
    set(CMAKE_CXX_FLAGS_DEBUG "-DDEBUG -g")
    set(CMAKE_CXX_FLAGS_RELWITHDEBINFO "-DDEBUG")
    set(CMAKE_CXX_FLAGS_MINSIZEREL "")
    set(CMAKE_CXX_FLAGS_RELEASE "")
    set(CMAKE_CXX_FLAGS "-DASSETS_PATH=${ASSETS_PATH} -W -Wall -Wextra -Werror -Wno-unused-variable -Wno-unused-parameter -Wno-deprecated -Wno-deprecated-copy")
endif (WIN32)

# Create executable
add_executable(bomberman
        assets/icon.rc
        src/mains/MainBomberman.cpp

        src/IndieStudio.cpp
        src/IndieStudio.hpp
        src/Settings.cpp
        src/Settings.hpp
        src/audio/Audio.cpp
        src/audio/Audio.hpp

        include/Config.hpp
        include/Structures.hpp
        include/Enums.hpp
        include/Consts.hpp

        src/irrlicht/IrrlichtDevice.cpp
        src/irrlicht/IrrlichtDevice.hpp
        src/irrlicht/ResponsiveGui.cpp
        src/irrlicht/ResponsiveGui.hpp
        src/irrlicht/MyEventReceiver.cpp
        src/irrlicht/MyEventReceiver.hpp

        src/scene/AScene.hpp
        src/scene/IScene.hpp
        src/scene/SceneType.hpp
        src/scene/SceneFactory.hpp

        src/scene/scenes/SceneSplashScreen.cpp
        src/scene/scenes/SceneSplashScreen.hpp
        src/scene/scenes/SceneIntroduction.cpp
        src/scene/scenes/SceneIntroduction.hpp
        src/scene/scenes/SceneMainMenu.cpp
        src/scene/scenes/SceneMainMenu.hpp
        src/scene/scenes/SceneCreateGame.cpp
        src/scene/scenes/SceneCreateGame.hpp
        src/scene/scenes/SceneJoinGame.cpp
        src/scene/scenes/SceneJoinGame.hpp
        src/scene/scenes/SceneInGame.cpp
        src/scene/scenes/SceneInGame.hpp
        src/scene/scenes/SceneSettings.cpp
        src/scene/scenes/SceneKeySettings.cpp
        src/scene/scenes/SceneKeySettings.hpp
		src/scene/scenes/SceneCredit.cpp
		src/scene/scenes/SceneCredit.hpp
        src/scene/scenes/SceneIntroductionAnim.cpp
		src/scene/scenes/SceneIntroductionAnim.hpp

        src/game/TcpServer.cpp
        src/game/TcpServer.hpp
        src/game/TcpClient.cpp
        src/game/TcpClient.hpp
        src/game/GameBack.cpp
        src/game/GameBack.hpp
        src/game/GameStatsContainer.cpp
        src/game/GameStatsContainer.hpp
        src/game/Map.cpp
        src/game/Map.hpp
		src/game/IntroAnimBack.cpp
		src/game/IntroAnimBack.hpp

        src/game/player/Player.hpp
        src/game/player/Player.cpp
        src/game/player/AiPlayer.cpp
        src/game/player/AiPlayer.hpp

        src/game/display/DisplayGame.cpp
        src/game/display/DisplayGame.hpp
        src/game/display/DisplayDecor.cpp
        src/game/display/DisplayDecor.hpp
        src/game/display/DisplayMap.cpp
        src/game/display/DisplayMap.hpp
        src/game/display/DisplayPlayer.cpp
        src/game/display/DisplayPlayer.hpp
        src/game/display/DisplayOverlay.cpp
        src/game/display/DisplayOverlay.hpp
		src/game/display/DisplayPlayerAnim.cpp
		src/game/display/DisplayPlayerAnim.hpp
		src/game/display/DisplayDecorAnim.cpp
		src/game/display/DisplayDecorAnim.hpp

        src/utils/milli_sleep.cpp
        src/utils/milli_sleep.hpp
        src/utils/my_sockets.cpp
        src/utils/my_sockets.hpp src/game/player/IPlayer.hpp)

# Find library package
find_package(Irrlicht 1.8.4 REQUIRED)
find_package(SFML 2.4 REQUIRED)

# Link external libaries to executable
if (UNIX)
    target_link_libraries(bomberman
            Irrlicht sfml-audio sfml-system
            GL Xxf86vm X11
            pthread)
else (UNIX)
    target_link_libraries(bomberman
            Irrlicht sfml-audio sfml-system)
endif (UNIX)


# Copy ddls if windows, else copy executable
if (WIN32)
    set(DLLS_FILES Irrlicht.dll openal32.dll sfml-audio-2.dll sfml-system-2.dll)
    if (CMAKE_CL_64)
        set(DLLS_PATH ${CMAKE_SOURCE_DIR}/libs/win64/)
    else (CMAKE_CL_64)
        set(DLLS_PATH ${CMAKE_SOURCE_DIR}/libs/win32/)
    endif (CMAKE_CL_64)
    foreach (file_i ${DLLS_FILES})
        add_custom_command(TARGET bomberman POST_BUILD
                COMMAND ${CMAKE_COMMAND}
                ARGS -E copy ${DLLS_PATH}${file_i} ${CMAKE_SOURCE_DIR}/)
    endforeach (file_i)
else (WIN32)
    add_custom_command(TARGET bomberman POST_BUILD
            COMMAND ${CMAKE_COMMAND}
            ARGS -E copy bomberman ${CMAKE_SOURCE_DIR}/)
endif (WIN32)