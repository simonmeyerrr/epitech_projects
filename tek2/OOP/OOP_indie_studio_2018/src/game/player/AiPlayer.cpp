/*
** EPITECH PROJECT, 2018
** OOP_indie_studio_2018
** File description:
** Ai.cpp
*/

#include <ctime>
#include <tuple>
#include <iostream>
#include "AiPlayer.hpp"

AiPlayer::~AiPlayer()
{
}

AiPlayer::AiPlayer(int priv_nb, int pub_nb, const std::string &ip,
    const Settings &settings
)
    : Player(priv_nb, pub_nb, ip), _updateStart(true), _direction(0),
    _settings(settings)
{
    std::vector<std::tuple<std::size_t, BlockType, bool>> temp;

    for (std::size_t x = 0; x < MAP_WIDTH; ++x)
        temp.emplace_back(std::make_tuple(0, BLOCK_NONE, false));
    for (std::size_t y = 0; y < MAP_HEIGHT; ++y)
        _noGoZone.emplace_back(temp);
}

void AiPlayer::update(const KeySet &set, MyEventReceiver &event)
{
    (void)set;
    (void)event;
    if (_updateStart || !_game->players[_pub_nb].alive ||
        _game->players[_pub_nb].using_laser || _game->players[_pub_nb].moving ||
        !_game->started) {
        DoNothing();
        _updateStart = false;
        return;
    }
    for (std::size_t y = 0; y < MAP_HEIGHT; ++y) {
        for (std::size_t x = 0; x < MAP_WIDTH; ++x)
            std::get<0>(_noGoZone[y][x]) = 0;
    }
    for (std::size_t index = 0, y = 0, x = 0;
        index < MAP_HEIGHT * MAP_WIDTH; ++index) {
        if (_game->map[index].explosion) {
            std::get<0>(_noGoZone[y][x]) = 2;
            if (y + 1 < MAP_HEIGHT)
                std::get<0>(_noGoZone[y + 1][x]) = 2;
            if (((int)y - (int)1) >= 0)
                std::get<0>(_noGoZone[y - 1][x]) = 2;
            if (x + 1 < MAP_WIDTH)
                std::get<0>(_noGoZone[y][x + 1]) = 2;
            if ((int)x - (int)1 >= 0)
                std::get<0>(_noGoZone[y][x - 1]) = 2;
        } else if (_game->map[index].bomb) {
            std::get<0>(_noGoZone[y][x]) = 1;
            for (std::size_t i = 0;
                i < (std::size_t)_game->map[index].bomb_power + 1; ++i) {
                if (y + i < MAP_HEIGHT)
                    std::get<0>(_noGoZone[y + i][x]) = 1;
                if (((int)y - (int)i) >= 0)
                    std::get<0>(_noGoZone[y - i][x]) = 1;
                if (x + i < MAP_WIDTH)
                    std::get<0>(_noGoZone[y][x + i]) = 1;
                if ((int)x - (int)i >= 0)
                    std::get<0>(_noGoZone[y][x - i]) = 1;
            }
        }
        std::get<1>(_noGoZone[y][x]) = _game->map[index].type;
        std::get<2>(_noGoZone[y][x]) = false;
        #ifdef DEBUG
        std::cerr << std::get<0>(_noGoZone[y][x]);
        #endif
        ++x;
        if (x == MAP_WIDTH) {
            #ifdef DEBUG
            std::cerr << std::endl;
            #endif
            x = 0;
            ++y;
        }
    }
    chooseAction();
}

void AiPlayer::DoNothing()
{
    Action action = {MAGIC_NUMBER, false, DIR_UP, false};
    _client.sendMessage(&action);
    auto new_game = _client.getMessage();
    if (new_game) {
        delete _game;
        _game = new_game;
    }
}

void AiPlayer::chooseAction()
{
    if (isInDanger(_game->players[_pub_nb].pos)) {
        #ifdef DEBUG
        std::cerr << "Defence" << std::endl;
        #endif
        playDefencive();
    } else {
        playOffencive();
        #ifdef DEBUG
        std::cerr << "offencive" << std::endl << std::endl;
        #endif
    }
    auto new_game = _client.getMessage();
    if (new_game) {
        delete _game;
        _game = new_game;
    }
}

bool AiPlayer::isInDanger(const Position &pos) const
{
    return std::get<0>(_noGoZone[(int)pos.y][(int)pos.x]) != 0;
}

void AiPlayer::playOffencive()
{
    Action action = {MAGIC_NUMBER, false, DIR_UP, false};

    if (_game->players[_pub_nb].bonus_laser) {
        if (tryToUseLaser())
            return;
    } else if (putBomb()) {
        action.use_power = true;
    }
    void (AiPlayer::*go[4])(Action &) const = {&AiPlayer::goUp,
        &AiPlayer::goDown, &AiPlayer::goLeft, &AiPlayer::goRight};
    bool (AiPlayer::*tryToGo[4])() const = {&AiPlayer::tryToGoUp,
        &AiPlayer::tryToGoDown, &AiPlayer::tryToGoLeft,
        &AiPlayer::tryToGoRight};
    chase(comparePosition(findNearestPlayer()));
    if ((this->*tryToGo[_direction - 1])())
        (this->*go[_direction - 1])(action);
    _client.sendMessage(&action);
}

void AiPlayer::playDefencive()
{
    Action action = {MAGIC_NUMBER, false, DIR_UP, false};

    size_t direction = findSafePlaceAroundMe(_game->players[_pub_nb].pos);
    if (!direction)
        direction = std::get<0>((findSafeWay(_game->players[_pub_nb].pos, 0)));
    switch (direction) {
    case 1:
        goUp(action);
        break;
    case 2:
        goDown(action);
        break;
    case 3:
        goLeft(action);
        break;
    case 4:
        goRight(action);
        break;
    default:
        break;
    }
    _client.sendMessage(&action);
}

std::pair<std::size_t, std::size_t> AiPlayer::findSafeWay(Position pos,
    std::size_t distance
)
{
    if (!isInDanger(pos))
        return std::make_pair(5, distance);

    std::get<2>(_noGoZone[pos.y][pos.x]) = true;
    std::size_t distanceU = MAP_HEIGHT;
    std::size_t distanceD = MAP_HEIGHT;
    std::size_t distanceL = MAP_WIDTH;
    std::size_t distanceR = MAP_WIDTH;
    Position temp;
    std::pair<std::size_t, std::size_t> value;

    if (tryToGoUp(pos)) {
        temp.x = pos.x;
        temp.y = pos.y - 1;
        #ifdef DEBUG
        std::cerr << "U = " << distance << std::endl;
        #endif
        value = findSafeWay(temp, distance + 1);
        if (std::get<0>(value) != 0) {
            distanceU = std::get<1>(value);
        }
    }
    if (tryToGoDown(pos)) {
        temp.x = pos.x;
        temp.y = pos.y + 1;
        #ifdef DEBUG
        std::cerr << "D = " << distance << std::endl;
        #endif
        value = findSafeWay(temp, distance + 1);
        if (std::get<0>(value) != 0) {
            distanceD = std::get<1>(value);
        }
    }
    if (tryToGoLeft(pos)) {
        temp.x = pos.x - 1;
        temp.y = pos.y;
        #ifdef DEBUG
        std::cerr << "L = " << distance << std::endl;
        #endif
        value = findSafeWay(temp, distance + 1);
        if (std::get<0>(value) != 0) {
            distanceL = std::get<1>(value);
        }
    }
    if (tryToGoRight(pos)) {
        temp.x = pos.x + 1;
        temp.y = pos.y;
        #ifdef DEBUG
        std::cerr << "R = " << distance << std::endl;
        #endif
        value = findSafeWay(temp, distance + 1);
        if (std::get<0>(value) != 0) {
            distanceR = std::get<1>(value);
        }
    }
    #ifdef DEBUG
    std::cerr << "distanceU = " << distanceU << std::endl;
    std::cerr << "distanceD = " << distanceD << std::endl;
    std::cerr << "distanceL = " << distanceL << std::endl;
    std::cerr << "distanceR = " << distanceR << std::endl << std::endl;
    #endif
    if (distanceU != MAP_HEIGHT && distanceU <= distanceD &&
        distanceU <= distanceL && distanceU <= distanceR)
        return std::make_pair(1, distance);
    else if (distanceD != MAP_HEIGHT && distanceD <= distanceU &&
        distanceD <= distanceL && distanceD <= distanceR)
        return std::make_pair(2, distance);
    else if (distanceL != MAP_WIDTH && distanceL <= distanceD &&
        distanceL <= distanceU && distanceL <= distanceR)
        return std::make_pair(3, distance);
    else if (distanceR != MAP_WIDTH && distanceR <= distanceD &&
        distanceR <= distanceL && distanceR <= distanceU)
        return std::make_pair(4, distance);
    else
        return std::make_pair(0, distance);
}

bool AiPlayer::verifBreackableWallAroundMe() const
{
    if (_game->players[_pub_nb].pos.y - 1 >= 0 && std::get<1>(
        _noGoZone[_game->players[_pub_nb].pos.y -
            1][_game->players[_pub_nb].pos.x]) == BLOCK_BREAKABLE)
        return true;
    else if (_game->players[_pub_nb].pos.y + 1 < MAP_HEIGHT && std::get<1>(
        _noGoZone[_game->players[_pub_nb].pos.y +
            1][_game->players[_pub_nb].pos.x]) == BLOCK_BREAKABLE)
        return true;
    else if (_game->players[_pub_nb].pos.x - 1 >= 0 && std::get<1>(
        _noGoZone[_game->players[_pub_nb].pos.y][_game->players[_pub_nb].pos.x -
            1]) == BLOCK_BREAKABLE)
        return true;
    else
        return _game->players[_pub_nb].pos.x + 1 < MAP_WIDTH && std::get<1>(
            _noGoZone[_game->players[_pub_nb].pos.y][
                _game->players[_pub_nb].pos.x + 1]) == BLOCK_BREAKABLE;
}

std::size_t AiPlayer::findSafePlaceAroundMe(const Position &pos) const
{
    if (pos.y - 1 >= 0 && !std::get<0>(_noGoZone[pos.y - 1][pos.x]) &&
        std::get<1>(_noGoZone[pos.y - 1][pos.x]) == BLOCK_NONE)
        return 1;
    else if (pos.y + 1 < MAP_HEIGHT &&
        !std::get<0>(_noGoZone[pos.y + 1][pos.x]) &&
        std::get<1>(_noGoZone[pos.y + 1][pos.x]) == BLOCK_NONE)
        return 2;
    else if (pos.x - 1 >= 0 && !std::get<0>(_noGoZone[pos.y][pos.x - 1]) &&
        std::get<1>(_noGoZone[pos.y][pos.x - 1]) == BLOCK_NONE)
        return 3;
    else if (pos.x + 1 < MAP_WIDTH &&
        !std::get<0>(_noGoZone[pos.y][pos.x + 1]) &&
        std::get<1>(_noGoZone[pos.y][pos.x + 1]) == BLOCK_NONE)
        return 4;
    return 0;
}

Position AiPlayer::findNearestPlayer() const
{
    std::vector<Position> pos;

    for (std::size_t i = 0; i < 4; ++i) {
        if (i != (long unsigned int)_pub_nb && _game->players[i].alive) {
            pos.emplace_back(_game->players[i].pos);
        }
    }
    Position anyone;
    anyone.x = MAP_WIDTH / 2;
    anyone.y = MAP_HEIGHT / 2;
    if (pos.empty())
        return anyone;
    Position temp = pos[0];
    for (std::size_t i = 1; i < pos.size(); ++i) {
        int me = _game->players[_pub_nb].pos.x + _game->players[_pub_nb].pos.y;
        int one = temp.x + temp.y;
        int two = pos[i].x + pos[i].y;
        if ((one - me) * -1 > (two - me) * -1)
            temp = pos[i];
    }
    return temp;
}

bool AiPlayer::tryToGoUp(const Position &pos) const
{
    if (pos.y <= 0)
        return false;
    if (_settings.settings.game.collision_player)
        for (auto &player : _game->players) {
            if (player.alive && pos.x == player.pos.x &&
                pos.y - 1 == player.pos.y)
                return false;
        }
    return std::get<0>(_noGoZone[pos.y - 1][pos.x]) != 2 &&
        std::get<1>(_noGoZone[pos.y - 1][pos.x]) == BLOCK_NONE &&
        !std::get<2>(_noGoZone[pos.y - 1][pos.x]);
}

bool AiPlayer::tryToGoDown(const Position &pos) const
{
    if (pos.y >= MAP_HEIGHT - 1)
        return false;
    if (_settings.settings.game.collision_player)
        for (auto &player : _game->players) {
            if (player.alive && pos.x == player.pos.x &&
                pos.y + 1 == player.pos.y)
                return false;
        }
    return std::get<0>(_noGoZone[pos.y + 1][pos.x]) != 2 &&
        std::get<1>(_noGoZone[pos.y + 1][pos.x]) == BLOCK_NONE &&
        !std::get<2>(_noGoZone[pos.y + 1][pos.x]);
}

bool AiPlayer::tryToGoLeft(const Position &pos) const
{
    if (pos.x <= 0)
        return false;
    if (_settings.settings.game.collision_player)
        for (auto &player : _game->players) {
            if (player.alive && pos.x - 1 == player.pos.x &&
                pos.y == player.pos.y)
                return false;
        }
    return std::get<0>(_noGoZone[pos.y][pos.x - 1]) != 2 &&
        std::get<1>(_noGoZone[pos.y][pos.x - 1]) == BLOCK_NONE &&
        !std::get<2>(_noGoZone[pos.y][pos.x - 1]);
}

bool AiPlayer::tryToGoRight(const Position &pos) const
{
    if (pos.x >= MAP_WIDTH - 1)
        return false;
    if (_settings.settings.game.collision_player)
        for (auto &player : _game->players) {
            if (player.alive && pos.x + 1 == player.pos.x &&
                pos.y == player.pos.y)
                return false;
        }
    return std::get<0>(_noGoZone[pos.y][pos.x + 1]) != 2 &&
        std::get<1>(_noGoZone[pos.y][pos.x + 1]) == BLOCK_NONE &&
        !std::get<2>(_noGoZone[pos.y][pos.x + 1]);
}

bool AiPlayer::tryToGoUp() const
{
    if (_game->players[_pub_nb].pos.y <= 0)
        return false;
    if (_settings.settings.game.collision_player)
        for (auto &player : _game->players) {
            if (player.alive && _game->players[_pub_nb].pos.x == player.pos.x &&
                _game->players[_pub_nb].pos.y - 1 == player.pos.y)
                return false;
        }
    return !std::get<0>(_noGoZone[_game->players[_pub_nb].pos.y -
        1][_game->players[_pub_nb].pos.x]) && std::get<1>(
        _noGoZone[_game->players[_pub_nb].pos.y -
            1][_game->players[_pub_nb].pos.x]) == BLOCK_NONE && !std::get<2>(
        _noGoZone[_game->players[_pub_nb].pos.y -
            1][_game->players[_pub_nb].pos.x]);
}

bool AiPlayer::tryToGoDown() const
{
    if (_game->players[_pub_nb].pos.y >= MAP_HEIGHT - 1)
        return false;
    if (_settings.settings.game.collision_player)
        for (auto &player : _game->players) {
            if (player.alive && _game->players[_pub_nb].pos.x == player.pos.x &&
                _game->players[_pub_nb].pos.y + 1 == player.pos.y)
                return false;
        }
    return !std::get<0>(_noGoZone[_game->players[_pub_nb].pos.y +
        1][_game->players[_pub_nb].pos.x]) && std::get<1>(
        _noGoZone[_game->players[_pub_nb].pos.y +
            1][_game->players[_pub_nb].pos.x]) == BLOCK_NONE && !std::get<2>(
        _noGoZone[_game->players[_pub_nb].pos.y +
            1][_game->players[_pub_nb].pos.x]);
}

bool AiPlayer::tryToGoLeft() const
{
    if (_game->players[_pub_nb].pos.x <= 0)
        return false;
    if (_settings.settings.game.collision_player)
        for (auto &player : _game->players) {
            if (player.alive &&
                _game->players[_pub_nb].pos.x - 1 == player.pos.x &&
                _game->players[_pub_nb].pos.y == player.pos.y)
                return false;
        }
    return !std::get<0>(
        _noGoZone[_game->players[_pub_nb].pos.y][_game->players[_pub_nb].pos.x -
            1]) && std::get<1>(
        _noGoZone[_game->players[_pub_nb].pos.y][_game->players[_pub_nb].pos.x -
            1]) == BLOCK_NONE && !std::get<2>(
        _noGoZone[_game->players[_pub_nb].pos.y][_game->players[_pub_nb].pos.x -
            1]);
}

bool AiPlayer::tryToGoRight() const
{
    if (_game->players[_pub_nb].pos.x >= MAP_WIDTH - 1)
        return false;
    if (_settings.settings.game.collision_player)
        for (auto &player : _game->players) {
            if (player.alive &&
                _game->players[_pub_nb].pos.x + 1 == player.pos.x &&
                _game->players[_pub_nb].pos.y == player.pos.y)
                return false;
        }
    return !std::get<0>(
        _noGoZone[_game->players[_pub_nb].pos.y][_game->players[_pub_nb].pos.x +
            1]) && std::get<1>(
        _noGoZone[_game->players[_pub_nb].pos.y][_game->players[_pub_nb].pos.x +
            1]) == BLOCK_NONE && !std::get<2>(
        _noGoZone[_game->players[_pub_nb].pos.y][_game->players[_pub_nb].pos.x +
            1]);
}

void AiPlayer::goUp(Action &action) const
{
    action.move = true;
    action.dir = DIR_UP;
}

void AiPlayer::goDown(Action &action) const
{
    action.move = true;
    action.dir = DIR_DOWN;
}

void AiPlayer::goLeft(Action &action) const
{
    action.move = true;
    action.dir = DIR_LEFT;
}

void AiPlayer::goRight(Action &action) const
{
    action.move = true;
    action.dir = DIR_RIGHT;
}

void AiPlayer::chase(const Position &move)
{
    switch (_direction) {
    case 1:
        if (!tryToGoLeft() && !tryToGoRight() && !tryToGoUp()) {
            _direction = 2;
        } else {
            if (move.x == 1 && tryToGoRight())
                _direction = 4;
            else if (move.x == -1 && tryToGoLeft())
                _direction = 3;
            else if (!tryToGoUp()) {
                if (tryToGoLeft())
                    _direction = 3;
                else if (tryToGoRight())
                    _direction = 4;
            }
        }
        break;
    case 2:
        if (!tryToGoLeft() && !tryToGoRight() && !tryToGoDown()) {
            _direction = 1;
        } else {
            if (move.x == 1 && tryToGoRight())
                _direction = 4;
            else if (move.x == -1 && tryToGoLeft())
                _direction = 3;
            else if (!tryToGoDown()) {
                if (tryToGoLeft())
                    _direction = 3;
                else if (tryToGoRight())
                    _direction = 4;
            }
        }
        break;
    case 3:
        if (!tryToGoUp() && !tryToGoDown() && !tryToGoLeft()) {
            _direction = 4;
        } else {
            if (move.y == -1 && tryToGoUp())
                _direction = 1;
            else if (move.y == 1 && tryToGoDown())
                _direction = 2;
            else if (!tryToGoLeft()) {
                if (tryToGoDown())
                    _direction = 2;
                else if (tryToGoUp())
                    _direction = 1;
            }
        }
        break;
    case 4:
        if (!tryToGoUp() && !tryToGoDown() && !tryToGoRight()) {
            _direction = 3;
        } else {
            if (move.y == -1 && tryToGoUp())
                _direction = 1;
            else if (move.y == 1 && tryToGoDown())
                _direction = 2;
            else if (!tryToGoRight()) {
                if (tryToGoDown())
                    _direction = 2;
                else if (tryToGoUp())
                    _direction = 1;
            }
        }
        break;
    default:
        _direction = std::rand() % 4 + 1;
        break;
    }
}

bool AiPlayer::tryToUseLaser()
{
    static bool time = false;
    bool find = false;
    Direction dir = DIR_UP;

    if (!time) {
        time = true;
        _timeLaser = std::chrono::high_resolution_clock::now();
    }
    for (std::size_t i = 0; i < 4; ++i) {
        if ((int)i != _pub_nb && _game->players[i].alive) {
            if (_game->players[_pub_nb].pos.x == _game->players[i].pos.x) {
                if (_game->players[_pub_nb].pos.y - _game->players[i].pos.y >
                    0) {
                    dir = DIR_UP;
                } else
                    dir = DIR_DOWN;
                find = true;
                break;
            } else if (_game->players[_pub_nb].pos.y ==
                _game->players[i].pos.y) {
                if (_game->players[_pub_nb].pos.x - _game->players[i].pos.x >
                    0) {
                    dir = DIR_LEFT;
                } else
                    dir = DIR_RIGHT;
                find = true;
                break;
            }
        }
    }
    auto wait = std::chrono::duration<double, std::milli>(
        std::chrono::high_resolution_clock::now() - _timeLaser).count();
    if ((!find || _game->players[_pub_nb].dir != dir) && wait < 2500.0)
        return false;
    Action action = {MAGIC_NUMBER, false, dir, true};
    _client.sendMessage(&action);
    time = false;
    return true;
}

bool AiPlayer::putBomb()
{
    if (_game->players[_pub_nb].max_bomb - _game->players[_pub_nb].ready_bomb >
        _game->players[_pub_nb].max_bomb / 2)
        return false;
    for (std::size_t i = 0; i < 4; ++i) {
        if (_pub_nb != (int)i) {
            if (_game->players[i].alive &&
                _game->players[_pub_nb].pos.x == _game->players[i].pos.x) {
                int temp =
                    _game->players[_pub_nb].pos.y - _game->players[i].pos.y;
                temp < 0 ? temp *= -1 : 0;
                if (temp <= _game->players[_pub_nb].bomb_power)
                    return true;
            }
            if (_game->players[i].alive &&
                _game->players[_pub_nb].pos.y == _game->players[i].pos.y) {
                int temp =
                    _game->players[_pub_nb].pos.x - _game->players[i].pos.x;
                temp < 0 ? temp *= -1 : 0;
                if (temp <= _game->players[_pub_nb].bomb_power)
                    return true;
            }
        }
    }
    return verifBreackableWallAroundMe() &&
        findSafePlaceAroundMe(_game->players[_pub_nb].pos) != 0;
}

Position AiPlayer::comparePosition(const Position &pos) const
{
    Position move;

    if (_game->players[_pub_nb].pos.x > pos.x)
        move.x = -1;
    else if (_game->players[_pub_nb].pos.x < pos.x)
        move.x = 1;
    else
        move.x = 0;
    if (_game->players[_pub_nb].pos.y > pos.y)
        move.y = -1;
    else if (_game->players[_pub_nb].pos.y < pos.y)
        move.y = 1;
    else
        move.y = 0;
    return move;
}


