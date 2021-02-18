/*
** EPITECH PROJECT, 2018
** OOP_arcade_2018
** File description:
** Pacman.cpp
*/

#include <memory>
#include <regex>
#include <fstream>
#include <dirent.h>
#include <iostream>
#include "PacmanGhostPink.hpp"
#include "PacmanGhostYellow.hpp"
#include "Pacman.hpp"

void __attribute__((constructor)) ctor()
{
}

void __attribute__((destructor)) dtor()
{
}

extern "C" arcade::IGame *init()
{
    return new arcade::Pacman();
}

namespace arcade {

    static const Color colors[] = {ARCADE_WHITE, ARCADE_BLACK, ARCADE_RED,
        ARCADE_BLUE, ARCADE_GREEN, ARCADE_YELLOW, ARCADE_MAGENTA, ARCADE_CYAN};

    MapPacman::MapPacman(const std::string &path)
        : _name(path.substr(20, path.size() - 24))
    {
        std::ifstream in(path);
        if (!in)
            return;
        std::string line;
        while (std::getline(in, line))
            _map.push_back(line);
    }

    std::string MapPacman::getName() const
    {
        return (_name);
    }

    std::vector<std::string> MapPacman::getMap() const
    {
        return (_map);
    }

    void MapPacman::display(IGraphic &graphic) const
    {
        for (unsigned int i = 0; i < _map.size() && i < 21; ++i) {
            for (unsigned int j = 0; j < _map[i].size() && j < 21; ++j) {
                if (_map[i][j] == '#')
                    graphic.printPixel(Vector(j + 22, i + 15), ARCADE_BLUE);
                else if (_map[i][j] == '-')
                    graphic.printText(Vector(j + 22, i + 15), "--",
                        ARCADE_GREEN, ARCADE_TRANSPARENT);
                else if (_map[i][j] == '*' || _map[i][j] == '0')
                    graphic.printText(Vector(j + 22, i + 15),
                        std::string(1, _map[i][j]), ARCADE_WHITE,
                        ARCADE_TRANSPARENT);
            }
        }
    }

    Pacman::~Pacman()
    {
        for (auto it : _ghost)
            delete it;
    }

    Pacman::Pacman()
        : _menu(0), _pacman({0, 0}), _direction(0), _saveDirection(0),
        _maxScore(0), _score(0), _selectMap(0), _selectMenu(0)
    {
        std::ifstream in("./assets/pacman.txt");
        if (!in)
            return;
        std::string line;
        while (std::getline(in, line))
            _art.push_back(line);
        std::ifstream i("./assets/pacman_pause.txt");
        if (!i)
            return;
        while (std::getline(i, line))
            _artPause.push_back(line);
        loadMaps();
    }

    void Pacman::setUsername(const std::string &username)
    {
        _username = username;
    }

    Event Pacman::manageEvent(IGraphic &graphic)
    {
        Event e = graphic.getEvent();

        switch (_menu) {
        case 1:
            eventPacman(e);
            break;
        case 2:
            eventPause(e);
            break;
        case 3:
            eventEnd(e);
            break;
        default:
            eventMenu(e);
        }
        return (e);
    }

    void Pacman::updateGame()
    {
        if (_menu == 1)
            updatePacman();
    }

    void Pacman::displayWindow(IGraphic &graphic)
    {
        graphic.clearWindow(ARCADE_BLACK);
        for (unsigned int i = 0; i < _art.size() && i < 45; ++i) {
            for (unsigned int j = 0; j < _art[i].size() && j < 80; ++j) {
                if (_art[i][j] >= '1' && _art[i][j] <= '8')
                    graphic.printPixel(Vector(j, i), colors[_art[i][j] - '1']);
            }
        }
        switch (_menu) {
        case 1:
            displayPacman(graphic);
            break;
        case 2:
            displayPause(graphic);
            break;
        case 3:
            displayEnd(graphic);
            break;
        default:
            displayMenu(graphic);
        }
        graphic.displayWindow();
    }

    void Pacman::loadMaps()
    {
        _selectMap = 0;
        _maps.clear();
        std::string path = "./assets/";
        std::regex reg("pacman_map_[a-z_0-9]+\\.txt");
        DIR *dir = opendir(path.c_str());
        struct dirent *ent;
        if (dir == NULL)
            return;
        ent = readdir(dir);
        while (ent != NULL) {
            std::string file = std::string(ent->d_name);
            if (std::regex_match(file, reg))
                _maps.push_back(MapPacman(path + file));
            ent = readdir(dir);
        }
        closedir(dir);
    }

    void Pacman::startGame()
    {
        _life = 3;
        _update = std::chrono::high_resolution_clock::now();
        _time = std::chrono::high_resolution_clock::now();
        _ghost.clear();
        _menu = 1;
        _direction = 0;
        _saveDirection = 0;
        _score = 0;
        _maxScore = 0;
        _selectMenu = 0;
        _useMap = _maps[_selectMap].getMap();
        _usePosMap = _useMap;
        std::srand(static_cast<unsigned int>(std::time(nullptr)));
        for (unsigned int i = 0; i < _useMap.size() && i < 21; ++i) {
            for (unsigned int j = 0; j < _useMap[i].size() && j < 21; ++j) {
                if (_useMap[i][j] == 'p') {
                    _pacman = {(int)j, (int)i};
                    _startPacman = _pacman;
                } else if (_useMap[i][j] == '*' || _useMap[i][j] == '0') {
                    _maxScore++;
                } else if (_useMap[i][j] == '-') {
                    _ghost.push_back(
                        new PacmanGhostRed(Vector((int)j, (int)i), 10));
                } else if (_useMap[i][j] == 'y') {
                    _ghost.push_back(
                        new PacmanGhostYellow(Vector((int)j, (int)i), 15,
                            _useMap));
                } else if (_useMap[i][j] == 'm') {
                    _ghost.push_back(
                        new PacmanGhostPink(Vector((int)j, (int)i), 20));
                } else if (_useMap[i][j] == 'g') {
                    _ghost.push_back(
                        new PacmanGhost(Vector((int)j, (int)i), ARCADE_GREEN,
                            30));
                }
            }
        }
    }

    void Pacman::resetGame()
    {
        --_life;
        _update = std::chrono::high_resolution_clock::now();
        _direction = 0;
        _saveDirection = 0;
        _pacman = _startPacman;
        for (auto it : _ghost)
            it->reset();
    }

    void Pacman::eventMenu(Event e)
    {
        if (e == ARCADE_KEY_UP)
            _selectMap = (_selectMap == 0 ? _maps.size() - 1 : _selectMap - 1);
        if (e == ARCADE_KEY_DOWN)
            _selectMap = (_selectMap == _maps.size() - 1 ? 0 : _selectMap + 1);
        if (e == ARCADE_KEY_SPACE)
            loadMaps();
        if (e == ARCADE_KEY_ENTER && _maps.size() > _selectMap)
            startGame();
    }

    void Pacman::eventPacman(Event e)
    {
        if (_score == _maxScore) {
            addScore();
            getScore();
            _menu = 3;
            return;
        } else if (e == ARCADE_KEY_SPACE) {
            _menu = 2;
            _pause = std::chrono::high_resolution_clock::now();
        } else if (e == ARCADE_KEY_UP) {
            _direction = verifDirection(Vector(_pacman.x, _pacman.y - 1), 1);
            _saveDirection = 1;
        } else if (e == ARCADE_KEY_DOWN) {
            _direction = verifDirection(Vector(_pacman.x, _pacman.y + 1), 2);
            _saveDirection = 2;
        } else if (e == ARCADE_KEY_RIGHT) {
            _direction = verifDirection(Vector(_pacman.x + 1, _pacman.y), 3);
            _saveDirection = 3;
        } else if (e == ARCADE_KEY_LEFT) {
            _direction = verifDirection(Vector(_pacman.x - 1, _pacman.y), 4);
            _saveDirection = 4;
        }
    }

    void Pacman::eventPause(Event e)
    {
        if (e == ARCADE_KEY_SPACE ||
            (e == ARCADE_KEY_ENTER && _selectMenu == 0)) {
            _selectMenu = 0;

            _time += std::chrono::high_resolution_clock::now() - _pause;
            _menu = 1;
        } else if (e == ARCADE_KEY_ENTER) {
            _selectMenu = 0;
            _menu = 0;
        }
        if (e == ARCADE_KEY_UP || e == ARCADE_KEY_DOWN ||
            e == ARCADE_KEY_LEFT || e == ARCADE_KEY_RIGHT)
            _selectMenu = (_selectMenu == 0 ? 1 : 0);
    }

    void Pacman::eventEnd(Event e)
    {
        if (e == ARCADE_KEY_ENTER && _selectMenu == 0) {
            _selectMenu = 0;
            startGame();
            _menu = 1;
        } else if (e == ARCADE_KEY_ENTER) {
            _selectMenu = 0;
            _menu = 0;
        }
        if (e == ARCADE_KEY_UP || e == ARCADE_KEY_DOWN ||
            e == ARCADE_KEY_LEFT || e == ARCADE_KEY_RIGHT)
            _selectMenu = (_selectMenu == 0 ? 1 : 0);
    }

    void Pacman::updatePacman()
    {
        auto update = std::chrono::duration<double, std::milli>(
            std::chrono::high_resolution_clock::now() - _update).count();
        if (update < 200.0)
            return;
        else {
            _update = std::chrono::high_resolution_clock::now();
        }
        verifPosition();
        for (auto it : _ghost) {
            Vector itPos = it->getPosition();
            Vector newItPos = it->update(_usePosMap);
            it->teleporte(_useMap);
            if (!(itPos == newItPos)) {
                _usePosMap[itPos.y][itPos.x] = ' ';
                _usePosMap[newItPos.y][newItPos.x] = 'g';
            }
        }
        verifPosition();
        verifSaveDirection();
        if (_useMap[_pacman.y][_pacman.x] == '*') {
            _useMap[_pacman.y][_pacman.x] = ' ';
            ++_score;
        }
        switch (_direction) {
        case 1:
            _pacman.y -= verifMove(Vector(_pacman.x, _pacman.y - 1));
            break;
        case 2:
            _pacman.y += verifMove(Vector(_pacman.x, _pacman.y + 1));
            break;
        case 3:
            _pacman.x += verifMove(Vector(_pacman.x + 1, _pacman.y));
            break;
        case 4:
            _pacman.x -= verifMove(Vector(_pacman.x - 1, _pacman.y));
            break;
        default:
            break;
        }
        teleporte();
        for (auto it : _ghost) {
            it->comparePosition(_pacman);
            if (it->getColor() == ARCADE_MAGENTA)
                it->move(_usePosMap, _pacman, _direction);
            else
                it->move(_usePosMap);
        }
    }

    void Pacman::displayMenu(IGraphic &graphic)
    {
        graphic.printText(Vector(46, 19), "USERNAME:");
        graphic.printText(Vector(51, 19), _username, ARCADE_RED);
        graphic.printText(Vector(14, 42), "ESC: quit", ARCADE_BLACK,
            ARCADE_WHITE);
        graphic.printText(Vector(20, 42), "F1,F2,...: chose graphic mod",
            ARCADE_BLACK, ARCADE_WHITE);
        graphic.printText(Vector(36, 42), "SPACE: reload maps", ARCADE_BLACK,
            ARCADE_WHITE);
        graphic.printText(Vector(47, 42), "/\\ \\/: chose map", ARCADE_BLACK,
            ARCADE_WHITE);
        graphic.printText(Vector(57, 42), "ENTER: launch map", ARCADE_BLACK,
            ARCADE_WHITE);
        if (_maps.size() > _selectMap)
            _maps[_selectMap].display(graphic);
        graphic.printText(Vector(46, 23), "CHOOSE A MAP:");
        if (_maps.size() == 0) {
            graphic.printText(Vector(48, 29), "NO MAP AVAILABLE!", ARCADE_RED);
        }
        for (unsigned int i = 0; i < _maps.size(); ++i) {
            if (i != _selectMap)
                graphic.printText(Vector(48, i * 2 + 25), _maps[i].getName());
            else
                graphic.printText(Vector(48, i * 2 + 25), _maps[i].getName(),
                    ARCADE_WHITE, ARCADE_BLUE);
        }
    }

    void Pacman::displayPacman(IGraphic &graphic)
    {
        graphic.printText(Vector(46, 19), "USERNAME:");
        graphic.printText(Vector(51, 19), _username, ARCADE_RED);
        graphic.printText(Vector(46, 22), "SCORE:");
        graphic.printText(Vector(51, 22), std::to_string(_score), ARCADE_RED);
        graphic.printText(Vector(52, 22), " / " + std::to_string(_maxScore));
        graphic.printText(Vector(13, 42), "F1,F2,...: chose graphic mod",
            ARCADE_BLACK, ARCADE_WHITE);
        graphic.printText(Vector(32, 41), "  ^  ", ARCADE_BLACK, ARCADE_WHITE);
        graphic.printText(Vector(32, 42), "<-|->", ARCADE_BLACK, ARCADE_WHITE);
        graphic.printText(Vector(35, 42), "Use arrow key to move Pacman",
            ARCADE_BLACK, ARCADE_WHITE);
        graphic.printText(Vector(32, 43), "  v  ", ARCADE_BLACK, ARCADE_WHITE);
        graphic.printText(Vector(55, 42), "Press SPACE for pause", ARCADE_BLACK,
            ARCADE_WHITE);
        graphic.printText(Vector(46, 25), "LIFE:");
        for (int i = 0; i < _life; ++i)
            graphic.printPixel(Vector(50 + i * 2, 25), ARCADE_YELLOW);
        graphic.printText(Vector(46, 28), getTime());
        displayMap(graphic);
        for (auto it : _ghost)
            it->display(graphic);
        std::string str = " ";
        switch (_direction) {
        case 1:
            str = "\\/";
            break;
        case 2:
            str = "/\\";
            break;
        case 3:
            str = " <";
            break;
        case 4:
            str = "> ";
            break;
        default:
            break;
        }
        graphic.printText(Vector(_pacman.x + 22, _pacman.y + 15), str,
            ARCADE_BLACK, ARCADE_YELLOW);
    }

    void Pacman::displayPause(IGraphic &graphic)
    {
        graphic.printText(Vector(46, 19), "USERNAME:");
        graphic.printText(Vector(51, 19), _username, ARCADE_RED);
        graphic.printText(Vector(14, 42), "ESC: quit", ARCADE_BLACK,
            ARCADE_WHITE);
        graphic.printText(Vector(20, 42), "F1,F2,...: chose graphic mod",
            ARCADE_BLACK, ARCADE_WHITE);
        graphic.printText(Vector(36, 42), "SPACE: resume", ARCADE_BLACK,
            ARCADE_WHITE);
        graphic.printText(Vector(45, 42), "/\\ \\/: chose button", ARCADE_BLACK,
            ARCADE_WHITE);
        graphic.printText(Vector(55, 42), "ENTER: press button", ARCADE_BLACK,
            ARCADE_WHITE);
        for (unsigned int i = 1; i < _artPause.size() && i < 21; ++i) {
            for (unsigned int j = 1; j < _artPause[i].size() && j < 21; ++j) {
                if (_artPause[i][j] >= '1' && _artPause[i][j] <= '8')
                    graphic.printPixel(Vector(j + 21, i + 15),
                        colors[_artPause[i][j] - '1']);
            }
        }
        graphic.printText(Vector(46, 22), "SCORE:");
        graphic.printText(Vector(51, 22), std::to_string(_score), ARCADE_RED);
        graphic.printText(Vector(52, 22), "/ " + std::to_string(_maxScore));
        if (_selectMenu == 0) {
            graphic.printText(Vector(47, 32), "RESUME", ARCADE_WHITE,
                ARCADE_BLUE);
            graphic.printText(Vector(53, 32), "MENU");
        } else {
            graphic.printText(Vector(47, 32), "RESUME");
            graphic.printText(Vector(53, 32), "MENU", ARCADE_WHITE,
                ARCADE_BLUE);
        }
    }

    void Pacman::displayEnd(IGraphic &graphic)
    {
        if (_score != _maxScore)
            graphic.printText(Vector(49, 23), "You Lose");
        else
            graphic.printText(Vector(49, 23), "You Win");
        if (_selectMenu == 0) {
            graphic.printText(Vector(47, 27), "RESTART", ARCADE_WHITE,
                ARCADE_BLUE);
            graphic.printText(Vector(54, 27), "MENU");
        } else {
            graphic.printText(Vector(47, 27), "RESTART");
            graphic.printText(Vector(54, 27), "MENU", ARCADE_WHITE,
                ARCADE_BLUE);
        }
        for (size_t i = 0; i < _scores.size() && i < 11; i++) {
            graphic.printText(Vector(23, 20 + i), "|", ARCADE_GREEN,
                ARCADE_BLACK);
            graphic.printText(Vector(24, 20 + i), _scores[i][0], ARCADE_WHITE,
                ARCADE_BLACK);
            graphic.printText(Vector(31, 20 + i), _scores[i][1], ARCADE_WHITE,
                ARCADE_BLACK);
            if (_username == _scores[i][0])
                graphic.printText(Vector(31, 20 + i), _scores[i][1],
                    ARCADE_BLACK, ARCADE_WHITE);
        }
    }

    void Pacman::displayMap(IGraphic &graphic)
    {
        for (unsigned int i = 0; i < _useMap.size() && i < 21; ++i) {
            for (unsigned int j = 0; j < _useMap[i].size() && j < 21; ++j) {
                if (_useMap[i][j] == '#')
                    graphic.printPixel(Vector(j + 22, i + 15), ARCADE_BLUE);
                else if (_useMap[i][j] == '-')
                    graphic.printText(Vector(j + 22, i + 15), "--",
                        ARCADE_GREEN, ARCADE_TRANSPARENT);
                else if (_useMap[i][j] == '*')
                    graphic.printText(Vector(j + 22, i + 15), "*", ARCADE_WHITE,
                        ARCADE_TRANSPARENT);
                else if (_useMap[i][j] == '0')
                    graphic.printText(Vector(j + 22, i + 15), "0", ARCADE_WHITE,
                        ARCADE_TRANSPARENT);
            }
        }
    }

    int Pacman::verifMove(Vector pos)
    {
        if (pos.y < 0 || pos.y > 20 || pos.x < 0 || pos.x > 20)
            return 0;
        else if (_useMap[pos.y][pos.x] != '#' && _useMap[pos.y][pos.x] != '-') {
            return 1;
        }
        return 0;
    }

    int Pacman::verifDirection(Vector pos, int newway)
    {
        if (pos.y < 0 || pos.y > 20 || pos.x < 0 || pos.x > 20)
            return 0;
        else if (_useMap[pos.y][pos.x] != '#' && _useMap[pos.y][pos.x] != '-')
            return newway;
        return _direction;
    }

    void Pacman::verifSaveDirection()
    {
        switch (_saveDirection) {
        case 1:
            _direction = verifDirection(Vector(_pacman.x, _pacman.y - 1), 1);
            break;
        case 2:
            _direction = verifDirection(Vector(_pacman.x, _pacman.y + 1), 2);
            break;
        case 3:
            _direction = verifDirection(Vector(_pacman.x + 1, _pacman.y), 3);
            break;
        case 4:
            _direction = verifDirection(Vector(_pacman.x - 1, _pacman.y), 4);
            break;
        default:
            break;
        }
    }

    void Pacman::verifPosition()
    {
        for (auto it : _ghost) {
            if (_pacman == it->getPosition()) {
                if (it->getState()) {
                    it->setDeath(true);
                } else {
                    if (_life > 1)
                        resetGame();
                    else {
                        getScore();
                        _menu = 3;
                    }
                }
            }
        }
        if (_useMap[_pacman.y][_pacman.x] == '0') {
            _useMap[_pacman.y][_pacman.x] = ' ';
            ++_score;
            for (auto it : _ghost)
                it->setState(true);
        }
    }

    void Pacman::teleporte()
    {
        if (_useMap[_pacman.y][_pacman.x] <= '0' ||
            _useMap[_pacman.y][_pacman.x] > '9')
            return;
        for (unsigned int i = 0; i < _useMap.size() && i < 21; ++i) {
            for (unsigned int j = 0; j < _useMap[i].size() && j < 21; ++j) {
                if (_useMap[i][j] == _useMap[_pacman.y][_pacman.x] &&
                    ((_pacman.x != (int)j && _pacman.y != (int)i) ||
                        (_pacman.x == (int)j && _pacman.y != (int)i) ||
                        (_pacman.x != (int)j && _pacman.y == (int)i))) {
                    _pacman = {(int)j, (int)i};
                    return;
                }
            }
        }
    }

    std::string Pacman::getTime() const
    {
        std::chrono::time_point<std::chrono::system_clock> now = std::chrono::system_clock::now();
        int tmp = std::chrono::duration_cast<std::chrono::seconds>(
            now - _time).count();
        std::string buf = "";
        if (tmp / 60 < 10)
            buf += "0";
        buf += std::to_string(tmp / 60) + ":";
        if (tmp % 60 < 10)
            buf += "0";
        buf += std::to_string(tmp % 60);
        return (buf);
    }

    void Pacman::addScore() const
    {
        std::string file = (std::string("./assets/pacman_score_") +
            _maps[_selectMap].getName() + ".txt");
        std::ofstream out(file, std::ios_base::app);
        if (!out)
            return;
        if (!_username.empty())
            out << _username << " " << getTime() << std::endl;
        std::ifstream in(file);
        if (!in)
            return;
        std::ofstream score;
    }

    bool compareScore(std::vector<std::string> a, std::vector<std::string> b)
    {
        std::regex rgx("^([0-9]+):([0-9]+)");
        std::smatch rgxBuf;
        std::regex_search(a[1], rgxBuf, rgx);
        int aT = (60 * std::stoi(rgxBuf[1])) + (std::stoi(rgxBuf[2]));
        std::regex_search(b[1], rgxBuf, rgx);
        int bT = (60 * std::stoi(rgxBuf[1])) + (std::stoi(rgxBuf[2]));
        if (aT == bT)
            return (true);
        else
            return (aT < bT);
    }

    void Pacman::getScore()
    {
        _scores.clear();
        std::ifstream in(
            "./assets/pacman_score_" + _maps[_selectMap].getName() + ".txt");
        std::regex rgx("^([A-Z]+) ([0-9]+:[0-9]+)");
        std::smatch rgxBuf;
        std::string line;
        if (!in)
            return;
        while (std::getline(in, line)) {
            std::vector<std::string> tmp;
            if (std::regex_search(line, rgxBuf, rgx)) {
                for (size_t i = 1; i < 3; i++)
                    tmp.push_back(rgxBuf[i]);
                _scores.push_back(tmp);
            }
        }
        std::sort(_scores.begin(), _scores.end(), compareScore);
    }
}
