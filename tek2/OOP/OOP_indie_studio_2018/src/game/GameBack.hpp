/*
** EPITECH PROJECT, 2018
** OOP_indie_studio_2018
** File description:
** GameBack.hpp
*/

#ifndef OOP_INDIE_STUDIO_2018_GAMEBACK_HPP
    #define OOP_INDIE_STUDIO_2018_GAMEBACK_HPP

#include <deque>
#include <thread>
#include "../Settings.hpp"
#include "Structures.hpp"
#include "TcpServer.hpp"
#include "GameStatsContainer.hpp"

class GameBack {
public:
    ~GameBack();
    explicit GameBack(Settings &settings);

    bool hasError() const {return _error;}
    bool isReady() const;
    bool startGame();
    void saveGame();
    const GameStats &getGame() const {return _game.getGame();}

private:
    void gameLoop();
    void updateGame(const std::deque<std::unique_ptr<Action>> &actions,
        double diff);
    void sendResponse(const std::deque<std::unique_ptr<Action>> &actions);

    Settings &_settings;
    GameStatsContainer _game;
    bool _error;
    std::deque<TcpServerPtr> _servers;
    std::deque<std::thread> _threads;

};

using GameBackPtr = std::unique_ptr<GameBack>;

#endif /*OOP_INDIE_STUDIO_2018_GAMEBACK_HPP*/
