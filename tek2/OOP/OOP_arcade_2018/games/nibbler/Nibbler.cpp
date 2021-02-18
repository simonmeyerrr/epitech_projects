/*
** EPITECH PROJECT, 2018
** OOP_arcade_2018
** File description:
** Nibbler.cpp
*/

#include <memory>
#include <regex>
#include <string>
#include <iostream>
#include <fstream>
#include <dirent.h>
#include "Nibbler.hpp"

void __attribute__((constructor)) ctor()
{
}

void __attribute__((destructor)) dtor()
{
}

extern "C" arcade::IGame *init()
{
    return new arcade::Nibbler();
}

namespace arcade {
    const Color colors[] = {ARCADE_WHITE, ARCADE_BLACK, ARCADE_RED, ARCADE_BLUE,
        ARCADE_GREEN, ARCADE_YELLOW, ARCADE_MAGENTA, ARCADE_CYAN};

    MapNibbler::MapNibbler(const std::string &path)
        : _name(path.substr(21, path.size() - 25))
    {
        std::ifstream in(path);
        if (!in)
            return;
        std::string line;
        while (std::getline(in, line))
            _map.push_back(line);
    }

    std::string MapNibbler::getName() const
    {
        return (_name);
    }

    std::vector <std::string> MapNibbler::getMap() const
    {
        return (_map);
    }

    void MapNibbler::display(IGraphic &graphic) const
    {
        for (unsigned int i = 1; i < _map.size() && i < 21; i++) {
            for (unsigned int j = 1; j < _map[i].size() && j < 21; j++) {
                if (_map[i][j] == '#')
                    graphic.printPixel(Vector(j + 20, i + 15), ARCADE_BLUE);
            }
        }
    }

    Nibbler::~Nibbler()
    {
    }

    Nibbler::Nibbler()
        : _menu(0), _selectMap(0), _selectMenu(0), _update(0)
    {
        std::ifstream in("./assets/nibbler.txt");
        std::string line;
        while (in && std::getline(in, line))
            _art.push_back(line);

        std::ifstream in2("./assets/nibbler_pause.txt");
        while (in2 && std::getline(in2, line))
            _artPause.push_back(line);
        loadMaps();
    }

    void Nibbler::setUsername(const std::string &username)
    {
        _username = username;
    }

    Event Nibbler::manageEvent(IGraphic &graphic)
    {
        Event e = graphic.getEvent();

        switch (_menu) {
        case 1:
            eventNibbler(e);
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

    void Nibbler::updateGame()
    {
        if (_menu == 1)
            updateNibbler();
    }

    void Nibbler::displayWindow(IGraphic &graphic)
    {
        graphic.clearWindow(ARCADE_BLACK);
        for (unsigned int i = 0; i < _art.size() && i < 45; i++) {
            for (unsigned int j = 0; j < _art[i].size() && j < 80; j++) {
                if (_art[i][j] >= '1' && _art[i][j] <= '8')
                    graphic.printPixel(Vector(j, i), colors[_art[i][j] - '1']);
            }
        }
        switch (_menu) {
        case 1:
            graphic.printText(Vector(46, 19), "USERNAME:");
            graphic.printText(Vector(51, 19), _username, ARCADE_RED);
            displayNibbler(graphic);
            break;
        case 2:
            graphic.printText(Vector(46, 19), "USERNAME:");
            graphic.printText(Vector(51, 19), _username, ARCADE_RED);
            displayPause(graphic);
            break;
        case 3:
            displayEnd(graphic);
            break;
        default:
            graphic.printText(Vector(46, 19), "USERNAME:");
            graphic.printText(Vector(51, 19), _username, ARCADE_RED);
            displayMenu(graphic);
        }
        graphic.displayWindow();
    }

    void Nibbler::loadMaps()
    {
        _selectMap = 0;
        _maps.clear();
        std::string path = "./assets/";
        std::regex reg("nibbler_map_[a-z_0-9]+\\.txt");
        DIR *dir = opendir(path.c_str());
        struct dirent *ent;
        if (dir == NULL)
            return;
        ent = readdir(dir);
        while (ent != NULL) {
            std::string file = std::string(ent->d_name);
            if (std::regex_match(file, reg))
                _maps.push_back(MapNibbler(path + file));
            ent = readdir(dir);
        }
        closedir(dir);
    }

    Event Nibbler::eventMenu(Event e)
    {
        auto type = e.getType();

        if (type == ARCADE_KEY_UP)
            _selectMap = (_selectMap == 0 ? _maps.size() - 1 : _selectMap - 1);
        if (type == ARCADE_KEY_DOWN)
            _selectMap = (_selectMap == _maps.size() - 1 ? 0 : _selectMap + 1);
        if (type == ARCADE_KEY_SPACE)
            loadMaps();
        if (type == ARCADE_KEY_ENTER && _maps.size() > _selectMap)
            startGame();
        return (e);
    }

    void Nibbler::startGame()
    {
        _menu = 1;
        _nibbler.clear();
        _update = 0;
        _direction = 1;
        _nextDir = 1;
        _selectMenu = 0;
        _nibbler.push_back(Vector(10, 10));
        _nibbler.push_back(Vector(10, 11));
        _nibbler.push_back(Vector(10, 12));
        _nibbler.push_back(Vector(10, 13));
        generateApple(_maps[_selectMap].getMap());
    }

    bool safeApple(Vector pos, std::vector <Vector> nibbler,
        std::vector <std::string> map)
    {
        if (map[pos.y][pos.x] == '#')
            return (false);
        for (unsigned int i = 0; i < nibbler.size(); i++) {
            if (nibbler[i].x == pos.x && nibbler[i].y == pos.y)
                return (false);
        }
        return (true);
    }

    void Nibbler::generateApple(std::vector <std::string> map)
    {
        bool good = false;
        Vector apple = Vector(0, 0);

        for (int i = 0; i < 5 && !good; i++) {
            apple = Vector(rand() % 20 + 1, rand() % 20 + 1);
            if (safeApple(apple, _nibbler, map))
                good = true;
        }
        if (good) {
            _apple = apple;
            return;
        }
        for (unsigned int i = 1; i < 21; i++) {
            for (unsigned int j = 1; j < 21; j++) {
                if (safeApple(Vector(i, j), _nibbler, map)) {
                    _apple = Vector(i, j);
                    return;
                }
            }
        }
        _apple = Vector(-1, -1);
    }

    Event Nibbler::eventNibbler(Event e)
    {
        if (e == ARCADE_KEY_SPACE) {
            _menu = 2;
        }
        if (e == ARCADE_KEY_A) {
            generateApple(_maps[_selectMap].getMap());
        }
        if (e == ARCADE_KEY_UP && _direction != 3)
            _nextDir = 1;
        if (e == ARCADE_KEY_RIGHT && _direction != 4)
            _nextDir = 2;
        if (e == ARCADE_KEY_DOWN && _direction != 1)
            _nextDir = 3;
        if (e == ARCADE_KEY_LEFT && _direction != 2)
            _nextDir = 4;
        return (e);
    }

    Event Nibbler::eventPause(Event e)
    {
        if (e == ARCADE_KEY_SPACE ||
            (e == ARCADE_KEY_ENTER && _selectMenu == 0)) {
            _selectMenu = 0;
            _menu = 1;
        } else if (e == ARCADE_KEY_ENTER) {
            _selectMenu = 0;
            _menu = 0;
        }
        if (e == ARCADE_KEY_UP || e == ARCADE_KEY_DOWN ||
            e == ARCADE_KEY_LEFT || e == ARCADE_KEY_RIGHT)
            _selectMenu = (_selectMenu == 0 ? 1 : 0);
        return (e);
    }

    Event Nibbler::eventEnd(Event e)
    {
        if (e == ARCADE_KEY_ENTER && _selectMenu == 0) {
            _selectMenu = 0;
            startGame();
        } else if (e == ARCADE_KEY_ENTER) {
            _selectMenu = 0;
            _menu = 0;
        }
        if (e == ARCADE_KEY_UP || e == ARCADE_KEY_DOWN ||
            e == ARCADE_KEY_LEFT || e == ARCADE_KEY_RIGHT)
            _selectMenu = (_selectMenu == 0 ? 1 : 0);
        return (e);
    }

    void Nibbler::updateNibbler()
    {
        if (_update < 4) {
            _update++;
            return;
        }
        bool regen = false;
        Vector offset(0, 0);
        _update = 0;
        _direction = _nextDir;
        if (_direction == 1)
            offset.y = -1;
        if (_direction == 2)
            offset.x = 1;
        if (_direction == 3)
            offset.y = 1;
        if (_direction == 4)
            offset.x = -1;
        if (_apple == Vector(_nibbler[0].x + offset.x, _nibbler[0].y + offset.y)) {
            _nibbler.push_back(Vector(0, 0));
            regen = true;
        }
        if (!safeApple(Vector(_nibbler[0].x + offset.x, _nibbler[0].y + offset.y),
            _nibbler, _maps[_selectMap].getMap()) || _nibbler[0].x + offset.x < 1 ||
            _nibbler[0].x + offset.x > 20 || _nibbler[0].y + offset.y < 1 ||
            _nibbler[0].y + offset.y > 20) {
            _menu = 3;
            getScores();
            return;
        }
        for (unsigned int i = _nibbler.size() - 1; i > 0; i--)
            _nibbler[i] = _nibbler[i - 1];
        _nibbler[0] = Vector(_nibbler[0].x + offset.x, _nibbler[0].y + offset.y);
        if (regen)
            generateApple(_maps[_selectMap].getMap());
    }

    void Nibbler::displayMenu(IGraphic &graphic)
    {
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
        graphic.printText(Vector(30, 25), "/\\", ARCADE_BLACK, ARCADE_GREEN);
        for (int i = 0; i < 3; i++)
            graphic.printPixel(Vector(30, i + 26), ARCADE_GREEN);
        for (unsigned int i = 0; i < _maps.size(); i++) {
            if (i != _selectMap)
                graphic.printText(Vector(48, i * 2 + 25), _maps[i].getName());
            else
                graphic.printText(Vector(48, i * 2 + 25), _maps[i].getName(),
                    ARCADE_WHITE, ARCADE_BLUE);
        }
    }

    void Nibbler::displayNibbler(IGraphic &graphic)
    {
        graphic.printText(Vector(15, 42), "ESC: quit", ARCADE_BLACK,
            ARCADE_WHITE);
        graphic.printText(Vector(22, 42), "F1,F2,...: chose graphic mod",
            ARCADE_BLACK, ARCADE_WHITE);
        graphic.printText(Vector(39, 42), "SPACE: pause", ARCADE_BLACK,
            ARCADE_WHITE);
        graphic.printText(Vector(48, 42), "/\\ > \\/ <: move", ARCADE_BLACK,
            ARCADE_WHITE);
        if (_maps.size() > _selectMap)
            _maps[_selectMap].display(graphic);
        if (_direction == 1)
            graphic.printText(Vector(_nibbler[0].x + 20, _nibbler[0].y + 15), "/\\",
                ARCADE_BLACK, ARCADE_GREEN);
        if (_direction == 2)
            graphic.printText(Vector(_nibbler[0].x + 20, _nibbler[0].y + 15), " >",
                ARCADE_BLACK, ARCADE_GREEN);
        if (_direction == 3)
            graphic.printText(Vector(_nibbler[0].x + 20, _nibbler[0].y + 15), "\\/",
                ARCADE_BLACK, ARCADE_GREEN);
        if (_direction == 4)
            graphic.printText(Vector(_nibbler[0].x + 20, _nibbler[0].y + 15), "< ",
                ARCADE_BLACK, ARCADE_GREEN);
        for (unsigned int i = 1; i < _nibbler.size(); i++)
            graphic.printPixel(Vector(_nibbler[i].x + 20, _nibbler[i].y + 15),
                ARCADE_GREEN);
        graphic.printPixel(Vector(_apple.x + 20, _apple.y + 15), ARCADE_RED);
        graphic.printText(Vector(46, 22), "SCORE:");
        graphic.printText(Vector(51, 22), std::to_string(_nibbler.size() - 4),
            ARCADE_RED);
    }

    void Nibbler::displayPause(IGraphic &graphic)
    {
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
        for (unsigned int i = 1; i < _artPause.size() && i < 21; i++) {
            for (unsigned int j = 1; j < _artPause[i].size() && j < 21; j++) {
                if (_artPause[i][j] >= '1' && _artPause[i][j] <= '8')
                    graphic.printPixel(Vector(j + 20, i + 15),
                        colors[_artPause[i][j] - '1']);
            }
        }
        graphic.printText(Vector(46, 22), "SCORE:");
        graphic.printText(Vector(51, 22), std::to_string(_nibbler.size() - 4),
            ARCADE_RED);
        if (_selectMenu == 0) {
            graphic.printText(Vector(45, 32), "RESUME", ARCADE_WHITE,
                ARCADE_BLUE);
            graphic.printText(Vector(52, 32), "MENU");
        } else {
            graphic.printText(Vector(45, 32), "RESUME");
            graphic.printText(Vector(52, 32), "MENU", ARCADE_WHITE,
                ARCADE_BLUE);
        }
    }

    void Nibbler::displayEnd(IGraphic &graphic)
    {
        graphic.printText(Vector(17, 42), "ESC: quit", ARCADE_BLACK,
            ARCADE_WHITE);
        graphic.printText(Vector(25, 42), "F1,F2,...: chose graphic mod",
            ARCADE_BLACK, ARCADE_WHITE);
        graphic.printText(Vector(40, 42), "/\\ \\/: chose button", ARCADE_BLACK,
            ARCADE_WHITE);
        graphic.printText(Vector(52, 42), "ENTER: press button", ARCADE_BLACK,
            ARCADE_WHITE);
        if (_maps.size() > _selectMap)
            _maps[_selectMap].display(graphic);
        if (_direction == 1)
            graphic.printText(Vector(_nibbler[0].x + 20, _nibbler[0].y + 15), "/\\",
                ARCADE_BLACK, ARCADE_GREEN);
        if (_direction == 2)
            graphic.printText(Vector(_nibbler[0].x + 20, _nibbler[0].y + 15), " >",
                ARCADE_BLACK, ARCADE_GREEN);
        if (_direction == 3)
            graphic.printText(Vector(_nibbler[0].x + 20, _nibbler[0].y + 15), "\\/",
                ARCADE_BLACK, ARCADE_GREEN);
        if (_direction == 4)
            graphic.printText(Vector(_nibbler[0].x + 20, _nibbler[0].y + 15), "< ",
                ARCADE_BLACK, ARCADE_GREEN);
        for (unsigned int i = 1; i < _nibbler.size(); i++)
            graphic.printPixel(Vector(_nibbler[i].x + 20, _nibbler[i].y + 15),
                ARCADE_GREEN);
        graphic.printPixel(Vector(_apple.x + 20, _apple.y + 15), ARCADE_RED);
        if (_selectMenu == 0) {
            graphic.printText(Vector(45, 32), "RESTART", ARCADE_WHITE,
                ARCADE_BLUE);
            graphic.printText(Vector(52, 32), "MENU");
        } else {
            graphic.printText(Vector(45, 32), "RESTART");
            graphic.printText(Vector(52, 32), "MENU", ARCADE_WHITE,
                ARCADE_BLUE);
        }

        for (unsigned int i = 0; i < _scores.size() && i < 10; i++) {
            if (_scorePos == i + 1) {
                graphic.printText(Vector(45, 19 + i), std::to_string(i + 1),
                    ARCADE_RED);
                graphic.printText(Vector(47, 19 + i), std::get<0>(_scores[i]),
                    ARCADE_RED);
                graphic.printText(Vector(54, 19 + i),
                    std::to_string(std::get<1>(_scores[i])), ARCADE_RED);
            } else {
                graphic.printText(Vector(45, 19 + i), std::to_string(i + 1));
                graphic.printText(Vector(47, 19 + i), std::get<0>(_scores[i]));
                graphic.printText(Vector(54, 19 + i),
                    std::to_string(std::get<1>(_scores[i])));
            }
        }
        if (_scorePos != 0 && _scorePos >= 10) {
            graphic.printText(Vector(47, 29), "...");
            graphic.printText(Vector(45, 30), std::to_string(_scorePos + 1),
                ARCADE_RED);
            graphic.printText(Vector(47, 30), _username, ARCADE_RED);
            graphic.printText(Vector(54, 30), std::to_string(_nibbler.size() - 4),
                ARCADE_RED);
        }
    }

    std::string user = "";
    unsigned int myScore = 0;

    bool compareScore(std::tuple<std::string, unsigned int> a,
        std::tuple<std::string, unsigned int> b)
    {
        auto score1 = std::get<1>(a);
        auto score2 = std::get<1>(b);
        if (score1 == score2 && std::get<0>(a) == user)
            return (true);
        else
            return (std::get<1>(a) > std::get<1>(b));
    }

    void Nibbler::getScores()
    {
        _scores.clear();
        _scorePos = 0;
        user = _username;
        myScore = _nibbler.size() - 4;
        std::string file = (std::string("./assets/nibbler_score_") +
            _maps[_selectMap].getName() + ".txt");
        std::ofstream out(file, std::ios_base::app);
        if (!out)
            return;
        if (_username.size() > 0)
            out << _username << " " << std::to_string(myScore)
                << std::endl;
        std::ifstream in(file);
        if (!in)
            return;
        std::string line;
        while (std::getline(in, line)) {
            auto pos = line.find(" ");
            if (pos == std::string::npos)
                continue;
            auto username = line.substr(0, pos);
            if (username.size() > 12 || username.size() == 0)
                continue;
            auto score = std::atoi(
                line.substr(pos + 1, line.size() - pos + 1).c_str());
            if (score < 0 || score > 400)
                continue;
            _scores.push_back(
                std::tuple<std::string, unsigned int>(username, score));
        }
        std::sort(_scores.begin(), _scores.end(), compareScore);
        for (unsigned int i = 0; i < _scores.size(); i++) {
            if (std::get<0>(_scores[i]) == user &&
                std::get<1>(_scores[i]) == myScore) {
                _scorePos = i + 1;
                break;
            }
        }
    }
}
