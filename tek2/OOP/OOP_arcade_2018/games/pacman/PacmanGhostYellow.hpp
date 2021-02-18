/*
** EPITECH PROJECT, 2018
** OOP_arcade_2018
** File description:
** PacmanGhostYellow.hpp
*/

#ifndef OOP_ARCADE_2018_PACMANGHOSTYELLOW_HPP
#define OOP_ARCADE_2018_PACMANGHOSTYELLOW_HPP

#include <vector>
# include "PacmanGhost.hpp"
# include "IGame.hpp"

namespace arcade {
    class PacmanGhostYellow : public PacmanGhost {
    public:
        ~PacmanGhostYellow() override;
        PacmanGhostYellow(const Vector &, int,
            const std::vector<std::string> &map
        );
        void chase(const std::vector<std::string> &map) override;
    private:
        size_t _nextCheckpoint;
        std::vector<Vector> _checkpoint;
    };
}

#endif /* OOP_ARCADE_2018_PACMANGHOSTYELLOW_HPP */
