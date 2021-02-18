/*
** EPITECH PROJECT, 2018
** OOP_indie_studio_2018
** File description:
** GameStatsContainer.hpp
*/

#ifndef OOP_INDIE_STUDIO_2018_GAMESTATSCONTAINER_HPP
#define OOP_INDIE_STUDIO_2018_GAMESTATSCONTAINER_HPP

#include <chrono>
#include <ctime>
#include <memory>
#include "../Settings.hpp"
#include "Config.hpp"
#include "Structures.hpp"

class GameStatsContainer {
public:
    ~GameStatsContainer() = default;
    explicit GameStatsContainer(Settings &settings);

    const GameStats &getGame() const {return _game;}
    GameStats &getGame() {return _game;}
    GameStats *operator->() {return &_game;}
    const GameStats *operator->() const {return &_game;}

    void updateMap(double diff);
    void updatePlayer(unsigned char nb, const std::unique_ptr<Action>
        &action, double diff);
    void updatePlayersRank();

private:
    void updateExplosions(double diff);
    void updateBombs(double diff);
    void updateBomb(double diff, Position position);
    void bombExplode(Position position);
    void makeExplosion(Position pos, Direction dir,
        unsigned char power);
    BonusType getRandomBonus();

    void updateMoveLaserPlayer(unsigned char nb, double diff);
    void movePlayer(unsigned char nb, Direction dir);
    void usePower(unsigned char nb);
    void updateBonusPlayer(unsigned char nb);

    static Position getNextPosition(const Position &pos, Direction dir);
    using Chrono = std::chrono::time_point<std::chrono::high_resolution_clock>;

    Settings &_set;
    GameStats _game;
    bool _end;
    Chrono _chrono;
};

#endif /*OOP_INDIE_STUDIO_2018_GAMESTATSCONTAINER_HPP*/
