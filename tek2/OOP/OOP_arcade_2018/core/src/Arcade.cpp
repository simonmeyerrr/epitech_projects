/*
** EPITECH PROJECT, 2018
** OOP_arcade_2018
** File description:
** Arcade.cpp
*/

#include <regex>
#include <iostream>
#include <dirent.h>
#include <fstream>
#include "Arcade.hpp"

namespace arcade {

    Arcade::~Arcade()
    {
    }

    Arcade::Arcade()
        : _username("____________"), _itUsername(0), _itGames(0)
    {
        searchGames();
        std::ifstream in("./assets/arcade.txt");
        if (!in)
            return;
        std::string line;
        while (std::getline(in, line))
            _art.push_back(line);
    }

    Event Arcade::manageEvent(IGraphic &graphic)
    {
        Event e = graphic.getEvent();
        EventType type = e.getType();
        Vector pos = e.getPos();

        if (type == ARCADE_NO_EVENT)
            return (e);
        if (type >= ARCADE_KEY_A && type <= ARCADE_KEY_Z && _itUsername < 12) {
            _username[_itUsername] = type - ARCADE_KEY_A + 'A';
            _itUsername++;
        } else if (type >= ARCADE_KEY_0 && type <= ARCADE_KEY_9 &&
            _itUsername < 12) {
            _username[_itUsername] = type - ARCADE_KEY_0 + '0';
            _itUsername++;
        }
        if (type == ARCADE_KEY_DELETE && _itUsername > 0) {
            _username[_itUsername - 1] = '_';
            _itUsername--;
        }
        if (type == ARCADE_KEY_UP)
            _itGames = (_itGames == 0 ? _games.size() - 1 : _itGames - 1);
        if (type == ARCADE_KEY_DOWN)
            _itGames = (_itGames == _games.size() - 1 ? 0 : _itGames + 1);
        if (type == ARCADE_KEY_SPACE)
            searchGames();
        return (e);
    }

    const Color colors[] = {ARCADE_WHITE, ARCADE_BLACK, ARCADE_RED, ARCADE_BLUE,
        ARCADE_GREEN, ARCADE_YELLOW, ARCADE_MAGENTA, ARCADE_CYAN};

    void Arcade::displayWindow(IGraphic &graphic,
        const std::vector <std::string> &libs)
    {
        graphic.clearWindow(ARCADE_BLACK);
        for (unsigned int i = 0; i < _art.size() && i < 45; i++) {
            for (unsigned int j = 0; j < _art[i].size() && j < 80; j++) {
                if (_art[i][j] >= '1' && _art[i][j] <= '8')
                    graphic.printPixel(Vector(j, i), colors[_art[i][j] - '1']);
            }
        }
        graphic.printText(Vector(25, 18), "CHOOSE YOUR USERNAME:");
        graphic.printText(Vector(28, 20), _username, ARCADE_RED);
        graphic.printText(Vector(23, 24), "CHOOSE A GAME:");
        if (_games.size() == 0) {
            graphic.printText(Vector(23, 27), "NO GAMES AVAILABLE!",
                ARCADE_RED);
        }
        for (unsigned int i = 0; i < _games.size(); i++) {
            if (i != _itGames) {
                graphic.printText(Vector(24, i * 2 + 26), _games[i]);
            } else {
                graphic.printText(Vector(24, i * 2 + 26), _games[i],
                    ARCADE_WHITE, ARCADE_BLUE);
            }
        }
        graphic.printText(Vector(32, 24), "GRAPHICAL MODS:");
        for (unsigned int i = 0; i < libs.size(); i++) {
            graphic.printText(Vector(33, i * 2 + 26),
                "F" + std::to_string(i + 1) + ":");
            graphic.printText(Vector(35, i * 2 + 26),
                libs[i].substr(17, libs[i].size() - 20));
        }
        unsigned int i = 21;
        graphic.printText(Vector(47, 18), "BEST SCORES", ARCADE_RED);
        for (unsigned int j = 0;
            _games.size() > 0 && j < _scores[_itGames].size(); j++) {
            graphic.printText(Vector(43, i), _scores[_itGames][j][0][0]);
            for (unsigned int k = 1; k < _scores[_itGames][j].size(); k++) {
                graphic.printText(Vector(48, i), std::to_string(k), ARCADE_RED);
                graphic.printText(Vector(49, i), _scores[_itGames][j][k][0]);
                graphic.printText(Vector(56, i), _scores[_itGames][j][k][1]);
                i++;
            }
            i += (_scores[_itGames][j].size() > 1 ? 1 : 2);
        }
        graphic.printText(Vector(12, 42), "ESC: quit", ARCADE_BLACK,
            ARCADE_WHITE);
        graphic.printText(Vector(18, 42), "SPACE: reload libraries",
            ARCADE_BLACK, ARCADE_WHITE);
        graphic.printText(Vector(32, 42), "F1,F2,...: chose graphic mod",
            ARCADE_BLACK, ARCADE_WHITE);
        graphic.printText(Vector(48, 42), "/\\ \\/: chose game", ARCADE_BLACK,
            ARCADE_WHITE);
        graphic.printText(Vector(59, 42), "ENTER: launch game", ARCADE_BLACK,
            ARCADE_WHITE);
        graphic.displayWindow();
    }

    std::string Arcade::getUsername() const
    {
        return (_username.substr(0, _itUsername));
    }

    std::string Arcade::getGamePath() const
    {
        if (_itGames >= _games.size())
            return ("");
        else
            return (_gamesPath[_itGames]);
    }

    void Arcade::searchGames()
    {
        std::string path = "./games/";
        std::regex reg("lib_arcade_[a-z_]+\\.so");
        DIR *dir = opendir(path.c_str());
        _itGames = 0;
        _games.clear();
        _gamesPath.clear();
        _scores.clear();
        struct dirent *ent;
        if (dir == NULL)
            return;
        ent = readdir(dir);
        while (ent != NULL) {
            std::string file = std::string(ent->d_name);
            if (std::regex_match(file, reg)) {
                _games.push_back(file.substr(11, file.size() - 14));
                _gamesPath.push_back(path + std::string(ent->d_name));
                _scores.push_back(
                    std::vector < std::vector < std::vector < std::string >> >
                        ());
            }
            ent = readdir(dir);
        }
        closedir(dir);
        getScores();
    }

    void Arcade::getScores()
    {
        std::string path = "./assets/";
        std::regex reg("[a-z_]+_score_[a-z_0-9]+\\.txt");
        DIR *dir = opendir(path.c_str());
        struct dirent *ent;
        if (dir == NULL)
            return;
        ent = readdir(dir);
        while (ent != NULL) {
            std::string file = std::string(ent->d_name);
            if (std::regex_match(file, reg)) {
                for (unsigned int i = 0; i < _games.size(); i++) {
                    if (file.substr(0, file.find("_")) == _games[i]) {
                        addScore(i, path + file, file.substr(file.find("_") + 7,
                            file.size() - (7 + 4 + file.find("_"))));
                    }
                }
            }
            ent = readdir(dir);
        }
        closedir(dir);
    }

    bool compareScore(std::vector <std::string> a, std::vector <std::string> b)
    {
        auto score1 = a[1];
        auto score2 = b[1];
        if (score1.size() > score2.size())
            return (true);
        if (score1.size() < score2.size())
            return (false);
        if (score1.find(":") != std::string::npos)
            return (score2 > score1);
        return (score1 > score2);
    }

    void Arcade::addScore(unsigned int i, std::string file, std::string map)
    {
        auto ssize = _scores[i].size();
        _scores[i].push_back(std::vector < std::vector < std::string >> ());
        std::ifstream in(file);
        if (!in)
            return;
        std::string line;
        std::vector <std::vector<std::string>> scores;
        while (std::getline(in, line)) {
            auto pos = line.find(" ");
            if (pos == std::string::npos)
                continue;
            auto username = line.substr(0, pos);
            if (username.size() > 12 || username.size() == 0)
                continue;
            std::vector <std::string> score;
            score.push_back(username);
            score.push_back(line.substr(pos + 1, line.size() - pos + 1));
            scores.push_back(score);
        }
        std::sort(scores.begin(), scores.end(), compareScore);
        std::vector <std::string> mapName;
        mapName.push_back(map);
        _scores[i][ssize].push_back(mapName);
        for (unsigned int j = 0; j < scores.size() && j < 3; j++) {
            _scores[i][ssize].push_back(scores[j]);
        }
    }
}