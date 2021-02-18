/*
** EPITECH PROJECT, 2018
** OOP_arcade_2018
** File description:
** Core.hpp
*/

#ifndef OOP_ARCADE_2018_CORE_HPP
# define OOP_ARCADE_2018_CORE_HPP

# include <memory>
# include <vector>
# include <string>
# include "IGraphic.hpp"
# include "IGame.hpp"
# include "Arcade.hpp"

namespace arcade {
    class Core {
    public:
        ~Core();
        Core(const std::string &libGraph);

        void loop();
        void update();
        int event();
        void display();

    private:
        void changeGraphicLib(const std::string &libGraph);
        void changeGameLib(const std::string &libGame);
        void searchGraphs();

        void *_libGraph;
        void *_libGame;

        Arcade _arcade;
        std::unique_ptr<arcade::IGraphic> _graph;
        std::unique_ptr<arcade::IGame> _game;

        std::vector<std::string> _graphicals;
    };
}

#endif /* OOP_ARCADE_2018_CORE_HPP */
