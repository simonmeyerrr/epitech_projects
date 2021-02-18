#include <cstring>
#include <iostream>
#include "User.hpp"
#include "../ProtocolTCP.hpp"

User::~User()
{
#ifdef DEBUG
    std::cout << "[-] CONNECTION " << _socket->getId() << std::endl;
#endif
}

User::User(my_socket::ISocketPtr &socket)
    : _socket(socket), _username(""), _connected(false), _room(-1)
{
#ifdef DEBUG
    std::cout << "[+] CONNECTION " << _socket->getId() << std::endl;
#endif
}

std::pair<int, my_socket::Buffer> User::getRequest()
{
    ProtocolTCP::Request req = {0, ProtocolTCP::INVALID, 0};
    my_socket::Buffer data(0, 0);
    auto header = _socket->recv(sizeof(ProtocolTCP::Request));

    if (header.size() != sizeof(ProtocolTCP::Request))
        return {ProtocolTCP::INVALID, data};
    std::memcpy(&req, header.data(), sizeof(ProtocolTCP::Request));

    if (req.magic != MAGIC_NUMBER)
        return {ProtocolTCP::INVALID, data};

    if (req.data_size != 0) {
        data = _socket->recv(req.data_size);
        if (data.size() != req.data_size) {
            return {ProtocolTCP::INVALID, data};
        }
    }
    if (req.action <= ProtocolTCP::INVALID || req.action >= ProtocolTCP::LAST_TYPE)
        return {ProtocolTCP::INVALID, data};
    return {req.action, data};
}

void User::respond(bool ok, const my_socket::Buffer &data)
{
    ProtocolTCP::Response header = {MAGIC_NUMBER, ok, static_cast<unsigned int>(data.size())};
    my_socket::Buffer res(sizeof(ProtocolTCP::Response) + data.size(), 0);

    std::memcpy(res.data(), &header, sizeof(ProtocolTCP::Response));
    std::memcpy(res.data() + sizeof(ProtocolTCP::Response), data.data(), data.size());
    _socket->send(res);
}

void User::setConnection(bool connected, const std::string &username)
{
    _connected = connected;
    _username = username;
#ifdef DEBUG
    std::cout << "USER " << _username << " is now connected" << std::endl;
#endif
}

void User::setRoom(int room)
{
#ifdef DEBUG
    if (room == -1)
        std::cout << "USER " <<  _username << " leaved room " << _room << std::endl;
    else
        std::cout << "USER " <<  _username << " joined room " << room << std::endl;
#endif
    _room = room;
}