/*
** EPITECH PROJECT, 2018
** OOP_arcade_2018
** File description:
** Minesweeper.cpp
*/

#include <memory>
#include <fstream>
#include <iostream>
#include <regex>
#include "Minesweeper.hpp"

void __attribute__((constructor)) ctor()
{
}

void __attribute__((destructor)) dtor()
{
}

extern "C" arcade::IGame *init()
{
    return new arcade::Minesweeper();
}

namespace arcade {

    static const Color colors[] = {ARCADE_WHITE, ARCADE_BLACK, ARCADE_RED,
        ARCADE_BLUE, ARCADE_GREEN, ARCADE_YELLOW, ARCADE_MAGENTA, ARCADE_CYAN};

    Minesweeper::~Minesweeper()
    {
    }

    Minesweeper::Minesweeper()
        :   _level(1), _bombs(0), _flags(0), _failed(false),
        _launched(false), _restart(false), _win(false)
    {

        std::string buf = "                                      ";
        for (std::size_t i = 0; i < 18; i++) {
            _game.push_back(buf);
            _data.push_back(buf);
        }
        std::ifstream in("./assets/minesweeper.txt");
        if (in) {
            std::string line;
            while (std::getline(in, line))
                _bck.push_back(line);
        }
        getScore("easy", _easy);
        getScore("adept", _adept);
        getScore("hard", _hard);
    }

    bool compareScore(std::vector<std::string> a, std::vector<std::string> b)
    {
        std::regex rgx("^([0-9]+):([0-9]+)");
        std::smatch rgxBuf;
        std::regex_search(a[1], rgxBuf, rgx);
        int aT = (60 * std::stoi(rgxBuf[1])) + (std::stoi(rgxBuf[2]));
        std::regex_search(b[1], rgxBuf, rgx);
        int bT = (60 * std::stoi(rgxBuf[1])) + (std::stoi(rgxBuf[2]));
        if (aT == bT)
            return (true);
        else
            return (aT < bT);
    }

    void Minesweeper::getScore(const std::string &lvl,
        std::vector<std::vector<std::string>> &v)
    {
        v.clear();
        std::ifstream in("./assets/minesweeper_score_" + lvl + ".txt");
        std::regex rgx("^([A-Z]+) ([0-9]+:[0-9]+)");
        std::smatch rgxBuf;
        std::string line;
        if (!in)
            return;
        while (std::getline(in, line)) {
            std::vector<std::string> tmp;
            if (std::regex_search(line, rgxBuf, rgx)) {
                for (size_t i = 1; i < 3; i++)
                    tmp.push_back(rgxBuf[i]);
                v.push_back(tmp);
            }
        }
        std::sort(v.begin(), v.end(), compareScore);
    }

    void Minesweeper::setUsername(const std::string &username)
    {
        _username = username;
    }

    Event Minesweeper::manageEvent(IGraphic &graphic)
    {
        Event e = graphic.getEvent();
        EventType t = e.getType();
        Vector pos = e.getPos();

        startGame(t);
        if (t == ARCADE_CLICK_LEFT && _launched == true
            && pos.x >= 21 && pos.x < 21 + WIDTH
            && pos.y >= 16 && pos.y < 16 + HEIGHT) {
            if (_game[pos.y - 16][pos.x - 21] == '.')
                endGame();
            else
                dig(pos.y - 16, pos.x - 21);
        } else if (t == ARCADE_CLICK_RIGHT && _launched == true
            && pos.x >= 21 && pos.x < 21 + WIDTH
            && pos.y >= 16 && pos.y < 16 + HEIGHT) {
            flag(pos.y - 16, pos.x - 21);
        }
        return (e);
    }

    void Minesweeper::addScore()
    {
        std::ofstream score;
        if (_username == "")
            return;
        if (_level == 1)
            score.open("./assets/minesweeper_score_easy.txt",
                std::ios_base::app);
        if (_level == 2)
            score.open("./assets/minesweeper_score_adept.txt",
                std::ios_base::app);
        if (_level == 3)
            score.open("./assets/minesweeper_score_hard.txt",
                std::ios_base::app);
        score << _username + " " + _endTime << std::endl;
        getScore("easy", _easy);
        getScore("adept", _adept);
        getScore("hard", _hard);
    }

    void Minesweeper::checkFlag()
    {
        FOR_DATA_M {
            FOR_DATA_L {
                if (_game[i][j] == '.') {
                    if (_data[i][j] != 'F') {
                        return;
                    }
                }
            }
        }
        FOR_DATA_M {
            FOR_DATA_L {
                if (_data[i][j] == 'F' && _game[i][j] == '.')
                    _data[i][j] = 'G';
                else if (_data[i][j] == 'F' && _game[i][j] != '.')
                    _data[i][j] = 'B';
                else
                    _data[i][j] = ' ';
            }
        }
        _win = true;
        _launched = false;
        _endTime = getTime();
        addScore();
    }

    void Minesweeper::flag(int i, int j)
    {
        if (_data[i][j] == 'F') {
            _data[i][j] = '6';
            _flags--;
        } else if (_data[i][j] == '6') {
            _data[i][j] = 'F';
            _flags++;
        }
        if (_flags == _bombs)
            checkFlag();
    }

    void Minesweeper::endGame()
    {
        FOR_DATA_M {
            FOR_DATA_L {
                if (_data[i][j] == 'F' && _game[i][j] == '.')
                    _data[i][j] = 'G';
                else if (_data[i][j] != 'G' && _game[i][j] == '.')
                    _data[i][j] = 'B';
                else
                    _data[i][j] = ' ';
            }
        }
        _launched = false;
        _failed = true;
        _endTime = getTime();
    }

    void Minesweeper::dig(int i, int j)
    {
        if (_data[i][j] == 'F')
            _flags--;
        if (_data[i][j] == ' ')
            return;
        _data[i][j] = ' ';
        if (_game[i][j] != ' ')
            return;
        if (i - 1 >= 0 && UP != '.')
            dig(i - 1, j);
        if (i >= 0 && j - 1 >= 0 && LEFT != '.')
            dig(i, j - 1);
        if (i >= 0 && j + 1 < 38 && RIGHT != '.')
            dig(i, j + 1);
        if (i + 1 < 18 && DOWN != '.')
            dig(i + 1, j);
    }

    char Minesweeper::nearBomb(int i, int j) const
    {
        char c = '0';

        if (_game[i][j] == '.')
            return ('.');
        if (i - 1 >= 0 && j - 1 >= 0 && UP_LEFT == '.')
            c++;
        if (i - 1 >= 0 && UP == '.')
            c++;
        if (i - 1 >= 0 && j + 1 < WIDTH && UP_RIGHT == '.')
            c++;
        if (i >= 0 && j - 1 >= 0 && LEFT == '.')
            c++;
        if (i >= 0 && j + 1 < WIDTH && RIGHT == '.')
            c++;
        if (i + 1 < HEIGHT && j - 1 >= 0 && DOWN_LEFT == '.')
            c++;
        if (i + 1 < HEIGHT && DOWN == '.')
            c++;
        if (i + 1 < HEIGHT && j + 1 < WIDTH &&
            DOWN_RIGHT == '.')
            c++;
        if (c != '0')
            return (c);
        return (' ');
    }

    void Minesweeper::startGame(EventType t)
    {
        if (t == ARCADE_KEY_E || t == ARCADE_KEY_A || t == ARCADE_KEY_H) {
            if (t == ARCADE_KEY_E)
                _level = 1;
            if (t == ARCADE_KEY_A)
                _level = 2;
            if (t == ARCADE_KEY_H)
                _level = 3;
            _restart = true;
        }
        if (t == ARCADE_KEY_SPACE)
            _restart = true;
        if (_restart) {
            _failed = false;
            _flags = 0;
            _bombs = 0;
            _win = false;
            FOR_GAME_M {
                FOR_GAME_L {
                    _game[i][j] = ' ';
                }
            }
            while (_bombs != _level * 30) {
                std::size_t x = rand() % WIDTH;
                std::size_t y = rand() % HEIGHT;
                if (_game[y][x] != '.') {
                    _game[y][x] = '.';
                    _bombs++;
                }
            }
            FOR_GAME_M {
                FOR_GAME_L {
                    _game[i][j] = nearBomb((int)i, (int)j);
                }
            }
            FOR_DATA_M {
                FOR_DATA_L {
                    _data[i][j] = '6';
                }
            }
            _restart = false;
            _launched = true;
            _time = std::chrono::system_clock::now();
        }
    }

    void Minesweeper::updateGame()
    {
    }

    void Minesweeper::displayWindow(IGraphic &graphic)
    {
        graphic.clearWindow(ARCADE_BLACK);
        displayBackground(graphic);
        displayGame(graphic);
        display(graphic);
        graphic.displayWindow();
    }

    void Minesweeper::displayBackground(IGraphic &graphic) const
    {
        FOR_BCK_M {
            FOR_BCK_L {
                graphic.printPixel(Vector(j, i), colors[_bck[i][j] - '1']);
            }
        }
    }

    std::string Minesweeper::cStr(char c) const
    {
        std::string buf = " ";
        buf[0] = c;
        return (buf);
    }

    void Minesweeper::displayGame(IGraphic &graphic) const
    {
        FOR_GAME_M {
            FOR_GAME_L {
                if (_game[i][j] >= '1' && _game[i][j] <= '9')
                    graphic.printText(Vector(j + 21, i + 16), cStr(_game[i][j]),
                        colors[_game[i][j] - '0'], ARCADE_WHITE);
                if (_game[i][j] == '.') {
                    graphic.printText(Vector(j + 21, i + 16), "*", ARCADE_BLACK,
                        ARCADE_WHITE);
                }
            }
        }
        FOR_DATA_M {
            FOR_DATA_L {
                if (_data[i][j] == '6' || _data[i][j] == '8')
                    graphic.printPixel(Vector(j + 21, i + 16),
                        colors[_data[i][j] - '1']);
                if (_data[i][j] == 'F')
                    graphic.printText(Vector(j + 21, i + 16), "B",
                    ARCADE_WHITE, ARCADE_RED);
                if (_data[i][j] == 'G')
                    graphic.printText(Vector(j + 21, i + 16), "*",
                    ARCADE_WHITE, ARCADE_GREEN);
                if (_data[i][j] == 'B')
                    graphic.printText(Vector(j + 21, i + 16), "*",
                    ARCADE_WHITE, ARCADE_RED);
            }
        }
    }

    void Minesweeper::displayScore(IGraphic &graphic) const
    {
        TEXT(Vector(23, 18), "EASY:", ARCADE_GREEN, ARCADE_BLACK);
        for (size_t i = 0; i < _easy.size() && i < 11; i++) {
            TEXT(Vector(23, 20 + i), "|", ARCADE_GREEN, ARCADE_BLACK);
            TEXT(Vector(24, 20 + i), _easy[i][0], ARCADE_WHITE, ARCADE_BLACK);
            TEXT(Vector(31, 20 + i), _easy[i][1], ARCADE_WHITE, ARCADE_BLACK);
            if (_username == _easy[i][0])
                TEXT(Vector(31, 20 + i), _easy[i][1], ARCADE_BLACK,
                    ARCADE_WHITE);
        }
        TEXT(Vector(35, 18), "ADEPT:", ARCADE_YELLOW, ARCADE_BLACK);
        for (size_t i = 0; i < _adept.size() && i < 11; i++) {
            TEXT(Vector(35, 20 + i), "|", ARCADE_YELLOW, ARCADE_BLACK);
            TEXT(Vector(36, 20 + i), _adept[i][0], ARCADE_WHITE, ARCADE_BLACK);
            TEXT(Vector(43, 20 + i), _adept[i][1], ARCADE_WHITE, ARCADE_BLACK);
            if (_username == _adept[i][0])
                TEXT(Vector(43, 20 + i), _adept[i][1], ARCADE_BLACK,
                    ARCADE_WHITE);
        }
        TEXT(Vector(47, 18), "HARD:", ARCADE_RED, ARCADE_BLACK);
        for (size_t i = 0; i < _hard.size() && i < 11; i++) {
            TEXT(Vector(47, 20 + i), "|", ARCADE_RED, ARCADE_BLACK);
            TEXT(Vector(48, 20 + i), _hard[i][0], ARCADE_WHITE, ARCADE_BLACK);
            TEXT(Vector(55, 20 + i), _hard[i][1], ARCADE_WHITE, ARCADE_BLACK);
            if (_username == _hard[i][0])
                TEXT(Vector(55, 20 + i), _hard[i][1], ARCADE_BLACK,
                    ARCADE_WHITE);
        }
    }

    std::string Minesweeper::getTime()
    {
        std::chrono::time_point<std::chrono::system_clock> now =
            std::chrono::system_clock::now();
        int tmp = std::chrono::duration_cast<std::chrono::seconds>(now -
            _time).count();
        std::string buf = "";
        if (tmp / 60 < 10)
            buf += "0";
        buf += std::to_string(tmp / 60) + ":";
        if (tmp % 60 < 10)
            buf += "0";
        buf += std::to_string(tmp % 60);
        return (buf);
    }

    void Minesweeper::displayStats(IGraphic &graphic)
    {
        std::string bomb = "BOMBS: " + std::to_string(_bombs);
        std::string flag = "FLAGS: " + std::to_string(_flags);

        TEXT(Vector(21, 35), bomb, ARCADE_WHITE, ARCADE_BLACK);
        TEXT(Vector(27, 35), flag, ARCADE_WHITE, ARCADE_BLACK);
        if (!_failed && !_win)
            TEXT(Vector(33, 35), getTime(), ARCADE_WHITE, ARCADE_BLACK);
        else
            TEXT(Vector(33, 35), _endTime, ARCADE_WHITE, ARCADE_BLACK);
        if (_level == 1 && _easy.size() > 0)
            TEXT(Vector(45, 35), "BEST SCORE IN EASY: " + _easy[0][1],
                ARCADE_WHITE, ARCADE_BLACK);
        if (_level == 2 && _adept.size() > 0)
            TEXT(Vector(45, 35), "BEST SCORE IN ADEPT: " + _adept[0][1],
                ARCADE_WHITE, ARCADE_BLACK);
        if (_level == 3 && _hard.size() > 0)
            TEXT(Vector(45, 35), "BEST SCORE IN HARD: " + _hard[0][1],
                ARCADE_WHITE, ARCADE_BLACK);
    }

    void Minesweeper::display(IGraphic &graphic)
    {
        if (!_launched && _bombs == 0)
            displayScore(graphic);
        if (!_launched && _failed)
            TEXT(Vector(37, 35), "YOU FAILED", ARCADE_RED, ARCADE_BLACK);
        if (!_launched && _win)
            TEXT(Vector(37, 35), "YOU WON", ARCADE_GREEN, ARCADE_BLACK);
        if (_launched || _failed || _win)
            displayStats(graphic);
        TEXT(Vector(12, 42), "ESC: quit", ARCADE_BLACK, ARCADE_WHITE);
        TEXT(Vector(18, 42), "SPACE: restart game", ARCADE_BLACK, ARCADE_WHITE);
        TEXT(Vector(29, 42), "LAUNCH GAME : (E)asy (A)dept H(ard)",
            ARCADE_BLACK, ARCADE_WHITE);
        TEXT(Vector(48, 42), "LEFT CLICK : dig", ARCADE_BLACK, ARCADE_WHITE);
        TEXT(Vector(58, 42), "RIGHT CLICK : put flag", ARCADE_BLACK,
            ARCADE_WHITE);
    }
}
