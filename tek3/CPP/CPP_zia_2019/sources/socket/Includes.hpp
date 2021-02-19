#pragma once

#ifdef WIN32

#define _WINSOCKAPI_

    #define _WINSOCK_DEPRECATED_NO_WARNINGS
    #include <windows.h>
    #include <winsock2.h>
    #include <ws2tcpip.h>
    #include <io.h>
    #include <iostream>
    #include <fstream>
    #include <string>
    #pragma comment(lib, "ws2_32.lib")

#else

    #include <unistd.h>
    #include <fcntl.h>
    #include <sys/types.h>
    #include <sys/socket.h>
    #include <netdb.h>
    #include <netinet/in.h>
    #include <arpa/inet.h>
    #include <ifaddrs.h>

    #define closesocket(fd) close(fd)
    #define SOCKET int

#endif

#define DEFAULT_IP 0x7F000001
