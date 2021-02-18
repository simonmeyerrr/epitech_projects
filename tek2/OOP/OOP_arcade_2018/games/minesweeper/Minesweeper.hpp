/*
** EPITECH PROJECT, 2018
** OOP_arcade_2018
** File description:
** Minesweeper.hpp
*/

#ifndef OOP_ARCADE_2018_MINESWEEPER_HPP
#define OOP_ARCADE_2018_MINESWEEPER_HPP

# include "IGame.hpp"
# include <vector>
# include <chrono>
# include <ctime>

# define HEIGHT (int)_game.size()
# define WIDTH (int)_game[0].size()

# define FOR_GAME_M for (unsigned int i = 0; i < _game.size() && i < 45; i++)
# define FOR_GAME_L for (unsigned int j = 0; j < _game[i].size() && j < 80; j++)
# define FOR_DATA_M for (unsigned int i = 0; i < _data.size() && i < 45; i++)
# define FOR_DATA_L for (unsigned int j = 0; j < _data[i].size() && j < 80; j++)
# define FOR_BCK_M for (unsigned int i = 0; i < _bck.size() && i < 45; i++)
# define FOR_BCK_L for (unsigned int j = 0; j < _bck[i].size() && j < 80; j++)

# define UP_LEFT _game[i - 1][j - 1]
# define UP _game[i - 1][j]
# define UP_RIGHT _game[i - 1][j + 1]
# define LEFT _game[i][j - 1]
# define RIGHT _game[i][j + 1]
# define DOWN_LEFT _game[i + 1][j - 1]
# define DOWN _game[i + 1][j]
# define DOWN_RIGHT _game[i + 1][j + 1]

# define TEXT graphic.printText
# define PIXEL graphic.printPixel

namespace arcade {
    class Minesweeper : public IGame {
    public:
        ~Minesweeper();
        Minesweeper();

        void setUsername(const std::string &username);
        Event manageEvent(IGraphic &graphic);
        void displayWindow(IGraphic &graphic);
        void updateGame();

    private:
        void getScore(const std::string &lvl,
            std::vector<std::vector<std::string>> &v);
        char nearBomb(int i, int j) const;
        std::string cStr(char c) const;
        void startGame(EventType t);
        void flag(int i, int j);
        void dig(int i, int j);
        std::string getTime();
        void checkFlag();
        void addScore();
        void endGame();

        void displayBackground(IGraphic &graphic) const;
        void displayGame(IGraphic &graphic) const;
        void displayScore(IGraphic &graphic) const;
        void displayStats(IGraphic &graphic);
        void display(IGraphic &graphic);

        std::chrono::time_point<std::chrono::system_clock> _time;
        std::vector<std::vector<std::string>> _easy;
        std::vector<std::vector<std::string>> _adept;
        std::vector<std::vector<std::string>> _hard;
        std::vector<std::string> _bck;
        std::vector<std::string> _game;
        std::vector<std::string> _data;
        std::string _username;
        std::string _endTime;
        std::size_t _level;
        std::size_t _bombs;
        std::size_t _flags;
        bool _failed;
        bool _launched;
        bool _restart;
        bool _win;
    };
}

#endif /* OOP_ARCADE_2018_MINESWEEPER_HPP */
