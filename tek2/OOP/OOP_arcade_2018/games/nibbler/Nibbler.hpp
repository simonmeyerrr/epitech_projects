/*
** EPITECH PROJECT, 2018
** OOP_arcade_2018
** File description:
** Nibbler.hpp
*/
#ifndef OOP_ARCADE_2018_SFML_HPP
# define OOP_ARCADE_2018_SFML_HPP

# include <tuple>
# include <vector>
# include "IGame.hpp"

namespace arcade {

    class MapNibbler {
    public:
        ~MapNibbler() = default;
        MapNibbler(const std::string &path);

        std::string getName() const;
        std::vector <std::string> getMap() const;
        void display(IGraphic &graphic) const;

    private:
        std::string _name;
        std::vector <std::string> _map;
    };

    class Nibbler : public IGame {
    public:
        ~Nibbler();
        Nibbler();

        void setUsername(const std::string &username);
        Event manageEvent(IGraphic &graphic);
        void updateGame();
        void displayWindow(IGraphic &graphic);

    private:
        void loadMaps();
        void startGame();
        void generateApple(std::vector <std::string>);

        Event eventMenu(Event e);
        Event eventNibbler(Event e);
        Event eventPause(Event e);
        Event eventEnd(Event e);

        void updateNibbler();

        void displayMenu(IGraphic &graphic);
        void displayNibbler(IGraphic &graphic);
        void displayPause(IGraphic &graphic);
        void displayEnd(IGraphic &graphic);

        void getScores();

        int _menu;
        std::string _username;
        std::vector<std::string> _art;
        std::vector<std::string> _artPause;

        std::vector<std::tuple<std::string, unsigned int>> _scores;
        unsigned int _scorePos;

        std::vector <MapNibbler> _maps;
        unsigned int _selectMap;
        unsigned int _selectMenu;

        int _direction;
        int _nextDir;
        std::vector <Vector> _nibbler;
        Vector _apple;
        int _update;
    };
}

#endif /* OOP_ARCADE_2018_SFML_HPP */
