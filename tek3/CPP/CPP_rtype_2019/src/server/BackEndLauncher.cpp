#include <iostream>
#include <memory>
#include "BackEndLauncher.hpp"
#include "../ProtocolTCP.hpp"

BackEndLauncher::BackEndLauncher(my_socket::Port port)
    : _port(port), _users(), _roomsId(1), _rooms()
{
}

bool BackEndLauncher::addConnection(my_socket::ISocketPtr &socket)
{
    try {
        _users.insert(std::make_pair(socket->getId(), std::make_unique<User>(socket)));
        return true;
    } catch (...) {
        return false;
    }
}

bool BackEndLauncher::communicate(my_socket::ISocketPtr &socket)
{
    auto &user = _users.at(socket->getId());
    auto request = user->getRequest();
    ProtocolTCP::Action actions[7] = {ProtocolTCP::PING, ProtocolTCP::CONNECT, ProtocolTCP::GET_ROOMS,
                                      ProtocolTCP::CREATE_ROOM, ProtocolTCP::JOIN_ROOM,
                                      ProtocolTCP::LEAVE_ROOM, ProtocolTCP::START_GAME};
    ActionFunction funcs[7] = {&BackEndLauncher::actionPing, &BackEndLauncher::actionConnect, &BackEndLauncher::actionGetRooms,
                               &BackEndLauncher::actionCreateRoom, &BackEndLauncher::actionJoinRoom,
                               &BackEndLauncher::actionLeaveRoom, &BackEndLauncher::actionStartGame};

    for (int i = 0; i < 7; i++) {
        if (request.first == actions[i])
            return (this->*funcs[i])(user, request.second);
    }
    user->respond(false, ProtocolTCP::strToBuffer("INVALID ACTION"));
    return true;
}

void BackEndLauncher::closeConnection(my_socket::ISocketPtr &socket)
{
    try {
        auto &user = _users.at(socket->getId());
        leaveRoom(user);
        _users.erase(socket->getId());
    } catch (...) {}
}

bool BackEndLauncher::actionPing(UserPtr &user, const my_socket::Buffer &buffer)
{
    user->respond(true, ProtocolTCP::strToBuffer("PONG"));
    return true;
}

bool BackEndLauncher::actionConnect(UserPtr &user, const my_socket::Buffer &buffer)
{
    auto body = ProtocolTCP::getBody<ProtocolTCP::RequestConnectData>(buffer);
    ProtocolTCP::ResponseConnectData response;

    if (user->isConnected()) {
        user->respond(false, ProtocolTCP::strToBuffer("ALREADY CONNECTED"));
        return true;
    } else if (!body.first) {
        user->respond(false, ProtocolTCP::strToBuffer("INVALID DATA SIZE"));
        return true;
    } else if (!ProtocolTCP::isTabValid(body.second.username)) {
        user->respond(false, ProtocolTCP::strToBuffer("INVALID USERNAME"));
        return true;
    }
    user->setConnection(true, ProtocolTCP::tabToStr(body.second.username));
    response.id = user->getId();
    user->respond(true, ProtocolTCP::setBody(response));
    return true;
}

bool BackEndLauncher::actionGetRooms(UserPtr &user, const my_socket::Buffer &buffer)
{
    auto body = ProtocolTCP::getBody<ProtocolTCP::DummyData>(buffer);

    if (!user->isConnected()) {
        user->respond(false, ProtocolTCP::strToBuffer("NOT CONNECTED"));
        return true;
    } else if (!body.first) {
        user->respond(false, ProtocolTCP::strToBuffer("INVALID DATA SIZE"));
        return true;
    }
    int id = user->getId();
    ProtocolTCP::Rooms rooms;
    for (auto & _room : _rooms)
        rooms.push_back(_room.second->getRoomInfo(id));
    my_socket::Buffer response(sizeof(ProtocolTCP::Room) * rooms.size(), 0);
    std::memcpy(response.data(), rooms.data(), sizeof(ProtocolTCP::Room) * rooms.size());
    user->respond(true, response);
    return true;
}

bool BackEndLauncher::actionCreateRoom(UserPtr &user, const my_socket::Buffer &buffer)
{
    auto body = ProtocolTCP::getBody<ProtocolTCP::RequestCreateRoomData>(buffer);
    ProtocolTCP::ResponseCreateRoomData response;

    if (!user->isConnected()) {
        user->respond(false, ProtocolTCP::strToBuffer("NOT CONNECTED"));
        return true;
    } else if (user->getRoom() != -1) {
        user->respond(false, ProtocolTCP::strToBuffer("ALREADY IN A ROOM"));
        return true;
    } else if (!body.first) {
        user->respond(false, ProtocolTCP::strToBuffer("INVALID DATA SIZE"));
        return true;
    } else if (!ProtocolTCP::isTabValid(body.second.name)) {
        user->respond(false, ProtocolTCP::strToBuffer("INVALID NAME"));
        return true;
    }
    int id = createRoom(ProtocolTCP::tabToStr(body.second.name), user->getId(), user->getUsername());
    if (id == -1) {
        user->respond(false, ProtocolTCP::strToBuffer("INTERNAL ERROR"));
    } else {
        user->setRoom(id);
        response.port = _rooms.at(id)->getPort();
        user->respond(true, ProtocolTCP::setBody(response));
    }
    return true;
}

bool BackEndLauncher::actionJoinRoom(UserPtr &user, const my_socket::Buffer &buffer)
{
    auto body = ProtocolTCP::getBody<ProtocolTCP::RequestJoinRoomData>(buffer);
    ProtocolTCP::ResponseJoinRoomData response;

    if (!user->isConnected()) {
        user->respond(false, ProtocolTCP::strToBuffer("NOT CONNECTED"));
        return true;
    } else if (user->getRoom() != -1) {
        user->respond(false, ProtocolTCP::strToBuffer("ALREADY IN A ROOM"));
        return true;
    } else if (!body.first) {
        user->respond(false, ProtocolTCP::strToBuffer("INVALID DATA SIZE"));
        return true;
    }
    try {
        auto &room = _rooms.at(body.second.nb_room);
        if (room->gameStarted()) {
            user->respond(false, ProtocolTCP::strToBuffer("GAME ALREADY STARTED"));
            return true;
        } else if (!room->addPlayer(user->getId(), user->getUsername())) {
            user->respond(false, ProtocolTCP::strToBuffer("ROOM IS FULL"));
            return true;
        } else {
            user->setRoom(body.second.nb_room);
            response.port = room->getPort();
            user->respond(true, ProtocolTCP::setBody(response));
            return true;
        }
    } catch (...) {
        user->respond(false, ProtocolTCP::strToBuffer("ROOM DOES NOT EXIST"));
        return true;
    }
}

bool BackEndLauncher::actionLeaveRoom(UserPtr &user, const my_socket::Buffer &buffer)
{
    auto body = ProtocolTCP::getBody<ProtocolTCP::DummyData>(buffer);
    ProtocolTCP::DummyData response;

    if (!user->isConnected()) {
        user->respond(false, ProtocolTCP::strToBuffer("NOT CONNECTED"));
        return true;
    } else if (user->getRoom() == -1) {
        user->respond(false, ProtocolTCP::strToBuffer("NOT IN A ROOM"));
        return true;
    } else if (!body.first) {
        user->respond(false, ProtocolTCP::strToBuffer("INVALID DATA SIZE"));
        return true;
    }
    leaveRoom(user);
    user->respond(true, ProtocolTCP::setBody(response));
    return true;
}

bool BackEndLauncher::actionStartGame(UserPtr &user, const my_socket::Buffer &buffer)
{
    auto body = ProtocolTCP::getBody<ProtocolTCP::DummyData>(buffer);
    ProtocolTCP::DummyData response;

    if (!user->isConnected()) {
        user->respond(false, ProtocolTCP::strToBuffer("NOT CONNECTED"));
    } else if (user->getRoom() == -1) {
        user->respond(false, ProtocolTCP::strToBuffer("NOT IN A ROOM"));
    } else if (!body.first) {
        user->respond(false, ProtocolTCP::strToBuffer("INVALID DATA SIZE"));
    } else if (!_rooms.at(user->getRoom())->isMaster(user->getId())) {
        user->respond(false, ProtocolTCP::strToBuffer("NOT MASTER"));
    } else if (!_rooms.at(user->getRoom())->startGame()) {
        user->respond(false, ProtocolTCP::strToBuffer("ALREADY STARTED"));
    } else {
        user->respond(true, ProtocolTCP::setBody(response));
    }
    return true;
}

int BackEndLauncher::createRoom(const std::string &name, int userId, const std::string &username)
{
    try {
        int id = _roomsId++;
        _rooms.insert(std::make_pair(id, std::make_unique<GameRoom>(id, _port + id, name, userId, username)));
        return id;
    } catch (...) {
        return -1;
    }
}

bool BackEndLauncher::leaveRoom(UserPtr &user)
{
    int roomNb = user->getRoom();
    if (roomNb == -1)
        return false;

    auto &room = _rooms.at(roomNb);
    user->setRoom(-1);
    if (!room->isMaster(user->getId())) {
        room->removePlayer(user->getId());
    } else {
        for (auto & _user : _users) {
            if (_user.second->getRoom() == roomNb)
                _user.second->setRoom(-1);
        }
        _rooms.erase(roomNb);
    }
    return true;
}