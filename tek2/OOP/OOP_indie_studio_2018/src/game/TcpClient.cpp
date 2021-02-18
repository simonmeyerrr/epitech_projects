/*
** EPITECH PROJECT, 2018
** OOP_indie_studio_2018
** File description:
** TcpClient.cpp
*/

#include <errno.h>
#include <string.h>
#include <iostream>

#include "../utils/milli_sleep.hpp"
#include "../utils/my_sockets.hpp"
#include "TcpClient.hpp"
#include "../Settings.hpp"

TcpClient::~TcpClient()
{
    if (_socket_fd != -1)
        closesocket(_socket_fd);
    #ifdef DEBUG
    std::cout << "DTOR TcpClient " << _address << ":" << _port << " error: "
        << std::boolalpha << _error << std::endl;
    #endif
}

TcpClient::TcpClient(const std::string &address, int port)
    : _error(false), _address(address), _port(port), _socket_fd(-1)
{
    if (init_socket() == -1) {
        #ifdef DEBUG
        std::cerr << "CTOR KO TcpClient " << _address << ":" << _port << " "
            << strerror(errno) << std::endl;
        #endif
        _error = true;
        return;
    }
    #ifdef DEBUG
    std::cout << "CTOR OK TcpClient " << address << ":" << _port << std::endl;
    #endif
}

bool TcpClient::sendMessage(const Action *message)
{
    if (_error || !message)
        return false;

    int ret = send(_socket_fd, (const char *)message, sizeof(Action), 0);

    if (ret != sizeof(Action)) {
        #ifdef DEBUG
        std::cerr << "ERROR TcpClient " << _port << " send" << std::endl;
        #endif
        _error = true;
        return false;
    }
    return true;
}

GameStats *TcpClient::getMessage()
{
    if (_error)
        return nullptr;

    auto game = new GameStats;
    int ret = recv(_socket_fd, (char *)game, sizeof(GameStats), 0);

    if (ret <= 4) {
        _error = true;
        delete game;
        return nullptr;
    } else if (ret != sizeof(GameStats)) {
        my_milli_sleep(50);
        if (game->magic != MAGIC_NUMBER ||
            recv(_socket_fd, &(((char *)game)[ret]), sizeof(GameStats) - ret,
                0) + ret != sizeof(GameStats)) {
            // TODO remove print
            std::cout << "two try get but fail client" << std::endl;
            delete game;
            return nullptr;
        }
    }
    return game;
}

int TcpClient::init_socket()
{
    _socket_fd = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if (_socket_fd == -1)
        return -1;

    struct in_addr inp = {0};
    if (inet_pton(AF_INET, _address.c_str(), &inp) != 1)
        return -1;

    struct sockaddr_in addr = {0, 0, {0}, {0}};
    addr.sin_family = AF_INET;
    addr.sin_port = htons(_port);
    addr.sin_addr.s_addr = inp.s_addr;
    if (connect(_socket_fd, (struct sockaddr *)&addr,
        sizeof(struct sockaddr_in)) == -1)
        return -1;
    return 0;
}
