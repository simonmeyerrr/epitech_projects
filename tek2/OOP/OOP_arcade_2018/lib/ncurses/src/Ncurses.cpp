/*
** EPITECH PROJECT, 2018
** OOP_arcade_2018
** File description:
** Ncurses.cpp
*/

#include <memory>
#include <tuple>
#include <string>
#include <iostream>
#include "Ncurses.hpp"
#include <ncurses.h>

void __attribute__((constructor)) ctor()
{
}

void __attribute__((destructor)) dtor()
{
}

extern "C" arcade::IGraphic *init()
{
    return new arcade::Ncurses();
}

namespace arcade {
    static const Ncurses::event_t events[] = {{'A', ARCADE_KEY_A},
        {'a', ARCADE_KEY_A}, {'B', ARCADE_KEY_B}, {'b', ARCADE_KEY_B},
        {'C', ARCADE_KEY_C}, {'c', ARCADE_KEY_C}, {'D', ARCADE_KEY_D},
        {'d', ARCADE_KEY_D}, {'E', ARCADE_KEY_E}, {'e', ARCADE_KEY_E},
        {'F', ARCADE_KEY_F}, {'f', ARCADE_KEY_F}, {'G', ARCADE_KEY_G},
        {'g', ARCADE_KEY_G}, {'H', ARCADE_KEY_H}, {'h', ARCADE_KEY_H},
        {'I', ARCADE_KEY_I}, {'i', ARCADE_KEY_I}, {'J', ARCADE_KEY_J},
        {'j', ARCADE_KEY_J}, {'K', ARCADE_KEY_K}, {'k', ARCADE_KEY_K},
        {'L', ARCADE_KEY_L}, {'l', ARCADE_KEY_L}, {'M', ARCADE_KEY_M},
        {'m', ARCADE_KEY_M}, {'N', ARCADE_KEY_N}, {'n', ARCADE_KEY_N},
        {'O', ARCADE_KEY_O}, {'o', ARCADE_KEY_O}, {'P', ARCADE_KEY_P},
        {'p', ARCADE_KEY_P}, {'Q', ARCADE_KEY_Q}, {'q', ARCADE_KEY_Q},
        {'R', ARCADE_KEY_R}, {'r', ARCADE_KEY_R}, {'S', ARCADE_KEY_S},
        {'s', ARCADE_KEY_S}, {'T', ARCADE_KEY_T}, {'t', ARCADE_KEY_T},
        {'U', ARCADE_KEY_U}, {'u', ARCADE_KEY_U}, {'V', ARCADE_KEY_V},
        {'v', ARCADE_KEY_V}, {'W', ARCADE_KEY_W}, {'w', ARCADE_KEY_W},
        {'X', ARCADE_KEY_X}, {'x', ARCADE_KEY_X}, {'Y', ARCADE_KEY_Y},
        {'y', ARCADE_KEY_Y}, {'z', ARCADE_KEY_Z}, {'Z', ARCADE_KEY_Z},
        {'0', ARCADE_KEY_0}, {'1', ARCADE_KEY_1}, {'&', ARCADE_KEY_1},
        {'2', ARCADE_KEY_2}, {'3', ARCADE_KEY_3}, {'\"', ARCADE_KEY_3},
        {'4', ARCADE_KEY_4}, {'\'', ARCADE_KEY_4}, {'5', ARCADE_KEY_5},
        {'(', ARCADE_KEY_5}, {'6', ARCADE_KEY_6}, {'-', ARCADE_KEY_6},
        {'7', ARCADE_KEY_7}, {'8', ARCADE_KEY_8}, {'_', ARCADE_KEY_8},
        {'9', ARCADE_KEY_9}, {265, ARCADE_KEY_F1}, {266, ARCADE_KEY_F2},
        {267, ARCADE_KEY_F3}, {268, ARCADE_KEY_F4}, {269, ARCADE_KEY_F5},
        {270, ARCADE_KEY_F6}, {271, ARCADE_KEY_F7}, {272, ARCADE_KEY_F8},
        {273, ARCADE_KEY_F9}, {274, ARCADE_KEY_F10}, {410, ARCADE_KEY_F11},
        {276, ARCADE_KEY_F12}, {9, ARCADE_KEY_TAB}, {' ', ARCADE_KEY_SPACE},
        {27, ARCADE_KEY_ESCAPE}, {10, ARCADE_KEY_ENTER},
        {263, ARCADE_KEY_DELETE}, {261, ARCADE_KEY_RIGHT},
        {260, ARCADE_KEY_LEFT}, {259, ARCADE_KEY_UP}, {258, ARCADE_KEY_DOWN}};

    static const short colorArray[] = {COLOR_BLACK, COLOR_WHITE, COLOR_BLACK,
        COLOR_RED, COLOR_BLUE, COLOR_GREEN, COLOR_YELLOW, COLOR_MAGENTA,
        COLOR_CYAN};

    Ncurses::Ncurses()
    {
        initscr();
        noecho();
        cbreak();
        curs_set(false);
        nodelay(stdscr, true);
        start_color();
        keypad(stdscr, true);
        mousemask(ALL_MOUSE_EVENTS, nullptr);
        clear();
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                init_pair(static_cast<short>(i * 9 + j), colorArray[i],
                    colorArray[j]);
            }
        }
    }

    Ncurses::~Ncurses()
    {
        endwin();
    }

    Event Ncurses::getEvent()
    {
        MEVENT e;
        int valueEvent = getch();

        if (valueEvent == KEY_MOUSE && getmouse(&e) == OK) {
            if (e.bstate & BUTTON1_CLICKED)
                return (Event(ARCADE_CLICK_LEFT, e.x / 2, e.y));
            else if (e.bstate & BUTTON3_CLICKED)
                return (Event(ARCADE_CLICK_RIGHT, e.x / 2, e.y));
        }
        for (const auto &event : events) {
            if (event.value == valueEvent)
                return event.event;
        }
        return ARCADE_NO_EVENT;
    }

    void Ncurses::clearWindow(Color color)
    {
        clear();
        (void)color;
    }

    void Ncurses::displayWindow()
    {
        refresh();
    }

    void Ncurses::printPixel(Vector v, Color color)
    {
        short pair = getPair(ARCADE_WHITE, color);

        attron(COLOR_PAIR(pair));
        mvprintw(v.y, v.x * 2, "  ");
        attroff(COLOR_PAIR(pair));
    }

    void Ncurses::printRectangle(Vector pos, Vector size, Color color)
    {
        short pair = getPair(ARCADE_WHITE, color);

        attron(COLOR_PAIR(pair));
        for (int y = 0; y < size.y; y++) {
            for (int x = 0; x < size.x; x++) {
                mvprintw(pos.y + y, (pos.x + x) * 2, "  ");
            }
        }
        attroff(COLOR_PAIR(pair));
    }

    void Ncurses::printText(Vector v, const std::string &text, Color color,
        Color background
    )
    {
        short pair = getPair(color, background);
        std::string str = text;

        if (str.size() % 2 == 1)
            str += " ";
        attron(COLOR_PAIR(pair));
        mvprintw(v.y, v.x * 2, str.c_str());
        attroff(COLOR_PAIR(pair));
    }

    short Ncurses::getPair(Color colorText, Color colorBackground)
    {
        int y = 0;
        int x = 0;

        for (y = 0; y < 9; y++) {
            for (x = 0; x < 9; x++) {
                if (colorText == y && colorBackground == x)
                    return static_cast<short>(y * 9 + x);
            }
        }
        return 0;
    }
}