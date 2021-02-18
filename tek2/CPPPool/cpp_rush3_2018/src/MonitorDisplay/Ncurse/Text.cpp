/*
** EPITECH PROJECT, 2018
** cpp_rush3_2018
** File description:
** Container.hpp
*/

#include "Text.hpp"

Ncurses::Text::Text(std::string const &name, std::string const &value,
    unsigned x, unsigned y, unsigned nameColor, unsigned valueColor) : Name(
    name), Value(value), X(x), Y(y), nameColor(nameColor),
    valueColor(valueColor)
{
}

void Ncurses::Text::setValue(std::string const &value)
{
    Value = value;
}

void Ncurses::Text::display() const
{
    move(X, Y);
    printw(" ");
    attron(A_BOLD);
    attron(COLOR_PAIR(nameColor));
    printw(Name.c_str());
    printw(": ");
    attroff(COLOR_PAIR(nameColor));
    attroff(A_BOLD);
    attron(COLOR_PAIR(valueColor));
    printw(Value.c_str());
    attroff(COLOR_PAIR(valueColor));
}
