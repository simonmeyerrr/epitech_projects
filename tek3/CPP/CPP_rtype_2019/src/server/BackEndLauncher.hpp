#ifndef CPP_RTYPE_2019_BACKENDLAUNCHER_HPP
#define CPP_RTYPE_2019_BACKENDLAUNCHER_HPP

#include <map>
#include <cstring>
#include "../socket/AServerTCP.hpp"
#include "User.hpp"
#include "GameRoom.hpp"

class BackEndLauncher : public my_socket::IBackEndTCP {
public:
    ~BackEndLauncher() override = default;
    BackEndLauncher(my_socket::Port port);

    bool addConnection(my_socket::ISocketPtr &socket) final;
    bool communicate(my_socket::ISocketPtr &socket) final;
    void closeConnection(my_socket::ISocketPtr &socket) final;

private:
    bool actionPing(UserPtr &user, const my_socket::Buffer &buffer);
    bool actionConnect(UserPtr &user, const my_socket::Buffer &buffer);
    bool actionGetRooms(UserPtr &user, const my_socket::Buffer &buffer);
    bool actionCreateRoom(UserPtr &user, const my_socket::Buffer &buffer);
    bool actionJoinRoom(UserPtr &user, const my_socket::Buffer &buffer);
    bool actionLeaveRoom(UserPtr &user, const my_socket::Buffer &buffer);
    bool actionStartGame(UserPtr &user, const my_socket::Buffer &buffer);

    int createRoom(const std::string &name, int userId, const std::string &username);
    bool leaveRoom(UserPtr &user);

    my_socket::Port _port;
    std::map<int, UserPtr> _users;
    int _roomsId;
    std::map<int, GameRoomPtr> _rooms;

    using ActionFunction = bool (BackEndLauncher::*)(UserPtr &, const my_socket::Buffer &);
};


#endif /*CPP_RTYPE_2019_BACKENDLAUNCHER_HPP*/
