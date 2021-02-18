/*
** EPITECH PROJECT, 2018
** OOP_arcade_2018
** File description:
** Core.cpp
*/

#include <string>
#include <iostream>
#include <dlfcn.h>
#include <exception>
#include <unistd.h>
#include <iomanip>
#include <chrono>
#include <ctime>
#include <regex>
#include <dirent.h>
#include "Core.hpp"

namespace arcade {
    Core::~Core()
    {
        _game = nullptr;
        _graph = nullptr;
        if (_libGraph)
            dlclose(_libGraph);
        if (_libGame)
            dlclose(_libGame);
    }

    Core::Core(const std::string &libGraph)
        : _libGraph(nullptr), _libGame(nullptr), _arcade(), _graph(nullptr),
        _game(nullptr)
    {
        searchGraphs();
        changeGraphicLib(libGraph);
    }

    void Core::loop()
    {
        auto startDisplay = std::chrono::high_resolution_clock::now();
        auto startUpdate = std::chrono::high_resolution_clock::now();

        while (!event()) {
            auto diffDisplay = std::chrono::duration<double, std::milli>(
                std::chrono::high_resolution_clock::now() -
                    startDisplay).count();
            if (diffDisplay >= (1.0 / 30.0) * 1000.0) {
                startDisplay = std::chrono::high_resolution_clock::now();
                display();
            }
            auto diffUpdate = std::chrono::duration<double, std::milli>(
                std::chrono::high_resolution_clock::now() -
                    startUpdate).count();
            if (diffUpdate >= (1.0 / 30.0) * 1000.0) {
                startUpdate = std::chrono::high_resolution_clock::now();
                update();
            }
        }
    }

    void Core::update()
    {
        if (_game)
            _game->updateGame();
    }

    int Core::event()
    {
        Event e(ARCADE_NO_EVENT);
        if (!_graph)
            throw std::exception();
        else if (_game) {
            e = _game->manageEvent(*_graph);
            if (e == ARCADE_KEY_ESCAPE)
                changeGameLib("");
        } else {
            e = _arcade.manageEvent(*_graph);
            if (e == ARCADE_KEY_ENTER)
                changeGameLib(_arcade.getGamePath());
            if (e == ARCADE_KEY_ESCAPE)
                return (1);
        }
        auto type = e.getType();
        if (e == ARCADE_CLOSE_WINDOW)
            return (1);
        if (type >= ARCADE_KEY_F1 && type <= ARCADE_KEY_F12 &&
            _graphicals.size() > (long unsigned int)type - ARCADE_KEY_F1) {
            changeGraphicLib(_graphicals[type - ARCADE_KEY_F1]);
        }
        return (0);
    }

    void Core::display()
    {
        if (!_graph)
            throw std::exception();
        if (_game)
            _game->displayWindow(*_graph);
        else
            _arcade.displayWindow(*_graph, _graphicals);
    }

    void Core::changeGraphicLib(const std::string &libGraph)
    {
        char *str;

        _graph = nullptr;
        if (_libGraph)
            dlclose(_libGraph);
        _libGraph = nullptr;
        str = dlerror();
        if (str) {
            std::cerr << str << std::endl;
            throw std::exception();
        }
        _libGraph = dlopen(libGraph.c_str(), RTLD_LAZY);
        str = dlerror();
        if (str) {
            std::cerr << str << std::endl;
            throw std::exception();
        }
        arcade::IGraphic *(*init)() =
            reinterpret_cast<arcade::IGraphic *(*)()>(dlsym(_libGraph, "init"));
        str = dlerror();
        if (str) {
            std::cerr << str << std::endl;
            throw std::exception();
        }
        if (!init) {
            std::cerr << "failed to start graphical library" << std::endl;
            throw std::exception();
        }
        _graph.release();
        _graph.reset(init());
        if (_graph == nullptr) {
            std::cerr << "failed to start graphical library" << std::endl;
            throw std::exception();
        }
    }

    void Core::changeGameLib(const std::string &libGame)
    {
        char *str;

        _game = nullptr;
        if (_libGame)
            dlclose(_libGame);
        _libGame = nullptr;
        str = dlerror();
        if (str) {
            std::cerr << str << std::endl;
            throw std::exception();
        }
        if (libGame.size() == 0)
            return;
        _libGame = dlopen(libGame.c_str(), RTLD_LAZY);
        str = dlerror();
        if (str) {
            std::cerr << str << std::endl;
            throw std::exception();
        }
        arcade::IGame *(*init)() =
            reinterpret_cast<arcade::IGame *(*)()>(dlsym(_libGame, "init"));
        str = dlerror();
        if (str) {
            std::cerr << str << std::endl;
            throw std::exception();
        }
        if (!init) {
            std::cerr << "failed to start game library" << std::endl;
            throw std::exception();
        }
        _game.release();
        _game.reset(init());
        if (_game == nullptr) {
            std::cerr << "failed to start game library" << std::endl;
            throw std::exception();
        }
        _game->setUsername(_arcade.getUsername());
    }

    void Core::searchGraphs()
    {
        std::string path = "./lib/";
        std::regex reg("lib_arcade_[a-z_]+\\.so");
        DIR *dir = opendir(path.c_str());
        _graphicals.clear();
        struct dirent *ent;
        if (dir == NULL)
            return;
        ent = readdir(dir);
        while (ent != NULL) {
            std::string file = std::string(ent->d_name);
            if (std::regex_match(file, reg))
                _graphicals.push_back(path + file);
            ent = readdir(dir);
        }
        closedir(dir);
    }
}