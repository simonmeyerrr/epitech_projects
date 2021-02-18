/*
** EPITECH PROJECT, 2018
** OOP_indie_studio_2018
** File description:
** GameStatsContainer.cpp
*/

#include <iostream>
#include <cstdlib>
#include <fstream>
#include "Config.hpp"
#include "GameStatsContainer.hpp"
#include "Map.hpp"

GameStatsContainer::GameStatsContainer(Settings &settings)
    : _set(settings), _game(), _end(false)
{
    memset(&_game, 0, sizeof(GameStats));
    _game.magic = MAGIC_NUMBER;
    _game.started = false;
    _game.end = false;
    for (int i = 0; i < PLAYER_NUMBER; ++i) {
        _game.players[i].exist = _set.settings.players[i].type != PLAYER_NONE;
        _game.players[i].connected = false;
        _game.players[i].alive = _set.settings.players[i].type != PLAYER_NONE;
        _game.players[i].skin = _set.settings.players[i].skin;
        _game.players[i].number = i;
        _game.players[i].rank = -1;
        _game.players[i].speed = _set.settings.game.speed_start;
        _game.players[i].max_bomb = _set.settings.game.bomb_start_nb;
        _game.players[i].ready_bomb = _set.settings.game.bomb_start_nb;
        _game.players[i].bomb_power = _set.settings.game.bomb_start_power;
        _game.players[i].dir = DIR_UP;
        _game.players[i].pos = {(char)(i % 2 == 0 ? 0 : MAP_WIDTH - 1),
            (char)(i / 2 == 0 ? 0 : MAP_HEIGHT - 1)};
        _game.players[i].next_pos = _game.players[i].pos;
        _game.players[i].moving = false;
        _game.players[i].move_percent = 0.0;
        _game.players[i].bonus_laser = false;
        _game.players[i].using_laser = false;
        _game.players[i].laser_percent = 0.0;
    }
    for (int i = 0; i < MAP_WIDTH * MAP_HEIGHT; ++i) {
        _game.map[i].type = BLOCK_NONE;
        _game.map[i].bomb = false;
        _game.map[i].bomb_player = 0;
        _game.map[i].bomb_power = 0;
        _game.map[i].bomb_percent = 0.0;
        _game.map[i].explosion = false;
        _game.map[i].explosion_percent = 0.0;
        _game.map[i].bonus = BONUS_NONE;
    }
    bool load_error = true;
    if (settings.settings.from_file) {
        std::ifstream file(SAVE_FILE);
        if (file.is_open()) {
            file.read((char *)&_game, sizeof(GameStats));
            file.close();
            load_error = false;
            _game.started = _game.end;
        } else {
            #ifdef DEBUG
            std::cerr << "Failed to open .save file" << std::endl;
            #endif
        }
    }
    if (!settings.settings.from_file || load_error)
        Map().generator(_game.map,
            settings.settings.map_complex ? MAP_COMPLEX : MAP_CLASSIC);
}

void GameStatsContainer::updateMap(double diff)
{
    updateExplosions(diff);
    updateBombs(diff);
}

void GameStatsContainer::updateExplosions(double diff)
{
    for (unsigned int y = 0; y < MAP_HEIGHT; y++) {
        for (unsigned int x = 0; x < MAP_WIDTH; x++) {
            int pos = y * MAP_WIDTH + x;
            if (_game.map[pos].explosion)
                _game.map[pos].explosion_percent +=
                    (diff / (_set.settings.game.explosion_time * 1000.0)) *
                        100.0;
            if (_game.map[pos].explosion &&
                _game.map[pos].explosion_percent >= 100.0) {
                _game.map[pos].explosion_percent = 0.0;
                _game.map[pos].explosion = false;
            }
        }
    }
}

void GameStatsContainer::updateBombs(double diff)
{
    for (unsigned int y = 0; y < MAP_HEIGHT; y++) {
        for (unsigned int x = 0; x < MAP_WIDTH; x++) {
            updateBomb(diff, {(char)x, (char)y});
        }
    }
}

void GameStatsContainer::updateBomb(double diff, Position position)
{
    int pos = position.y * MAP_WIDTH + position.x;

    if (_game.map[pos].bomb) {
        _game.map[pos].bomb_percent +=
            (diff / (_set.settings.game.bomb_time * 1000.0)) * 100.0;
        if (_game.map[pos].bomb && _game.map[pos].bomb_percent >= 100.0)
            bombExplode(position);
    }
}

void GameStatsContainer::bombExplode(Position pos)
{
    Block &block = _game.map[pos.y * MAP_WIDTH + pos.x];

    block.bomb = false;
    block.bomb_percent = 0.0;
    _game.players[block.bomb_player].ready_bomb += 1;
    makeExplosion(pos, DIR_UP, block.bomb_power);
    makeExplosion(pos, DIR_DOWN, block.bomb_power);
    makeExplosion(pos, DIR_RIGHT, block.bomb_power);
    makeExplosion(pos, DIR_LEFT, block.bomb_power);
    #ifdef DEBUG
    std::cout << "Bomb explode in " << (int)pos.x << ", " << (int)pos.y
        << std::endl;
    #endif
}

void GameStatsContainer::makeExplosion(Position pos, Direction dir,
    unsigned char power)
{
    char diff_x = (dir == DIR_RIGHT ? 1 : (dir == DIR_LEFT ? -1 : 0));
    char diff_y = (dir == DIR_DOWN ? 1 : (dir == DIR_UP ? -1 : 0));
    unsigned char i = 0;

    while (i < power + 1 && pos.x >= 0 && pos.x < MAP_WIDTH && pos.y >= 0 &&
        pos.y < MAP_HEIGHT &&
        _game.map[pos.y * MAP_WIDTH + pos.x].type != BLOCK_UNBREAKABLE) {
        _game.map[pos.y * MAP_WIDTH + pos.x].explosion = true;
        _game.map[pos.y * MAP_WIDTH + pos.x].explosion_percent = 0;
        if (_set.settings.game.bomb_cascade &&
            _game.map[pos.y * MAP_WIDTH + pos.x].bomb)
            bombExplode(pos);
        if (_game.map[pos.y * MAP_WIDTH + pos.x].type == BLOCK_BREAKABLE) {
            _game.map[pos.y * MAP_WIDTH + pos.x].type = BLOCK_NONE;
            _game.map[pos.y * MAP_WIDTH + pos.x].bonus = getRandomBonus();
            if (!_set.settings.game.explosion_multi_break)
                break;
        }
        pos.y += diff_y;
        pos.x += diff_x;
        i++;
    }
}

BonusType GameStatsContainer::getRandomBonus()
{
    const BonusType bonuses[] = {BONUS_SPEED_UP, BONUS_BOMB_POWER,
        BONUS_BOMB_MAX, BONUS_LASER};
    if (std::rand() % 100 < _set.settings.game.bonus_chance)
        return bonuses[std::rand() % 4];
    return BONUS_NONE;
}

void GameStatsContainer::updatePlayer(unsigned char nb,
    const std::unique_ptr<Action> &action, double diff)
{
    if (!_game.players[nb].alive || !_game.players[nb].exist || _game.end)
        return;
    updateMoveLaserPlayer(nb, diff);
    updateBonusPlayer(nb);
    if (action && action->move)
        movePlayer(nb, action->dir);
    if (action && action->use_power)
        usePower(nb);

    Position pos = _game.players[nb].pos;
    if (_game.players[nb].move_percent > 50.0)
        pos = _game.players[nb].next_pos;
    if (_game.map[pos.y * MAP_WIDTH + pos.x].explosion) {
        #ifdef DEBUG
        std::cout << "Player " << (int)nb << " died..." << std::endl;
        #endif
        _game.players[nb].alive = false;
    }
}

void GameStatsContainer::updateMoveLaserPlayer(unsigned char nb, double diff)
{
    if (_game.players[nb].moving)
        _game.players[nb].move_percent +=
            ((diff / (0.2 * 1000.0)) * (_game.players[nb].speed * 0.1 + 1.0)) *
                100.0;
    if (_game.players[nb].move_percent >= 100.0) {
        _game.players[nb].pos = _game.players[nb].next_pos;
        _game.players[nb].moving = false;
        _game.players[nb].move_percent = 0.0;
    }
    if (_game.players[nb].using_laser)
        _game.players[nb].laser_percent +=
            ((diff / (_set.settings.game.explosion_time * 1000.0))) * 100.0;
    if (_game.players[nb].laser_percent >= 100.0) {
        _game.players[nb].using_laser = false;
        _game.players[nb].laser_percent = 0.0;
    }
}

void GameStatsContainer::movePlayer(unsigned char nb, Direction dir)
{
    if (_game.players[nb].moving || _game.players[nb].using_laser)
        return;
    _game.players[nb].dir = dir;
    Position pos = {_game.players[nb].pos.x, _game.players[nb].pos.y};
    auto next = getNextPosition(_game.players[nb].pos, dir);
    if (next.x < 0 || next.x >= MAP_WIDTH || next.y < 0 || next.y >= MAP_HEIGHT)
        return;
    if (_set.settings.game.collision_bomb &&
        _game.map[next.y * MAP_WIDTH + next.x].bomb &&
        !_game.map[pos.y * MAP_WIDTH + pos.x].bomb)
        return;
    if (_game.map[next.y * MAP_WIDTH + next.x].type != BLOCK_NONE)
        return;
    for (unsigned char i = 0;
        _set.settings.game.collision_player && i < PLAYER_NUMBER; i++) {
        if (_game.players[i].alive && ((_game.players[i].next_pos.x == next.x &&
            _game.players[i].next_pos.y == next.y) ||
            (_game.players[i].move_percent <= 50.0 &&
                _game.players[i].pos.x == next.x &&
                _game.players[i].pos.y == next.y))) {
            return;
        }
    }
    _game.players[nb].moving = true;
    _game.players[nb].move_percent = 0.0;
    _game.players[nb].next_pos = next;
    #ifdef DEBUG
    std::cout << "Player " << (int)nb << " moved " << dir << std::endl;
    #endif
}

void GameStatsContainer::usePower(unsigned char nb)
{
    if ((_game.players[nb].bonus_laser && _game.players[nb].moving) ||
        _game.players[nb].using_laser)
        return;

    Position pos = {_game.players[nb].pos.x, _game.players[nb].pos.y};
    if (_game.players[nb].bonus_laser) {
        _game.players[nb].bonus_laser = false;
        _game.players[nb].using_laser = true;
        _game.players[nb].laser_percent = 0.0;
        auto next = getNextPosition(pos, _game.players[nb].dir);
        makeExplosion(next, _game.players[nb].dir, 100);
        #ifdef DEBUG
        std::cout << "Player " << (int)nb << " use laser" << std::endl;
        #endif
        return;
    }
    Position next = {_game.players[nb].next_pos.x,
        _game.players[nb].next_pos.y};
    if (_game.players[nb].ready_bomb <= 0 ||
        (_game.players[nb].move_percent <= 50.0 &&
            _game.map[pos.y * MAP_WIDTH + pos.x].bomb) ||
        (_game.players[nb].move_percent > 50.0 &&
            _game.map[next.y * MAP_WIDTH + next.x].bomb))
        return;
    if (_game.players[nb].move_percent > 50.0)
        pos = next;
    _game.players[nb].ready_bomb -= 1;
    _game.map[pos.y * MAP_WIDTH + pos.x].bomb = true;
    _game.map[pos.y * MAP_WIDTH + pos.x].bomb_percent = 0.0;
    _game.map[pos.y * MAP_WIDTH + pos.x].bomb_player = nb;
    _game.map[pos.y * MAP_WIDTH +
        pos.x].bomb_power = _game.players[nb].bomb_power;
    #ifdef DEBUG
    std::cout << "Player " << (int)nb << " put a bomb" << std::endl;
    #endif
}

void GameStatsContainer::updateBonusPlayer(unsigned char nb)
{
    Position pos = _game.players[nb].pos;

    if (_game.players[nb].move_percent > 50.0)
        pos = _game.players[nb].next_pos;
    if (_game.map[pos.y * MAP_WIDTH + pos.x].bonus == BONUS_NONE)
        return;
    switch (_game.map[pos.y * MAP_WIDTH + pos.x].bonus) {
    case BONUS_LASER:
        _game.players[nb].bonus_laser = true;
        break;
    case BONUS_BOMB_MAX:
        if (_game.players[nb].max_bomb < _set.settings.game.bomb_max_nb) {
            _game.players[nb].max_bomb += 1;
            _game.players[nb].ready_bomb += 1;
        }
        break;
    case BONUS_BOMB_POWER:
        _game.players[nb].bomb_power += (
            _game.players[nb].bomb_power < _set.settings.game.bomb_max_power ?
                1 : 0);
        break;
    case BONUS_SPEED_UP:
        _game.players[nb].speed += (
            _game.players[nb].speed < _set.settings.game.speed_max ? 1 : 0);
        break;
    default:
        break;
    }
    #ifdef DEBUG
    std::cout << "Player " << (int)nb << " took bonus "
        << _game.map[pos.y * MAP_WIDTH + pos.x].bonus << std::endl;
    #endif
    _game.map[pos.y * MAP_WIDTH + pos.x].bonus = BONUS_NONE;
}

Position GameStatsContainer::getNextPosition(const Position &pos, Direction dir)
{
    switch (dir) {
    case DIR_UP:
        return {pos.x, (char)(pos.y - 1)};
    case DIR_DOWN:
        return {pos.x, (char)(pos.y + 1)};
    case DIR_RIGHT:
        return {(char)(pos.x + 1), pos.y};
    case DIR_LEFT:
        return {(char)(pos.x - 1), pos.y};
    default:
        return {pos.x, pos.y};
    }
}

void GameStatsContainer::updatePlayersRank()
{
    int nb_alive = 0;

    for (int i = 0; i < PLAYER_NUMBER; i++) {
        if (_game.players[i].alive)
            nb_alive++;
    }
    for (int i = 0; i < PLAYER_NUMBER; i++) {
        if (!_game.players[i].alive && _game.players[i].exist &&
            _game.players[i].rank == -1) {
            _game.players[i].rank = nb_alive + 1;
        }
        if (_game.players[i].alive && nb_alive == 1)
            _game.players[i].rank = 1;
    }
    if (nb_alive <= 1 && !_end) {
        _chrono = std::chrono::high_resolution_clock::now();
        _end = true;
    } else if (_end) {
        auto diff = std::chrono::duration<double, std::milli>(
            std::chrono::high_resolution_clock::now() - _chrono).count();
        if (diff > 1000)
            _game.end = true;
    }
}