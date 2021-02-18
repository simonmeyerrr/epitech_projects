/*
** EPITECH PROJECT, 2018
** OOP_indie_studio_2018
** File description:
** my_sockets.hpp
*/

#ifndef OOP_INDIE_STUDIO_2018_MY_SOCKETS_HPP
#define OOP_INDIE_STUDIO_2018_MY_SOCKETS_HPP

#ifdef WIN32

    #include <winsock2.h>
    #include <io.h>
    #include <ws2tcpip.h>
    #pragma comment(lib, "ws2_32.lib")

#else /* not WIN32 */

    #include <unistd.h>
    #include <sys/types.h>
    #include <sys/socket.h>
    #include <netdb.h>
    #include <sys/socket.h>
    #include <netinet/in.h>
    #include <arpa/inet.h>
    #include <ifaddrs.h>

    #define closesocket(socket_fd) close(socket_fd)

#endif /* WIN32 */

#include <fcntl.h>

bool my_set_socket_non_blocking(int socket_fd);

#endif /*OOP_INDIE_STUDIO_2018_MY_SOCKETS_HPP*/
