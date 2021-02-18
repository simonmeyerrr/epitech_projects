/*
** EPITECH PROJECT, 2018
** OOP_arcade_2018
** File description:
** Ncurses.hpp
*/
#ifndef OOP_ARCADE_2018_Ncuses_HPP
# define OOP_ARCADE_2018_Ncuses_HPP

# include "IGraphic.hpp"

namespace arcade {

    class Ncurses : public IGraphic {
    public:
        ~Ncurses() override;
        Ncurses();

        Event getEvent() override;
        void clearWindow(Color color = ARCADE_BLACK);
        void displayWindow();
        void printPixel(Vector v, Color color = ARCADE_WHITE);
        void printRectangle(Vector pos, Vector size, Color color = ARCADE_WHITE
        );
        void printText(Vector v, const std::string &text,
            Color color = ARCADE_WHITE, Color background = ARCADE_TRANSPARENT
        );
        typedef struct event_s {
            int value;
            Event event;
        } event_t;
    private:
        short getPair(Color color, Color colorBackground);
    };
}

#endif /* OOP_ARCADE_2018_Ncuses_HPP */
