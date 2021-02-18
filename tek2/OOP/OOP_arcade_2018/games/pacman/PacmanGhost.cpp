#include <utility>

/*
** EPITECH PROJECT, 2018
** OOP_arcade_2018
** File description:
** PacmanGhost.cpp
*/


#include "PacmanGhost.hpp"

namespace arcade {
    PacmanGhost::~PacmanGhost()
    {
    }

    PacmanGhost::PacmanGhost(Vector position, Color color, int wait)
        : _position(position), _startPos(position), _direction(0), _dead(false),
        _eatable(false), _color(color), _nbWait(wait), _move(Vector(0, 0))
    {
        _wait = std::chrono::high_resolution_clock::now();
        _timeEatable = std::chrono::high_resolution_clock::now();
        _update = std::chrono::high_resolution_clock::now();
    }

    Color PacmanGhost::getColor() const
    {
        return _color;
    }

    Vector PacmanGhost::getPosition() const
    {
        return _position;
    }

    bool PacmanGhost::getState() const
    {
        return _eatable;
    }

    bool PacmanGhost::getDeath() const
    {
        return _dead;
    }

    void PacmanGhost::setState(bool state)
    {
        auto wait = std::chrono::duration<double, std::milli>(
            std::chrono::high_resolution_clock::now() - _wait).count();
        if (_dead || wait < _nbWait * 1000.0)
            return;
        if (state)
            _timeEatable = std::chrono::high_resolution_clock::now();
        _eatable = state;
    }

    void PacmanGhost::setDeath(bool life)
    {
        _dead = life;
    }

    void PacmanGhost::reset()
    {
        _position = _startPos;
        _direction = 0;
        _dead = false;
        _eatable = false;
        _wait = std::chrono::high_resolution_clock::now();
        _timeEatable = std::chrono::high_resolution_clock::now();
        _update = std::chrono::high_resolution_clock::now();
    }

    void PacmanGhost::display(IGraphic &graphic) const
    {
        Color color = _color;

        if (_dead) {
            color = ARCADE_BLACK;
        } else if (_eatable)
            color = ARCADE_CYAN;
        graphic.printText(Vector(_position.x + 22, _position.y + 15), "--",
            ARCADE_WHITE, color);
    }

    Vector PacmanGhost::update(std::vector<std::string> map)
    {
        auto wait = std::chrono::duration<double, std::milli>(
            std::chrono::high_resolution_clock::now() - _wait).count();
        if (wait < _nbWait * 1000.0)
            return _position;
        auto eatable = std::chrono::duration<double, std::milli>(
            std::chrono::high_resolution_clock::now() - _timeEatable).count();
        if (eatable >= 10 * 1000.0)
            _eatable = false;
        auto update = std::chrono::duration<double, std::milli>(
            std::chrono::high_resolution_clock::now() - _update).count();
        if (update < (_eatable && (!_dead) ? 250.0 : 0))
            return _position;
        else
            _update = std::chrono::high_resolution_clock::now();
        switch (_direction) {
        case 1:
            _position.y -= verifMove(Vector(_position.x, _position.y - 1), map);
            break;
        case 2:
            _position.y += verifMove(Vector(_position.x, _position.y + 1), map);
            break;
        case 3:
            _position.x += verifMove(Vector(_position.x + 1, _position.y), map);
            break;
        case 4:
            _position.x -= verifMove(Vector(_position.x - 1, _position.y), map);
            break;
        default:
            break;
        }
        if (_position == _startPos) {
            _eatable = false;
            _dead = false;
        }
        return _position;
    }

    void PacmanGhost::move(const std::vector<std::string> &map)
    {
        if (_dead)
            comeBackHome(map);
        else if (_eatable)
            fleePacamn(map);
        else
            chase(map);
    }

    void PacmanGhost::move(const std::vector<std::string> &map,
        const Vector &pacman, int direction
    )
    {
        (void)pacman;
        (void)direction;
        move(map);
    }

    void PacmanGhost::fleePacamn(const std::vector<std::string> &map)
    {
        switch (_direction) {
        case 1:
            if (!verifDirection(Vector(_position.x - 1, _position.y), map) &&
                !verifDirection(Vector(_position.x + 1, _position.y), map) &&
                !verifDirection(Vector(_position.x, _position.y - 1), map)) {
                _direction = 2;
            } else {
                if (_move.x == 1 &&
                    verifDirection(Vector(_position.x + 1, _position.y), map))
                    _direction = 3;
                else if (_move.x == -1 &&
                    verifDirection(Vector(_position.x - 1, _position.y), map))
                    _direction = 4;
                else if (!verifDirection(Vector(_position.x, _position.y - 1),
                    map)) {
                    if (verifDirection(Vector(_position.x + 1, _position.y),
                        map))
                        _direction = 3;
                    else if (verifDirection(
                        Vector(_position.x - 1, _position.y), map))
                        _direction = 4;
                }
            }
            break;
        case 2:
            if (!verifDirection(Vector(_position.x - 1, _position.y), map) &&
                !verifDirection(Vector(_position.x + 1, _position.y), map) &&
                !verifDirection(Vector(_position.x, _position.y + 1), map)) {
                _direction = 1;
            } else {
                if (_move.x == 1 &&
                    verifDirection(Vector(_position.x + 1, _position.y), map))
                    _direction = 3;
                else if (_move.x == -1 &&
                    verifDirection(Vector(_position.x - 1, _position.y), map))
                    _direction = 4;
                else if (!verifDirection(Vector(_position.x, _position.y + 1),
                    map)) {
                    if (verifDirection(Vector(_position.x + 1, _position.y),
                        map))
                        _direction = 3;
                    else if (verifDirection(
                        Vector(_position.x - 1, _position.y), map))
                        _direction = 4;
                }
            }
            break;
        case 3:
            if (!verifDirection(Vector(_position.x, _position.y - 1), map) &&
                !verifDirection(Vector(_position.x, _position.y + 1), map) &&
                !verifDirection(Vector(_position.x + 1, _position.y), map)) {
                _direction = 4;
            } else {
                if (_move.y == 1 &&
                    verifDirection(Vector(_position.x, _position.y + 1), map))
                    _direction = 2;
                else if (_move.y == -1 &&
                    verifDirection(Vector(_position.x, _position.y - 1), map))
                    _direction = 1;
                else if (!verifDirection(Vector(_position.x + 1, _position.y),
                    map)) {
                    if (verifDirection(Vector(_position.x, _position.y - 1),
                        map))
                        _direction = 1;
                    else if (verifDirection(
                        Vector(_position.x, _position.y + 1), map))
                        _direction = 2;
                }
            }
            break;
        case 4:
            if (!verifDirection(Vector(_position.x, _position.y - 1), map) &&
                !verifDirection(Vector(_position.x, _position.y + 1), map) &&
                !verifDirection(Vector(_position.x - 1, _position.y), map)) {
                _direction = 3;
            } else {
                if (_move.y == 1 &&
                    verifDirection(Vector(_position.x, _position.y + 1), map))
                    _direction = 2;
                else if (_move.y == -1 &&
                    verifDirection(Vector(_position.x, _position.y - 1), map))
                    _direction = 1;
                else if (!verifDirection(Vector(_position.x - 1, _position.y),
                    map)) {
                    if (verifDirection(Vector(_position.x, _position.y - 1),
                        map))
                        _direction = 1;
                    else if (verifDirection(
                        Vector(_position.x, _position.y + 1), map))
                        _direction = 2;
                }
            }
            break;
        default:
            _direction = 1;
            break;
        }
    }

    void PacmanGhost::comeBackHome(const std::vector<std::string> &map)
    {
        comparePosition(_startPos);
        _move.x *= -1;
        _move.y *= -1;
        fleePacamn(map);
    }

    void PacmanGhost::chase(const std::vector<std::string> &map)
    {
        switch (_direction) {
        case 1:
            if (!verifDirection(Vector(_position.x - 1, _position.y), map) &&
                !verifDirection(Vector(_position.x + 1, _position.y), map) &&
                !verifDirection(Vector(_position.x, _position.y - 1), map)) {
                _direction = 2;
            } else {
                int i = std::rand() % 2;
                if (i == 0) {
                    if (verifDirection(Vector(_position.x - 1, _position.y),
                        map))
                        _direction = 4;
                    else if (verifDirection(
                        Vector(_position.x + 1, _position.y), map))
                        _direction = 3;
                } else {
                    if (verifDirection(Vector(_position.x + 1, _position.y),
                        map))
                        _direction = 3;
                    else if (verifDirection(
                        Vector(_position.x - 1, _position.y), map))
                        _direction = 4;
                }
            }
            break;
        case 2:
            if (!verifDirection(Vector(_position.x - 1, _position.y), map) &&
                !verifDirection(Vector(_position.x + 1, _position.y), map) &&
                !verifDirection(Vector(_position.x, _position.y + 1), map)) {
                _direction = 1;
            } else {
                int i = std::rand() % 2;
                if (i == 0) {
                    if (verifDirection(Vector(_position.x + 1, _position.y),
                        map))
                        _direction = 3;
                    else if (verifDirection(
                        Vector(_position.x - 1, _position.y), map))
                        _direction = 4;
                } else {
                    if (verifDirection(Vector(_position.x - 1, _position.y),
                        map))
                        _direction = 4;
                    if (verifDirection(Vector(_position.x + 1, _position.y),
                        map))
                        _direction = 3;
                }
            }
            break;
        case 3:
            if (!verifDirection(Vector(_position.x, _position.y - 1), map) &&
                !verifDirection(Vector(_position.x, _position.y + 1), map) &&
                !verifDirection(Vector(_position.x + 1, _position.y), map)) {
                _direction = 4;
            } else {
                int i = std::rand() % 2;
                if (i == 0) {
                    if (verifDirection(Vector(_position.x, _position.y - 1),
                        map))
                        _direction = 1;
                    else if (verifDirection(
                        Vector(_position.x, _position.y + 1), map))
                        _direction = 2;
                } else {
                    if (verifDirection(Vector(_position.x, _position.y + 1),
                        map))
                        _direction = 2;
                    else if (verifDirection(
                        Vector(_position.x, _position.y - 1), map))
                        _direction = 1;
                }
            }
            break;
        case 4:
            if (!verifDirection(Vector(_position.x, _position.y - 1), map) &&
                !verifDirection(Vector(_position.x, _position.y + 1), map) &&
                !verifDirection(Vector(_position.x - 1, _position.y), map)) {
                _direction = 3;
            } else {
                int i = std::rand() % 2;
                if (i == 0) {
                    if (verifDirection(Vector(_position.x, _position.y + 1),
                        map))
                        _direction = 2;
                    else if (verifDirection(
                        Vector(_position.x, _position.y - 1), map))
                        _direction = 1;
                } else {
                    if (verifDirection(Vector(_position.x, _position.y - 1),
                        map))
                        _direction = 1;
                    else if (verifDirection(
                        Vector(_position.x, _position.y + 1), map))
                        _direction = 2;
                }
            }
            break;
        default:
            _direction = std::rand() % 4 + 1;
            break;
        }
    }

    int PacmanGhost::verifMove(Vector pos, std::vector<std::string> map) const
    {
        if (pos.y < 0 || pos.y > 20 || pos.x < 0 || pos.x > 20)
            return 0;
        else if (map[pos.y][pos.x] != '#' && map[pos.y][pos.x] != 'g') {
            return 1;
        }
        return 0;
    }

    int PacmanGhost::verifDirection(Vector pos, std::vector<std::string> map
    ) const
    {
        if (pos.y < 0 || pos.y > 20 || pos.x < 0 || pos.x > 20)
            return 0;
        if (map[pos.y][pos.x] != '#' && map[pos.y][pos.x] != 'g')
            return 1;
        return 0;
    }

    void PacmanGhost::teleporte(std::vector<std::string> map)
    {
        if (map[_position.y][_position.x] <= '0' ||
            map[_position.y][_position.x] > '9')
            return;
        for (unsigned int i = 0; i < map.size() && i < 21; ++i) {
            for (unsigned int j = 0; j < map[i].size() && j < 21; ++j) {
                if (map[i][j] == map[_position.y][_position.x] &&
                    ((_position.x != (int)j && _position.y != (int)i) ||
                        (_position.x == (int)j && _position.y != (int)i) ||
                        (_position.x != (int)j && _position.y == (int)i))) {
                    _position = {(int)j, (int)i};
                    return;
                }
            }
        }
    }

    void PacmanGhost::comparePosition(Vector pacman)
    {
        if (_position.x < pacman.x)
            _move.x = -1;
        else if (_position.x > pacman.x)
            _move.x = 1;
        else
            _move.x = 0;
        if (_position.y < pacman.y)
            _move.y = -1;
        else if (_position.y > pacman.y)
            _move.y = 1;
        else
            _move.y = 0;
    }
};