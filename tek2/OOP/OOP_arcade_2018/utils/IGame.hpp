/*
** EPITECH PROJECT, 2018
** OOP_arcade_2018
** File description:
** IGame.hpp
*/

#ifndef OOP_ARCADE_2018_IGAME_HPP
# define OOP_ARCADE_2018_IGAME_HPP

# include "IGraphic.hpp"

namespace arcade {
    class IGame {
    public:
        virtual ~IGame() = default;
        virtual void setUsername(const std::string &username) = 0;

        virtual Event manageEvent(IGraphic &graphic) = 0;
        virtual void updateGame() = 0;
        virtual void displayWindow(IGraphic &graphic) = 0;
    };
}

#endif /* OOP_ARCADE_2018_IGAME_HPP */
