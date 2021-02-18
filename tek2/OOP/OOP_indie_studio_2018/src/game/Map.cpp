/*
** EPITECH PROJECT, 2018
** OOP_indie_studio_2018
** File description:
** Map.cpp
*/

#include <iostream>
#include <ctime>
#include <cstdlib>
#include "Map.hpp"

Map::Map()
{
    std::vector<BlockType> temp;
    for (std::size_t width = 0; width < MAP_WIDTH; ++width)
        temp.emplace_back(BLOCK_UNBREAKABLE);
    for (std::size_t height = 0; height < MAP_HEIGHT; ++height)
        _map.emplace_back(temp);
}

Map::Map(const Map &copy)
    : _map(copy.getMap())
{
}

std::vector<std::vector<BlockType>> Map::getMap() const
{
    return _map;
}

Map &Map::operator=(const Map &copy)
{
    _map = copy.getMap();
    return *this;
}

void Map::generator(Block *map, MapType type)
{
    switch (type) {
    case MAP_CLASSIC:
        classicMap();
        break;
    case MAP_COMPLEX:
        complexeMap();
        break;
    default:
        classicMap();
        break;
    }
    genMapStarterPack();
    for (std::size_t y = 0; y < MAP_HEIGHT; ++y) {
        for (std::size_t x = 0; x < MAP_WIDTH; ++x) {
            map[y * MAP_WIDTH + x].type =_map[y][x];
        }
    }
}

void Map::genMapStarterPack()
{
    _map[0][0] = BLOCK_NONE;
    _map[1][0] = BLOCK_NONE;
    _map[0][1] = BLOCK_NONE;
    _map[0][MAP_WIDTH - 1] = BLOCK_NONE;
    _map[1][MAP_WIDTH - 1] = BLOCK_NONE;
    _map[0][MAP_WIDTH - 2] = BLOCK_NONE;
    _map[MAP_HEIGHT - 1][0] = BLOCK_NONE;
    _map[MAP_HEIGHT - 2][0] = BLOCK_NONE;
    _map[MAP_HEIGHT - 1][1] = BLOCK_NONE;
    _map[MAP_HEIGHT - 1][MAP_WIDTH - 1] = BLOCK_NONE;
    _map[MAP_HEIGHT - 2][MAP_WIDTH - 1] = BLOCK_NONE;
    _map[MAP_HEIGHT - 1][MAP_WIDTH - 2] = BLOCK_NONE;
    #ifdef DEBUG
    std::cout << "Map created:" << std::endl;
    for (std::size_t y = 0; y < MAP_HEIGHT; ++y) {
        for (std::size_t x = 0; x < MAP_WIDTH; ++x) {
            std::cout << _map[y][x];
        }
        std::cout << std::endl;
    }
    #endif
}

void Map::classicMap()
{
    for (std::size_t y = 0, h = MAP_HEIGHT - 1; y <= h; ++y, --h) {
        for (std::size_t x = 0, w = MAP_WIDTH - 1; x <= w; ++x, --w) {
            if (!(y % 2)) {
                if (!(x % 2))
                    _map[y][x] = BLOCK_BREAKABLE;
                else
                    _map[y][x] = BLOCK_NONE;
            } else {
                if (!(x % 2))
                    _map[y][x] = BLOCK_NONE;
                else
                    _map[y][x] = BLOCK_UNBREAKABLE;
            }
            _map[y][w] = _map[y][x];
            _map[h][x] = _map[y][x];
            _map[h][w] = _map[y][x];
        }
    }
}

void Map::complexeMap()
{
    bool (Map::*tryToDig[4])(const std::tuple<int, int> &
    ) const = {&Map::tryToDigDown, &Map::tryToDigUp, &Map::tryToDigRight,
        &Map::tryToDigLeft};
    void (Map::*dig[4])(std::deque<std::tuple<int, int>> &
    ) = {&Map::digDown, &Map::digUp, &Map::digRight, &Map::digLeft};

    std::size_t direction = 0;
    std::deque<std::tuple<int, int>> minor;
    minor.emplace_back(std::make_tuple(0, 0));

    while (!minor.empty()) {
        direction = std::rand() % 4;
        if ((this->*tryToDig[direction])(minor.front())) {
            (this->*dig[direction])(minor);
        } else {
            for (std::size_t i = 0; i < 4; ++i) {
                if ((this->*tryToDig[i])(minor.front())) {
                    (this->*dig[i])(minor);
                    direction = 5;
                    break;
                }
            }
            if (direction != 5)
                minor.pop_front();
        }
    }
    for (std::size_t y = 0, h = MAP_HEIGHT - 1; y <= h; ++y, --h) {
        for (std::size_t x = 0, w = MAP_WIDTH - 1; x <= w; ++x, --w) {
            if (!(std::rand() % 3))
                _map[y][x] = BLOCK_BREAKABLE;
            _map[y][w] = _map[y][x];
            _map[h][x] = _map[y][x];
            _map[h][w] = _map[y][x];
        }
    }
}

bool Map::tryToDigUp(const std::tuple<int, int> &pos) const
{
    if (std::get<0>(pos) - 1 >= 0 &&
        _map[std::get<0>(pos) - 1][std::get<1>(pos)] != BLOCK_NONE) {
        if (std::get<0>(pos) - 2 >= 0)
            if (_map[std::get<0>(pos) - 2][std::get<1>(pos)] == BLOCK_NONE)
                return false;
        if (std::get<1>(pos) - 1 >= 0)
            if (_map[std::get<0>(pos) - 1][std::get<1>(pos) - 1] == BLOCK_NONE)
                return false;
        if (std::get<1>(pos) + 1 <= MAP_WIDTH / 2)
            if (_map[std::get<0>(pos) - 1][std::get<1>(pos) + 1] == BLOCK_NONE)
                return false;
    } else
        return false;
    return true;
}

bool Map::tryToDigDown(const std::tuple<int, int> &pos) const
{
    if (std::get<0>(pos) + 1 <= MAP_HEIGHT / 2 &&
        _map[std::get<0>(pos) + 1][std::get<1>(pos)] != BLOCK_NONE) {
        if (std::get<0>(pos) + 2 <= MAP_HEIGHT / 2)
            if (_map[std::get<0>(pos) + 2][std::get<1>(pos)] == BLOCK_NONE)
                return false;
        if (std::get<1>(pos) - 1 >= 0)
            if (_map[std::get<0>(pos) + 1][std::get<1>(pos) - 1] == BLOCK_NONE)
                return false;
        if (std::get<1>(pos) + 1 <= MAP_WIDTH / 2)
            if (_map[std::get<0>(pos) + 1][std::get<1>(pos) + 1] == BLOCK_NONE)
                return false;
    } else
        return false;
    return true;
}

bool Map::tryToDigLeft(const std::tuple<int, int> &pos) const
{
    if (std::get<1>(pos) - 1 >= 0 &&
        _map[std::get<0>(pos)][std::get<1>(pos) - 1] != BLOCK_NONE) {
        if (std::get<1>(pos) - 2 >= 0)
            if (_map[std::get<0>(pos)][std::get<1>(pos) - 2] == BLOCK_NONE)
                return false;
        if (std::get<0>(pos) - 1 >= 0)
            if (_map[std::get<0>(pos) - 1][std::get<1>(pos) - 1] == BLOCK_NONE)
                return false;
        if (std::get<0>(pos) + 1 <= MAP_HEIGHT / 2)
            if (_map[std::get<0>(pos) + 1][std::get<1>(pos) - 1] == BLOCK_NONE)
                return false;
    } else
        return false;
    return true;
}

bool Map::tryToDigRight(const std::tuple<int, int> &pos) const
{
    if (std::get<1>(pos) + 1 <= MAP_WIDTH / 2 &&
        _map[std::get<0>(pos)][std::get<1>(pos) + 1] != BLOCK_NONE) {
        if (std::get<1>(pos) + 2 <= MAP_WIDTH / 2)
            if (_map[std::get<0>(pos)][std::get<1>(pos) + 2] == BLOCK_NONE)
                return false;
        if (std::get<0>(pos) - 1 >= 0)
            if (_map[std::get<0>(pos) - 1][std::get<1>(pos) + 1] == BLOCK_NONE)
                return false;
        if (std::get<0>(pos) + 1 <= MAP_HEIGHT / 2)
            if (_map[std::get<0>(pos) + 1][std::get<1>(pos) + 1] == BLOCK_NONE)
                return false;
    } else
        return false;
    return true;
}

void Map::digUp(std::deque<std::tuple<int, int>> &minor)
{
    minor.push_front(std::make_tuple(std::get<0>(minor.front()) - 1,
        std::get<1>(minor.front())));
    _map[std::get<0>(minor.front())][std::get<1>(minor.front())] = BLOCK_NONE;
}

void Map::digDown(std::deque<std::tuple<int, int>> &minor)
{
    minor.push_front(std::make_tuple(std::get<0>(minor.front()) + 1,
        std::get<1>(minor.front())));
    _map[std::get<0>(minor.front())][std::get<1>(minor.front())] = BLOCK_NONE;
}

void Map::digLeft(std::deque<std::tuple<int, int>> &minor)
{
    minor.push_front(std::make_tuple(std::get<0>(minor.front()),
        std::get<1>(minor.front()) - 1));
    _map[std::get<0>(minor.front())][std::get<1>(minor.front())] = BLOCK_NONE;
}

void Map::digRight(std::deque<std::tuple<int, int>> &minor)
{
    minor.push_front(std::make_tuple(std::get<0>(minor.front()),
        std::get<1>(minor.front()) + 1));
    _map[std::get<0>(minor.front())][std::get<1>(minor.front())] = BLOCK_NONE;
}
