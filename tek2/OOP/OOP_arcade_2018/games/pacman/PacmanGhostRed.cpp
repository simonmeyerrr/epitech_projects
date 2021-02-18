/*
** EPITECH PROJECT, 2018
** OOP_arcade_2018
** File description:
** PacmanGhostRed.cpp
*/

#include "PacmanGhostRed.hpp"

namespace arcade {

    PacmanGhostRed::~PacmanGhostRed()
    {
    }

    PacmanGhostRed::PacmanGhostRed(const Vector &pos, int wait)
        : PacmanGhost(pos, ARCADE_RED, wait)
    {
    }

    void PacmanGhostRed::chase(const std::vector<std::string> &map)
    {
        _move.x *= -1;
        _move.y *= -1;
        PacmanGhost::fleePacamn(map);
    }
}