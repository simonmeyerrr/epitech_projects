#include <iostream>
#include "GameRoom.hpp"
#include "../socket/SocketError.hpp"
#include "../socket/socket_c/ServerUDP.hpp"

GameRoom::~GameRoom()
{
    _server->stopServer();
    _thread.join();
    _server = nullptr;
    _game = nullptr;
}

GameRoom::GameRoom(int id, my_socket::Port port, const std::string &name, int userId, const std::string &username)
    : _name(name), _nb(id), _port(port), _started(false), _ended(false),  _players(), _game(nullptr), _server(nullptr), _thread()
{
    for (int i = 0; i < PLAYERS_PER_ROOM; i++)
        _players[i] = {false, -1, ""};
    try {
        _game = std::make_unique<BackEndGame>();
        _server = std::make_unique<my_socket::ServerUDP>(port, *_game);
        _thread = std::thread(&my_socket::IServer::start, _server.get());
    } catch (...) {
        std::cout << "could not create room" << std::endl;
        throw my_socket::SocketError(my_socket::SocketError::UNKNOWN);
    }
    addPlayer(userId, username);
}

ProtocolTCP::Room GameRoom::getRoomInfo(int userId) const
{
    ProtocolTCP::Room room = {_nb, {}, _started, {}};

    ProtocolTCP::putStrIntoTab(room.name, _name);
    for (int i = 0; i < PLAYERS_PER_ROOM; i++) {
        room.players[i] = {_players[i].exist, {}, _players[i].id == userId};
        ProtocolTCP::putStrIntoTab(room.players[i].username, _players[i].username);
    }
    return room;
}

std::string GameRoom::getName() const
{
    return _name;
}

int GameRoom::getNb() const
{
    return _nb;
}

my_socket::Port GameRoom::getPort() const
{
    return _port;
}

bool GameRoom::isInRoom(int userId) const
{
    for (int i = 0; i < PLAYERS_PER_ROOM; i++) {
        if (_players[i].exist && _players[i].id == userId)
            return true;
    }
    return false;
}

bool GameRoom::isMaster(int userId) const
{
    return _players[0].id == userId;
}

bool GameRoom::gameStarted() const
{
    return _started;
}

bool GameRoom::gameEnded() const
{
    return _ended;
}

bool GameRoom::addPlayer(int userId, const std::string &username)
{
    for (int i = 0; i < PLAYERS_PER_ROOM; i++) {
        if (!_players[i].exist) {
            _players[i].exist = true;
            _players[i].id = userId;
            _players[i].username = username;
            _game->updateRoom(i, _players[i]);
            return true;
        }
    }
    return false;
}

bool GameRoom::removePlayer(int userId)
{
    for (int i = 0; i < PLAYERS_PER_ROOM; i++) {
        if (_players[i].exist && _players[i].id == userId) {
            _players[i].exist = false;
            _players[i].id = -1;
            _players[i].username = "";
            _game->updateRoom(i, _players[i]);
            return true;
        }
    }
    return false;
}

bool GameRoom::startGame()
{
    _started = true;
    return _game->start();
}