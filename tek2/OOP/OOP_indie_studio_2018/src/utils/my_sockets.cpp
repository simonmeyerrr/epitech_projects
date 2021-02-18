/*
** EPITECH PROJECT, 2018
** OOP_indie_studio_2018
** File description:
** my_sockets.cpp
*/

#include "my_sockets.hpp"

bool my_set_socket_non_blocking(int socket_fd)
{
    #ifdef WIN32
    u_long iMode = 1; // 0: blocking, else: non-blocking
    if (ioctlsocket(socket_fd, FIONBIO, &iMode) == -1)
        return false;
    #else /* not WIN32 */
    int flags = fcntl(socket_fd, F_GETFL);
    if (flags == -1)
        return false;
    if (fcntl(socket_fd, F_SETFL, flags | O_NONBLOCK) == -1)
        return false;
    #endif /* WIN32 */
    return true;
}