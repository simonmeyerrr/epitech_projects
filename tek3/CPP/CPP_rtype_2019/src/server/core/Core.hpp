//
// Created by arnaud on 25/11/2019.
//

#ifndef CPP_RTYPE_2019_CORE_HPP
#define CPP_RTYPE_2019_CORE_HPP


#include <vector>
#include <atomic>
#include <memory>
#include <mutex>
#include <deque>
#include "Entities/IEntity.hpp"
#include "Entities/Player.hpp"
#include "../../ProtocolUDP.hpp"
#include "../../LibLoader.hpp"

class Core {
public:
    ~Core();
    explicit Core(const PlayerInfo players[PLAYERS_PER_ROOM]);


    void handleMovement(int nb, const ProtocolUDP::ActionMovePlayer &movement);
    void removePlayer(int nb);
    void updateEntities();
    void stop() {_running = false;}
    void gameLoop();

    void setGameScore(const int &);
    void spawnWave();
    void spawnProjectils();
    bool hasCollision(const IEntity &, const IEntity &) const;
    void killMonsters();

    ProtocolUDP::Entities getEntities();
    std::vector<ProtocolUDP::InfoPlayer> getPlayers();
    int getGameScore();

private:
    std::deque<std::unique_ptr<LibLoader>> _monsterLoaders;
    std::deque<std::shared_ptr<IEntity>> _entities;
    std::deque<std::unique_ptr<IEntity>> _shots;
    std::vector<std::unique_ptr<Player>> _players;
    std::atomic<int> _gameScore;
    std::atomic<bool> _running;
    std::mutex _mutex;
    int _wave;
    int _shotsCount;
    int _alive;
};


#endif //CPP_RTYPE_2019_CORE_HPP
