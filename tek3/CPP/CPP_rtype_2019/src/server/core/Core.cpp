//
// Created by arnaud on 25/11/2019.
//

#include <iostream>
#include <chrono>
#include <experimental/filesystem>
#include "Core.hpp"
#include "./Entities/FriendShots.hpp"

Core::~Core()
{
    stop();
    _shots.clear();
    _entities.clear();
    _monsterLoaders.clear();
    _players.clear();
}

Core::Core(const PlayerInfo players[PLAYERS_PER_ROOM])
    : _monsterLoaders(), _entities(), _shots(), _players(), _gameScore(0), _running(false), _mutex(), _wave(120), _shotsCount(0), _alive(0)
{
    for (int i = 0; i < PLAYERS_PER_ROOM; i++) {
        _alive += (players[i].exist ? 1 : 0);
        _players.push_back(std::make_unique<Player>(i, players[i].exist));
    }

    std::string path = "./lib";
    for (const auto & entry : std::experimental::filesystem::directory_iterator(path)) {
        try {
#ifdef WIN32
			//_monsterLoaders.push_back(std::make_unique<LibLoader>(std::string(entry.path().generic_u8string())));
#else
            _monsterLoaders.push_back(std::make_unique<LibLoader>(entry.path()));
#endif
            std::cout << "loaded " << entry.path() << std::endl;
        } catch (...) {}
    }
}

void Core::handleMovement(int nb, const ProtocolUDP::ActionMovePlayer &movement)
{
    _mutex.lock();
    _players[nb]->setMovement(movement);
    _mutex.unlock();
}

void Core::removePlayer(int nb)
{
    _mutex.lock();
    _players[nb]->disconnect();
    _alive--;
    _mutex.unlock();
}

void Core::spawnWave()
{
    _wave++;
    if ((_wave < 240 && static_cast<int>(_entities.size()) > 2 * _alive) || _wave < 20)
        return;
    _wave = 0;
    for (int i = 0; i < 6 && _monsterLoaders.size() > 0; i++) {
        try {
            auto rand = std::rand() % _monsterLoaders.size();
            _entities.push_back(std::shared_ptr<IEntity>(_monsterLoaders[rand]->createInstance(143 * (i) + 40)));
        } catch (...) {}
    }
}

void Core::spawnProjectils()
{
    _shotsCount++;
    if (_alive <= 0 || _shotsCount < 30 * _alive)
        return;
    _shotsCount = 0;
    for (const auto &player: _players) {
        if (player->getAlive() && player->getConnected()) {
            const auto &pos = player->getPos();
            _shots.push_back(std::make_unique<FriendShots>(Vector2s(pos._x + 100, pos._y + 25)));
        }
    }
}

bool Core::hasCollision(const IEntity &ent1, const IEntity &ent2) const
{
    auto pos1 = ent1.getPos();
    auto pos2 = ent2.getPos();
    auto size1 = ent1.getSize();
    auto size2 = ent2.getSize();
    short top = pos1._y;
    short bot = pos1._y + size1._y;
    short left = pos1._x;
    short right = pos1._x + size1._x;

    Vector2s points[4] = {{left, top}, {left, bot}, {right, top}, {right, bot}};
    for (int i = 0; i < 4; i++) {
        if (points[i]._x >= pos2._x && points[i]._x <= pos2._x + size2._x &&
            points[i]._y >= pos2._y && points[i]._y <= pos2._y + size2._y) {
            return true;
        }
    }
    return false;
}

void Core::killMonsters()
{
    for (auto &player : _players) {
        if (!player->getAlive() || !player->getConnected())
            continue;
        for (auto it = _entities.begin(); _entities.size() > 0 && it != _entities.end(); it++) {
            if (hasCollision(*player, **it)) {
                _entities.erase(it);
                player->kill();
                _alive--;
                break;
            }
        }
    }
    for (auto its = _shots.begin(); _shots.size() > 0 && its != _shots.end(); its++) {
        bool stop = false;
        for (auto it = _entities.begin(); it != _entities.end(); it++) {
            if (hasCollision(**its, **it)) {
                _entities.erase(it);
                _shots.erase(its);
                stop = true;
                break;
            }
        }
        if (stop)
            break;
    }
}

void Core::updateEntities()
{
    _mutex.lock();
    spawnWave();
    spawnProjectils();
    killMonsters();
    for (const auto &item : _entities) {
        item->update();
    }
    for (const auto &item : _shots) {
        item->update();
    }
    for (auto it = _entities.begin(); it != _entities.end(); it++) {
        if ((*it)->getPos()._x < -100) {
            _entities.erase(it);
            break;
        }
    }
    for (auto it = _shots.begin(); it != _shots.end(); it++) {
        if ((*it)->getPos()._x > 1600) {
            _shots.erase(it);
            break;
        }
    }
    for (const auto &player : _players) {
        player->update();
    }
    _mutex.unlock();
}

ProtocolUDP::Entities Core::getEntities()
{
    ProtocolUDP::Entities data;

    _mutex.lock();
    for (const auto &item : _entities) {
        ProtocolUDP::Entity info{static_cast<short>(item->getType()), item->getPos()._x, item->getPos()._y};
        data.push_back(info);
    }
    for (const auto &item : _shots) {
        ProtocolUDP::Entity info{static_cast<short>(item->getType()), item->getPos()._x, item->getPos()._y};
        data.push_back(info);
    }
    _mutex.unlock();
    return data;
}

std::vector<ProtocolUDP::InfoPlayer> Core::getPlayers()
{
    std::vector<ProtocolUDP::InfoPlayer> data;

    _mutex.lock();
    for (const auto &item : _players) {
        ProtocolUDP::InfoPlayer info {item->getConnected(), item->getAlive(), item->getPos()._x, item->getPos()._y};
        data.push_back(info);
    }
    _mutex.unlock();
    return data;
}

int Core::getGameScore()
{
    return _gameScore;
}

void Core::setGameScore(const int &score)
{
    _gameScore = score;
}

void Core::gameLoop()
{
    using timer = std::chrono::high_resolution_clock;

    constexpr std::chrono::milliseconds timestep(16);
    auto previous = timer::now();
    std::chrono::nanoseconds lag(0);

    _running = true;

    while (_running) {
        auto current = timer::now();
        auto delta = current - previous;
        previous = current;
        lag += std::chrono::duration_cast<std::chrono::nanoseconds>(delta);

        while (lag >= timestep) {
            lag -= timestep;
            updateEntities();
        }
    }
    std::cout << "end core game" << std::endl;
}
