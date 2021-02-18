/*
** EPITECH PROJECT, 2018
** OOP_arcade_2018
** File description:
** PacmanGhostPink.cpp
*/

#include "PacmanGhostPink.hpp"

namespace arcade {

    PacmanGhostPink::~PacmanGhostPink()
    {
    }

    PacmanGhostPink::PacmanGhostPink(const Vector &pos, int wait)
        : PacmanGhost(pos, ARCADE_MAGENTA, wait)
    {
    }

    void PacmanGhostPink::chase(const std::vector<std::string> &map)
    {
        _move.x *= -1;
        _move.y *= -1;
        PacmanGhost::fleePacamn(map);
    }

    void PacmanGhostPink::move(const std::vector<std::string> &map,
        const Vector &pacman, int direction
    )
    {
        if (_dead)
            comeBackHome(map);
        else if (_eatable)
            fleePacamn(map);
        else {
            anticipatePacmanMove(map, pacman, direction);
            chase(map);
        }
    }

    void PacmanGhostPink::anticipatePacmanMove(
        const std::vector<std::string> &map, const Vector &pacman, int direction
    )
    {
        _move.x = 0;
        _move.y = 0;
        switch (direction) {
        case 1:
            for (std::size_t i = 0;
                pacman.y - i > 0 && map[pacman.y - i][pacman.x] != '#'; ++i) {
                if (verifDirection(Vector(pacman.x + 1, pacman.y - i), map)) {
                    comparePosition(Vector(pacman.x + 1, pacman.y - i));
                    return;
                } else if (verifDirection(Vector(pacman.x - 1, pacman.y - i),
                    map)) {
                    comparePosition(Vector(pacman.x - 1, pacman.y - i));
                    return;
                }
            }
            break;
        case 2:
            for (std::size_t i = 0; pacman.y + i < map.size() &&
                map[pacman.y + i][pacman.x] != '#'; ++i) {
                if (verifDirection(Vector(pacman.x + 1, pacman.y + i), map)) {
                    comparePosition(Vector(pacman.x + 1, pacman.y + i));
                    return;
                } else if (verifDirection(Vector(pacman.x - 1, pacman.y + i),
                    map)) {
                    comparePosition(Vector(pacman.x - 1, pacman.y + i));
                    return;
                }
            }
            break;
        case 3:
            for (std::size_t i = 0; pacman.x + i < map[pacman.y].size() &&
                map[pacman.y][pacman.x + i] != '#'; ++i) {
                if (verifDirection(Vector(pacman.x + i, pacman.y + 1), map)) {
                    comparePosition(Vector(pacman.x + i, pacman.y + 1));
                    return;
                } else if (verifDirection(Vector(pacman.x + i, pacman.y - 1),
                    map)) {
                    comparePosition(Vector(pacman.x + i, pacman.y - 1));
                    return;
                }
            }
            break;
        case 4:
            for (std::size_t i = 0;
                pacman.x - i > 0 && map[pacman.y][pacman.x - i] != '#'; ++i) {
                if (verifDirection(Vector(pacman.x - i, pacman.y + 1), map)) {
                    comparePosition(Vector(pacman.x - i, pacman.y + 1));
                    return;
                } else if (verifDirection(Vector(pacman.x - i, pacman.y - 1),
                    map)) {
                    comparePosition(Vector(pacman.x - i, pacman.y - 1));
                    return;
                }
            }
            break;
        default:
            break;
        }
    }
}