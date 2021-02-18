/*
** EPITECH PROJECT, 2018
** OOP_arcade_2018
** File description:
** PacmanGhostYellow.cpp
*/

#include <iostream>
#include "PacmanGhostYellow.hpp"

arcade::PacmanGhostYellow::~PacmanGhostYellow()
{
}

arcade::PacmanGhostYellow::PacmanGhostYellow(const arcade::Vector &pos,
    int wait, const std::vector<std::string> &map
)
    : PacmanGhost(pos, ARCADE_YELLOW, wait), _nextCheckpoint(0)
{
    for (unsigned int i = 0; i < map.size() && i < 21; ++i) {
        for (unsigned int j = 0; j < map[i].size() && j < 21; ++j) {
            if (map[i][j] == '0')
                _checkpoint.emplace_back(Vector((int)j, (int)i));
        }
    }
}

void arcade::PacmanGhostYellow::chase(const std::vector<std::string> &map)
{
    if (_position == _checkpoint[_nextCheckpoint]) {
        ++_nextCheckpoint;
        if (_checkpoint.size() <= _nextCheckpoint)
            _nextCheckpoint = 0;
    }
    comparePosition(_checkpoint[_nextCheckpoint]);
    _move.x *= -1;
    _move.y *= -1;
    PacmanGhost::fleePacamn(map);
}
