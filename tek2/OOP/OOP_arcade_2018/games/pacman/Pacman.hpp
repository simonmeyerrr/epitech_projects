/*
** EPITECH PROJECT, 2018
** OOP_arcade_2018
** File description:
** Pacman.hpp
*/

#ifndef OOP_ARCADE_2018_PACMAN_HPP
#define OOP_ARCADE_2018_PACMAN_HPP

#include <chrono>
#include <ctime>
#include <vector>
# include "IGame.hpp"
# include "PacmanGhost.hpp"
# include "PacmanGhostRed.hpp"

namespace arcade {

    class MapPacman {
    public:
        ~MapPacman() = default;
        MapPacman(const std::string &path);

        std::string getName() const;
        std::vector<std::string> getMap() const;
        void display(IGraphic &graphic) const;

    private:
        std::string _name;
        std::vector<std::string> _map;
    };

    struct Score {
        std::string user;
        std::size_t score;
        std::string time;
    };

    class Pacman : public IGame {
    public:
        ~Pacman();
        Pacman();

        void setUsername(const std::string &username);
        Event manageEvent(IGraphic &graphic);
        void updateGame();
        void displayWindow(IGraphic &graphic);

    private:
        void loadMaps();
        void startGame();
        void resetGame();

        void eventMenu(Event e);
        void eventPacman(Event e);
        void eventPause(Event e);
        void eventEnd(Event e);

        void updatePacman();

        void displayMenu(IGraphic &graphic);
        void displayPacman(IGraphic &graphic);
        void displayPause(IGraphic &graphic);
        void displayEnd(IGraphic &graphic);
        void displayMap(IGraphic &graphic);

        int verifMove(Vector);
        int verifDirection(Vector, int);
        void verifSaveDirection();
        void verifPosition();
        void teleporte();

        std::string getTime() const;
        void getScore();
        void addScore() const;

        std::size_t _menu;
        std::string _username;
        std::vector<std::string> _art;
        std::vector<std::string> _artPause;

        std::chrono::high_resolution_clock::time_point _update;
        std::chrono::high_resolution_clock::time_point _time;
        std::chrono::high_resolution_clock::time_point _pause;
        Vector _pacman;
        Vector _startPacman;
        int _life;
        int _direction;
        int _saveDirection;
        size_t _maxScore;
        size_t _score;
        std::vector<PacmanGhost *> _ghost;

        std::vector<std::string> _useMap;
        std::vector<std::string> _usePosMap;
        std::vector<MapPacman> _maps;
        std::size_t _selectMap;
        std::size_t _selectMenu;
        std::vector<std::vector<std::string>> _scores;
    };
}

#endif /* OOP_ARCADE_2018_PACMAN_HPP */
