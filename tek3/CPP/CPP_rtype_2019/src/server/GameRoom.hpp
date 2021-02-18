#ifndef CPP_RTYPE_2019_GAMEROOM_HPP
#define CPP_RTYPE_2019_GAMEROOM_HPP

#include <thread>
#include <memory>
#include "../ProtocolTCP.hpp"
#include "BackEndGame.hpp"

class GameRoom {
public:
    ~GameRoom();

    GameRoom(int id, my_socket::Port port, const std::string &name, int userId, const std::string &username);

    ProtocolTCP::Room getRoomInfo(int userId) const;
    std::string getName() const;
    int getNb() const;
    my_socket::Port getPort() const;
    bool isInRoom(int userId) const;
    bool isMaster(int userId) const;
    bool gameStarted() const;
    bool gameEnded() const;

    bool addPlayer(int userId, const std::string &username);
    bool removePlayer(int userId);
    bool startGame();

private:
    std::string _name;
    int _nb;
    my_socket::Port _port;
    std::atomic<bool> _started;
    std::atomic<bool> _ended;
    PlayerInfo _players[PLAYERS_PER_ROOM];

    std::unique_ptr<BackEndGame> _game;
    my_socket::IServerPtr _server;
    std::thread _thread;
};

using GameRoomPtr = std::unique_ptr<GameRoom>;


#endif /* CPP_RTYPE_2019_GAMEROOM_HPP */
