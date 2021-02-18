/*
** EPITECH PROJECT, 2018
** OOP_arcade_2018
** File description:
** PacmanGhostPink.hpp
*/

#ifndef OOP_ARCADE_2018_PACMANGHOSTPINK_HPP
#define OOP_ARCADE_2018_PACMANGHOSTPINK_HPP

#include <vector>
# include "PacmanGhost.hpp"
# include "IGame.hpp"

namespace arcade {
    class PacmanGhostPink : public PacmanGhost {
    public:
        ~PacmanGhostPink();
        PacmanGhostPink(const Vector &, int);
        void move(const std::vector<std::string> &map, const Vector &,
            int direction
        ) override;
        void anticipatePacmanMove(const std::vector<std::string> &map,
            const Vector &, int direction
        );
        void chase(const std::vector<std::string> &map) override;
    private:
    };
}
#endif /* OOP_ARCADE_2018_PACMANGHOSTPINK_HPP */
