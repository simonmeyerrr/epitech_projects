/*
** EPITECH PROJECT, 2018
** OOP_arcade_2018
** File description:
** Libcaca.cpp
*/

#include <memory>
#include <tuple>
#include <iostream>
#include "Libcaca.hpp"

void __attribute__((constructor)) ctor()
{
}

void __attribute__((destructor)) dtor()
{
}

extern "C" arcade::IGraphic *init()
{
    return new arcade::Libcaca();
}

namespace arcade {
    const std::tuple<int, EventType> events[] = {
        {97, ARCADE_KEY_A}, {98, ARCADE_KEY_B}, {99, ARCADE_KEY_C},
        {100, ARCADE_KEY_D}, {101, ARCADE_KEY_E}, {102, ARCADE_KEY_F},
        {103, ARCADE_KEY_G}, {104, ARCADE_KEY_H}, {105, ARCADE_KEY_I},
        {106, ARCADE_KEY_J}, {107, ARCADE_KEY_K}, {108, ARCADE_KEY_L},
        {109, ARCADE_KEY_M}, {110, ARCADE_KEY_N}, {111, ARCADE_KEY_O},
        {112, ARCADE_KEY_P}, {113, ARCADE_KEY_Q}, {114, ARCADE_KEY_R},
        {115, ARCADE_KEY_S}, {116, ARCADE_KEY_T}, {117, ARCADE_KEY_U},
        {118, ARCADE_KEY_V}, {119, ARCADE_KEY_W}, {120, ARCADE_KEY_X},
        {121, ARCADE_KEY_Y}, {122, ARCADE_KEY_Z}, {224, ARCADE_KEY_0},
        {38, ARCADE_KEY_1}, {233, ARCADE_KEY_2}, {34, ARCADE_KEY_3},
        {39, ARCADE_KEY_4}, {40, ARCADE_KEY_5}, {45, ARCADE_KEY_6},
        {232, ARCADE_KEY_7}, {95, ARCADE_KEY_8}, {231, ARCADE_KEY_9},
        {282, ARCADE_KEY_F1}, {283, ARCADE_KEY_F2}, {284, ARCADE_KEY_F3},
        {285, ARCADE_KEY_F4}, {286, ARCADE_KEY_F5}, {287, ARCADE_KEY_F6},
        {288, ARCADE_KEY_F7}, {289, ARCADE_KEY_F8}, {290, ARCADE_KEY_F9},
        {291, ARCADE_KEY_F10}, {292, ARCADE_KEY_F11}, {293, ARCADE_KEY_F12},
        {275, ARCADE_KEY_LEFT}, {276, ARCADE_KEY_RIGHT}, {273, ARCADE_KEY_UP},
        {274, ARCADE_KEY_DOWN}, {9, ARCADE_KEY_TAB}, {32, ARCADE_KEY_SPACE},
        {27, ARCADE_KEY_ESCAPE}, {13, ARCADE_KEY_ENTER}, {8, ARCADE_KEY_DELETE}
    };

    Libcaca::~Libcaca()
    {
        if (_display)
            caca_free_display(_display);
        if (_canvas)
            caca_free_canvas(_canvas);
    }

    Libcaca::Libcaca()
    {
        _canvas = caca_create_canvas(160, 45);
        if (!_canvas)
            throw std::exception();
        _display = caca_create_display(_canvas);
        if (!_display)
            throw std::exception();
        caca_set_display_time(_display, 20);
        caca_set_display_title(_display, "Arcade");
    }

    Event Libcaca::getEvent()
    {
        caca_get_event(_display, CACA_EVENT_ANY, &_event, 10000);
        if (caca_get_event_type(&_event) == CACA_EVENT_KEY_PRESS)
            for (int i = 0; i < 57; i++)
                if (caca_get_event_key_ch(&_event) == std::get<0>(events[i]))
                    return (Event(std::get<1>(events[i])));
        if (caca_get_event_type(&_event) == CACA_EVENT_QUIT)
            return (Event(ARCADE_CLOSE_WINDOW));
        return (Event(ARCADE_NO_EVENT));
    }

    void Libcaca::clearWindow(Color color)
    {
        caca_set_color_ansi(_canvas, getColor(color), getColor(color));
        caca_clear_canvas(_canvas);
    }

    void Libcaca::displayWindow()
    {
        caca_refresh_display(_display);
    }

    void Libcaca::printPixel(Vector v, Color color)
    {
        caca_set_color_ansi(_canvas, getColor(color), getColor(color));
        caca_put_str(_canvas, v.x * 2, v.y, "  ");
    }

    void Libcaca::printRectangle(Vector pos, Vector size, Color color)
    {
        caca_set_color_ansi(_canvas, getColor(color), getColor(color));
        for (int x = 0; x < size.x; x++)
            for (int y = 0; y < size.y; y++)
                caca_put_str(_canvas, (pos.x + x) * 2, pos.y + y, " ");
    }

    void Libcaca::printText(Vector v, const std::string &str, Color color,
        Color background)
    {
        caca_set_color_ansi(_canvas, getColor(color), getColor(background));
        caca_put_str(_canvas, v.x * 2, v.y, str.c_str());
    }

    int Libcaca::getColor(Color color)
    {
        switch (color) {
            case ARCADE_TRANSPARENT:
                return CACA_BLACK;
            case ARCADE_WHITE:
                return CACA_WHITE;
            case ARCADE_BLACK:
                return CACA_BLACK;
            case ARCADE_RED:
                return CACA_RED;
            case ARCADE_BLUE:
                return CACA_BLUE;
            case ARCADE_GREEN:
                return CACA_GREEN;
            case ARCADE_YELLOW:
                return CACA_YELLOW;
            case ARCADE_MAGENTA:
                return CACA_MAGENTA;
            case ARCADE_CYAN:
                return CACA_CYAN;
            default:
                return CACA_BLACK;
        }
    }
}
