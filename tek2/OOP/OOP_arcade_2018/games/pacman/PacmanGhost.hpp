/*
** EPITECH PROJECT, 2018
** OOP_arcade_2018
** File description:
** PacmanGhost.hpp
*/

#ifndef OOP_ARCADE_2018_PACMANGHOST_HPP
#define OOP_ARCADE_2018_PACMANGHOST_HPP

#include <vector>
#include <chrono>
# include "IGame.hpp"

namespace arcade {

    class PacmanGhost {
    public:
        virtual ~PacmanGhost();
        PacmanGhost(Vector, Color, int);
        Color getColor() const;
        Vector getPosition() const;
        bool getState() const;
        bool getDeath() const;
        void setState(bool);
        void setDeath(bool);
        void reset();

        void display(IGraphic &graphic) const;
        Vector update(std::vector<std::string>);
        void move(const std::vector<std::string> &map);
        virtual void move(const std::vector<std::string> &map, const Vector &,
            int direction
        );
        void fleePacamn(const std::vector<std::string> &map);
        void comeBackHome(const std::vector<std::string> &map);
        virtual void chase(const std::vector<std::string> &map);

        int verifMove(Vector, std::vector<std::string>) const;
        int verifDirection(Vector, std::vector<std::string>) const;
        void teleporte(std::vector<std::string> map);
        void comparePosition(Vector pacman);

    protected:
        Vector _position;
        Vector _startPos;
        int _direction;
        bool _dead;
        bool _eatable;
        Color _color;
        int _nbWait;
        Vector _move;
        std::chrono::high_resolution_clock::time_point _update;
        std::chrono::high_resolution_clock::time_point _wait;
        std::chrono::high_resolution_clock::time_point _timeEatable;
    };
}

#endif /* OOP_ARCADE_2018_PACMANGHOST_HPP */
