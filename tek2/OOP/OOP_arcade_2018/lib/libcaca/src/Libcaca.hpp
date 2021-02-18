/*
** EPITECH PROJECT, 2018
** OOP_arcade_2018
** File description:
** Libcaca.hpp
*/
#ifndef OOP_ARCADE_2018_LIBCACA_HPP
# define OOP_ARCADE_2018_LIBCACA_HPP

# include "caca.h"
# include "caca_types.h"
# include "IGraphic.hpp"

namespace arcade {
    class Libcaca : public IGraphic {
    public:
        ~Libcaca();
        Libcaca();

        Event getEvent();
        void clearWindow(Color color = ARCADE_BLACK);
        void displayWindow();
        void printPixel(Vector v, Color color = ARCADE_WHITE);
        void printRectangle(Vector pos, Vector size, Color color = ARCADE_WHITE);
        void printText(Vector v, const std::string &text, Color color = ARCADE_WHITE,
            Color background = ARCADE_TRANSPARENT);

    private:
        int getColor(Color color);
        caca_canvas_t *_canvas;
        caca_display_t *_display;
        caca_event_t _event;
    };
}

#endif /* OOP_ARCADE_2018_LIBCACA_HPP */
