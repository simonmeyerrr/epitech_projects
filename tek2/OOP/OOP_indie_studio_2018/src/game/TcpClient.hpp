/*
** EPITECH PROJECT, 2018
** OOP_indie_studio_2018
** File description:
** TcpClient.hpp
*/

#ifndef OOP_INDIE_STUDIO_2018_TCPCLIENT_HPP
#define OOP_INDIE_STUDIO_2018_TCPCLIENT_HPP

#include <memory>
#include <string>
#include "Structures.hpp"

class TcpClient {
public:
    ~TcpClient();
    TcpClient(const std::string &address, int port);

    bool hasError() const {return _error;}
    int getPort() const {return _port;}

    bool sendMessage(const Action *message);
    GameStats *getMessage();

private:
    int init_socket();

    bool _error;
    std::string _address;
    int _port;
    int _socket_fd;
};

using TcpClientPtr = std::unique_ptr<TcpClient>;

#endif /* OOP_INDIE_STUDIO_2018_TCPCLIENT_HPP */
