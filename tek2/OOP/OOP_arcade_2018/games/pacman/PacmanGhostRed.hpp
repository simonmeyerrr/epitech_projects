/*
** EPITECH PROJECT, 2018
** OOP_arcade_2018
** File description:
** PacmanGhostRed.hpp
*/

#ifndef OOP_ARCADE_2018_PACMANGHOSTRED_HPP
#define OOP_ARCADE_2018_PACMANGHOSTRED_HPP

#include <vector>
# include "PacmanGhost.hpp"
# include "IGame.hpp"

namespace arcade {
    class PacmanGhostRed : public PacmanGhost {
    public:
        ~PacmanGhostRed();
        PacmanGhostRed(const Vector &, int);
        void chase(const std::vector<std::string> &map) override;
    private:
    };
}

#endif /* OOP_ARCADE_2018_PACMANGHOSTRED_HPP */
