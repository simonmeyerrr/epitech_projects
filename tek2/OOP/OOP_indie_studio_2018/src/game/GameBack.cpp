/*
** EPITECH PROJECT, 2018
** OOP_indie_studio_2018
** File description:
** GameBack.cpp
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <iostream>
#include <fstream>
#include "GameBack.hpp"
#include "GameStatsContainer.hpp"

GameBack::~GameBack()
{
    int last_error = _error;

    _error = true;
    for (auto &thread: _threads)
        thread.join();
    #ifdef DEBUG
    std::cout << "DTOR GameBack error: " << std::boolalpha << last_error
        << std::endl;
    #endif
}

GameBack::GameBack(Settings &settings)
    : _settings(settings), _game(settings), _error(false)
{
    for (unsigned int i = 0; i < PLAYER_NUMBER; i++) {
        _servers.emplace_back(
            _game->players[i].exist ? new TcpServer(8001 + i) : nullptr);
        if (_servers[i] && _servers[i]->hasError()) {
            _error = true;
            #ifdef DEBUG
            std::cerr << "CTOR KO GameBack " << std::endl;
            #endif
            return;
        }
    }
    _threads.emplace_back(std::thread(&GameBack::gameLoop, this));
    #ifdef DEBUG
    std::cout << "CTOR OK GameBack " << std::endl;
    #endif
}

bool GameBack::isReady() const
{
    for (const auto &server: _servers)
        if (server && !server->isConnected())
            return false;
    return true;
}

bool GameBack::startGame()
{
    if (!isReady() || _game->started)
        return false;
    #ifdef DEBUG
    std::cerr << "GameBack start game" << std::endl;
    #endif
    _game->started = true;
    return true;
}

void GameBack::saveGame()
{
    std::ofstream file(SAVE_FILE);

    if (file.is_open()) {
        file.write((char*)&(_game.getGame()), sizeof(GameStats));
        file.close();
    } else {
        #ifdef DEBUG
        std::cerr << "Failed save the game into a file" << std::endl;
        #endif
    }
}

void GameBack::gameLoop()
{
    auto update = std::chrono::high_resolution_clock::now();

    while (!_error) {
        std::deque<std::unique_ptr<Action>> actions;
        for (auto &server: _servers)
            actions.emplace_back(server ? server->getMessage() : nullptr);
        auto diff = std::chrono::duration<double, std::milli>(
            std::chrono::high_resolution_clock::now() - update).count();
        update = std::chrono::high_resolution_clock::now();
        if (_game->started)
            updateGame(actions, diff);
        sendResponse(actions);
    }
}

void GameBack::updateGame(const std::deque<std::unique_ptr<Action>> &actions,
    double diff)
{
    _game.updateMap(diff);
    for (unsigned char i = 0; i < PLAYER_NUMBER; i++)
        _game.updatePlayer(i, actions[i], diff);
    _game.updatePlayersRank();
}

void GameBack::sendResponse(const std::deque<std::unique_ptr<Action>> &actions)
{
    for (unsigned int i = 0; i < actions.size() && i < PLAYER_NUMBER; i++) {
        if (actions[i] && _servers[i])
            _servers[i]->sendMessage(&_game.getGame());
    }
    for (unsigned int i = 0; i < _servers.size() && i < PLAYER_NUMBER; i++) {
        if (_servers[i])
            _game->players[i].connected = _servers[i]->isConnected();
    }
}
