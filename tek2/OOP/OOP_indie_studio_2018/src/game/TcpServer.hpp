/*
** EPITECH PROJECT, 2018
** OOP_indie_studio_2018
** File description:
** Server.hpp
*/

#ifndef OOP_INDIE_STUDIO_2018_TCPSERVER_HPP
    #define OOP_INDIE_STUDIO_2018_TCPSERVER_HPP

#include <deque>
#include <thread>
#include "Structures.hpp"

class TcpServer {
public:
    ~TcpServer();
    explicit TcpServer(int port);

    bool hasError() const {return _error;}
    int getPort() const {return _port;}
    bool isConnected() const {return _client_fd != -1;}

    bool sendMessage(const GameStats *game);
    Action *getMessage();

private:
    int init_socket();
    void loop_accept();

    bool _error;
    int _port;
    int _socket_fd;
    int _client_fd;
    std::deque<std::thread> _threads;
};

using TcpServerPtr = std::unique_ptr<TcpServer>;

#endif /*OOP_INDIE_STUDIO_2018_TCPSERVER_HPP*/
