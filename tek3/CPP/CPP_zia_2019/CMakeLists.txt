cmake_minimum_required(VERSION 3.11)
project("CPP_zia_2019")

# Set c++ version
set(CMAKE_CXX_STANDARD 17)

# Get libraries from conan
include(${PROJECT_SOURCE_DIR}/build/conanbuildinfo.cmake)
conan_basic_setup()

if (WIN32)
else ()
    #find_package(Threads REQUIRED)
    #set(SFML_STATIC_LIBRARIES FALSE)
    #find_package(SFML 2.5.1 REQUIRED COMPONENTS audio graphics window system)

    #if(NOT Threads_FOUND OR NOT SFML_FOUND)
    #  message(FATAL_ERROR "Couldn't find all dependencies :/")
    #endif()
endif ()

# Build type: Debug, RelWithDebInfo, MinSizeRel or Release
# Debug: print debug messages and use -g for valgrind
# RelWithDebInfo: print debug messages and don't use -g
# Release: no debug message and no -g
if (WIN32)
    set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -DDEBUG")
    set(CMAKE_CXX_FLAGS_RELWITHDEBINFO "${CMAKE_CXX_FLAGS_RELWITHDEBINFO} -DDEBUG")
    set(CMAKE_CXX_FLAGS_MINSIZEREL "${CMAKE_CXX_FLAGS_MINSIZEREL}")
    set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE}")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}")
else (WIN32)
    set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -DDEBUG -g")
    set(CMAKE_CXX_FLAGS_RELWITHDEBINFO "${CMAKE_CXX_FLAGS_RELWITHDEBINFO} -DDEBUG")
    set(CMAKE_CXX_FLAGS_MINSIZEREL "${CMAKE_CXX_FLAGS_MINSIZEREL}")
    set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE}")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -W -Wall -Wextra -Wfatal-errors -Wpedantic -ansi -Wno-unused-variable -Wno-unused-parameter")
endif (WIN32)

# Set output path
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR})
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_RELEASE ${CMAKE_SOURCE_DIR})
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_RELWITHDEBINFO ${CMAKE_SOURCE_DIR})
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_MINSIZEREL ${CMAKE_SOURCE_DIR})
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_DEBUG ${CMAKE_SOURCE_DIR})
file(MAKE_DIRECTORY ${CMAKE_SOURCE_DIR}/modules)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/modules)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY_RELEASE ${CMAKE_SOURCE_DIR}/modules)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY_RELWITHDEBINFO ${CMAKE_SOURCE_DIR}/modules)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY_MINSIZEREL ${CMAKE_SOURCE_DIR}/modules)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY_DEBUG ${CMAKE_SOURCE_DIR}/modules)

# Set includes directories
include_directories(sources/api/sources sources/tools sources/jsonparser sources/api/sources/module)

# API Headers
SET(API_HEADERS
        sources/api/sources/Types.hpp

        sources/api/sources/http/IMessage.hpp
        sources/api/sources/http/IRequest.hpp
        sources/api/sources/http/IResponse.hpp
        sources/api/sources/http/ISocket.hpp

        sources/api/sources/module/IModule.hpp
        sources/api/sources/module/ALogger.hpp
        sources/api/sources/module/ANetwork.hpp
        sources/api/sources/module/AHttp.hpp)

SET(JSON_SOURCES
        sources/jsonparser/JsonBuilder.cpp
        sources/jsonparser/JsonModifier.cpp
        sources/jsonparser/JsonPrinter.cpp
        sources/jsonparser/JsonWorker.cpp)

SET(SOCKET_SOURCES
        sources/socket/Includes.hpp
        sources/socket/SocketTCP.cpp
        sources/socket/SocketTCP.hpp
        sources/socket/MyRequest.hpp
        sources/socket/MyResponse.hpp)

SET(LIBLOADER_SOURCES
        sources/libloader/ILibLoader.hpp
        sources/libloader/LibLoader.hpp
        sources/libloader/DllLoader.hpp
        sources/libloader/ModuleLoader.cpp
        sources/libloader/ModuleLoader.hpp)

set(TLS_SRC
        sources/tools/Mutex.cpp
        sources/tools/Mutex.hpp
        sources/tools/SharedMutex.cpp
        sources/tools/SharedMutex.hpp
        sources/tools/Atomic.hpp
        sources/tools/ModuleLoggable.hpp)

# Binary
add_executable(zia
        sources/core/Main.cpp

        sources/core/Core.cpp
        sources/core/Core.hpp
        sources/core/Errors.cpp
        sources/core/IError.cpp
        sources/core/ModulesManager.cpp
        sources/core/ModulesManager.hpp
        ${TLS_SRC}
        ${API_HEADERS}
        ${LIBLOADER_SOURCES}
        ${JSON_SOURCES}
        )

if (WIN32)
    target_link_libraries(zia ${CONAN_LIBS})
else (WIN32)
    target_link_libraries(zia pthread dl ${CONAN_LIBS})
endif (WIN32)

## Modules
ADD_LIBRARY(NotSecureNetwork MODULE
        sources/modules/NotSecureNetwork/NotSecureNetwork.cpp
        sources/modules/NotSecureNetwork/NotSecureNetwork.hpp
        ${API_HEADERS} ${SOCKET_SOURCES} ${TLS_SRC})

ADD_LIBRARY(SecureNetwork MODULE
        sources/modules/SecureNetwork/SecureNetwork.cpp
        sources/modules/SecureNetwork/SecureNetwork.hpp
        sources/socket/SecureSocket.cpp
        sources/socket/SecureSocket.hpp
        ${API_HEADERS} ${SOCKET_SOURCES} ${TLS_SRC})
target_link_libraries(SecureNetwork ${CONAN_LIBS})

ADD_LIBRARY(HttpReceiver MODULE
        sources/modules/HttpReceiver/HttpReceiver.cpp
        sources/modules/HttpReceiver/HttpReceiver.hpp
        ${API_HEADERS} ${TLS_SRC})

ADD_LIBRARY(HttpSender MODULE
        sources/modules/HttpSender/HttpSender.cpp
        sources/modules/HttpSender/HttpSender.hpp
        ${API_HEADERS} ${TLS_SRC})

ADD_LIBRARY(PhpCgi MODULE
        sources/modules/PhpCgi/PhpCgi.cpp
        sources/modules/PhpCgi/PhpCgi.hpp
        ${API_HEADERS} ${SOCKET_SOURCES} ${TLS_SRC})

ADD_LIBRARY(FileServer MODULE
        sources/modules/FileServer/FileServer.cpp
        sources/modules/FileServer/FileServer.hpp
        ${API_HEADERS} ${TLS_SRC})

ADD_LIBRARY(ConsoleLogger MODULE
        sources/modules/ConsoleLogger/ConsoleLogger.cpp
        sources/modules/ConsoleLogger/ConsoleLogger.hpp
        ${API_HEADERS} ${TLS_SRC})


#if (SFML_FOUND)
    ADD_LIBRARY(Snek MODULE
            sources/modules/Snek/Snek.cpp
            sources/modules/Snek/Snek.hpp
            ${API_HEADERS} ${TLS_SRC})

    target_include_directories(Snek PUBLIC ${SFML_INCLUDE_DIRS})
    target_link_libraries(Snek PUBLIC ${SFML_LIBRARIES} ${SFML_DEPENDENCIES} ${CMAKE_THREAD_LIBS_INIT} sfml-graphics sfml-audio sfml-window sfml-system)
#endif ()

