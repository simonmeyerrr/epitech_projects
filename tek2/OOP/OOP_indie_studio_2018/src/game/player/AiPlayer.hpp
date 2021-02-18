/*
** EPITECH PROJECT, 2018
** OOP_indie_studio_2018
** File description:
** Ai.hpp
*/

#ifndef OOP_INDIE_STUDIO_2018_AIPLAYER_HPP
#define OOP_INDIE_STUDIO_2018_AIPLAYER_HPP

#include <vector>
#include <chrono>
#include "Player.hpp"
#include "Structures.hpp"

class AiPlayer : public Player {

public:
    ~AiPlayer() override;
    AiPlayer(int priv_nb, int pub_nb, const std::string &ip, const Settings &);

    void update(const KeySet &set, MyEventReceiver &event) override;

private:
    void DoNothing();
    void chooseAction();
    bool isInDanger(const Position &) const;
    void playOffencive();
    void playDefencive();

    std::pair<std::size_t, std::size_t> findSafeWay(Position, std::size_t
    );

    bool verifBreackableWallAroundMe() const;
    std::size_t findSafePlaceAroundMe(const Position &) const;
    Position findNearestPlayer() const;

    bool tryToGoUp(const Position &) const;
    bool tryToGoDown(const Position &) const;
    bool tryToGoLeft(const Position &) const;
    bool tryToGoRight(const Position &) const;

    bool tryToGoUp() const;
    bool tryToGoDown() const;
    bool tryToGoLeft() const;
    bool tryToGoRight() const;

    void goUp(Action &) const;
    void goDown(Action &) const;
    void goLeft(Action &) const;
    void goRight(Action &) const;

    void chase(const Position &);
    bool tryToUseLaser();
    bool putBomb();
    Position comparePosition(const Position&) const;

    bool _updateStart;
    std::size_t _direction;
    std::vector<std::vector<std::tuple<std::size_t, BlockType, bool>>> _noGoZone;
    Settings _settings;
    std::chrono::high_resolution_clock::time_point _timeLaser;
};

#endif /*OOP_INDIE_STUDIO_2018_AIPLAYER_HPP*/
