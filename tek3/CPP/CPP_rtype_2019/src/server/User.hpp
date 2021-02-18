#ifndef CPP_RTYPE_2019_USER_HPP
#define CPP_RTYPE_2019_USER_HPP

#include <memory>
#include "../socket/ISocket.hpp"

class User {
public:
    ~User();
    User(my_socket::ISocketPtr &socket);

    int getId() const {return _socket->getId();}
    bool isConnected() const {return _connected;}
    std::string getUsername() const {return _username;}
    int getRoom() const {return _room;}

    std::pair<int, my_socket::Buffer> getRequest();
    void respond(bool ok, const my_socket::Buffer &data);

    void setConnection(bool connected, const std::string &username);
    void setRoom(int room);

private:
    my_socket::ISocketPtr &_socket;
    std::string _username;
    bool _connected;
    int _room;
};

using UserPtr = std::unique_ptr<User>;

#endif /* CPP_RTYPE_2019_USER_HPP */
