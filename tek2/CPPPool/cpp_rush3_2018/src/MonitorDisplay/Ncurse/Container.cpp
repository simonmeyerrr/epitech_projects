/*
** EPITECH PROJECT, 2018
** cpp_rush3_2018
** File description:
** Container.hpp
*/

#include "Container.hpp"

Ncurses::Container::Container(unsigned x, unsigned y, unsigned w, unsigned h,
    unsigned color) : X(x), Y(y), W(w), H(h), Color(color)
{
}

void Ncurses::Container::display() const
{
    attron(COLOR_PAIR(Color));
    for (unsigned i = 0; i < W; i++)
        mvprintw(X, Y + i, " ");
    for (unsigned i = 0; i < W; i++)
        mvprintw(X + H - 1, Y + i, " ");
    for (unsigned i = 0; i < H; i++) {
        mvprintw(X + i, Y, "  ");
        mvprintw(X + i, Y + W - 1, "  ");
    }
    attroff(COLOR_PAIR(Color));
    attron(COLOR_PAIR(6));
    mvprintw(X + 1, (W - 8) + Y, " < ");
    mvprintw(X + 1, (W - 4) + Y, " > ");
    attroff(COLOR_PAIR(6));
}

std::tuple<int, int> Ncurses::Container::getPrev() const
{
    return std::make_tuple((W - 8) + Y, X + 1);
}

std::tuple<int, int> Ncurses::Container::getNext() const
{
    return std::make_tuple((W - 4) + Y, X + 1);
}
