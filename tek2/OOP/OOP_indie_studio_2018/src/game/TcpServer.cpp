/*
** EPITECH PROJECT, 2018
** OOP_indie_studio_2018
** File description:
** Server.cpp
*/

#include <errno.h>
#include <string.h>
#include <iostream>

#include "../utils/my_sockets.hpp"
#include "../utils/milli_sleep.hpp"
#include "TcpServer.hpp"

TcpServer::~TcpServer()
{
    bool last_error = _error;

    _error = true;
    if (_client_fd != -1)
        closesocket(_client_fd);
    if (_socket_fd != -1)
        closesocket(_socket_fd);
    for (auto &thread: _threads)
        thread.join();
    #ifdef DEBUG
    std::cout << "DTOR TcpServer :" << _port << " error: " << std::boolalpha
        << last_error << std::endl;
    #endif
}

TcpServer::TcpServer(int port)
    : _error(false), _port(port), _socket_fd(-1), _client_fd(-1)
{
    if (init_socket() == -1) {
        #ifdef DEBUG
        std::cerr << "CTOR KO TcpServer :" << _port << " " << strerror(errno)
            << std::endl;
        #endif
        _error = true;
        return;
    }
    _threads.emplace_back(std::thread(&TcpServer::loop_accept, this));
    #ifdef DEBUG
    std::cout << "CTOR OK TcpServer :" << _port << std::endl;
    #endif
}

bool TcpServer::sendMessage(const GameStats *game)
{
    if (_socket_fd == -1 || _client_fd == -1)
        return false;

    int ret = send(_client_fd, (const char *)game, sizeof(GameStats), 0);
    if (ret != sizeof(GameStats)) {
        #ifdef DEBUG
        std::cerr << "ERROR TcpServer " << _port << " send" << std::endl;
        #endif
        closesocket(_client_fd);
        _client_fd = -1;
        return false;
    }
    return true;
}

Action *TcpServer::getMessage()
{
    if (_error || _socket_fd == -1 || _client_fd == -1)
        return nullptr;

    auto action = new Action;
    int ret = recv(_client_fd, (char *)action, sizeof(Action), 0);

    if (ret <= 4) {
        if (ret == 0) {
            #ifdef DEBUG
            std::cerr << "ERROR TcpServer " << _port << " deconnected"
                << std::endl;
            #endif
            closesocket(_client_fd);
            _client_fd = -1;
        }
        delete action;
        return nullptr;
    } else if (ret != sizeof(Action)) {
        my_milli_sleep(5);
        if (action->magic != MAGIC_NUMBER ||
            recv(_socket_fd, &(((char *)action)[ret]), sizeof(Action) - ret,
                0) + ret != sizeof(Action)) {
            // TODO remove print
            std::cout << "two try get but fail server" << std::endl;
            delete action;
            return nullptr;
        }
    }
    return action;
}

int TcpServer::init_socket()
{
    _socket_fd = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if (_socket_fd == -1)
        return -1;

    if (!my_set_socket_non_blocking(_socket_fd))
        return -1;
    struct sockaddr_in addr = {0, 0, {0}, {0}};
    addr.sin_family = AF_INET;
    addr.sin_port = htons(_port);
    addr.sin_addr.s_addr = INADDR_ANY;
    if (bind(_socket_fd, (struct sockaddr *)&addr, sizeof(addr)) == -1)
        return -1;
    if (listen(_socket_fd, 1) == -1)
        return -1;
    return 0;
}

void TcpServer::loop_accept()
{
    while (!_error) {
        int new_fd = accept(_socket_fd, nullptr, nullptr);
        if (new_fd != -1 && _client_fd == -1) {
            #ifdef DEBUG
            std::cout << "TcpServer accepted on :" << _port << std::endl;
            #endif
            if (!my_set_socket_non_blocking(new_fd))
                closesocket(new_fd);
            else
                _client_fd = new_fd;
        } else if (new_fd != -1) {
            #ifdef DEBUG
            std::cout << "TcpServer accepted but not needed on :" << _port
                << std::endl;
            #endif
            closesocket(new_fd);
        }
    }
}