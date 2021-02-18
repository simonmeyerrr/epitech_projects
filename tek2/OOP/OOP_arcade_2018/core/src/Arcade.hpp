/*
** EPITECH PROJECT, 2018
** OOP_arcade_2018
** File description:
** Arcade.hpp
*/

#ifndef OOP_ARCADE_2018_ARCADE_HPP
# define OOP_ARCADE_2018_ARCADE_HPP

# include <map>
# include <vector>
# include <string>
# include "IGame.hpp"

namespace arcade {
    class Arcade {
    public:
        ~Arcade();
        Arcade();

        Event manageEvent(IGraphic &graphic);
        void displayWindow(IGraphic &graph, const std::vector<std::string> &);
        std::string getUsername() const;
        std::string getGamePath() const;

    private:
        void searchGames();
        void getScores();
        void addScore(unsigned int i, std::string file, std::string map);

        std::string _username;
        unsigned int _itUsername;

        std::vector<std::string> _games;
        std::vector<std::string> _gamesPath;
        std::vector<std::vector<std::vector<std::vector<std::string>>>> _scores;
        unsigned int _itGames;

        std::vector <std::string> _art;
    };
}

#endif /* OOP_ARCADE_2018_ARCADE_HPP */
