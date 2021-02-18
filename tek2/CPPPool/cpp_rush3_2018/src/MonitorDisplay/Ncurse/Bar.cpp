/*
** EPITECH PROJECT, 2018
** cpp_rush3_2018
** File description:
** Container.hpp
*/

#include "Bar.hpp"

Ncurses::Bar::Bar(std::string const &name, float max, unsigned w, unsigned x,
    unsigned y, bool percentMode, std::string const &unit) : Name(name),
    Max(max), W(w), X(x), Y(y), PercentMode(percentMode), Unit(unit)
{}

void Ncurses::Bar::setValue(float value)
{
    Value = value;
}

void Ncurses::Bar::display() const
{
    float len = (float)(W - Name.length() - 20);
    int bar;
    if (Value == 0 || Max == 0)
        return;
    bar = (int)((Value / Max) * len);
    move(X, Y);
    printw(" ");
    printw(Name.c_str());
    printw(" ");
    printw("[");
    if (bar > (len / 2))
        attron(COLOR_PAIR(2));
    else
        attron(COLOR_PAIR(1));
    for (int i = 0; i < bar; i++)
        printw("|");
    if (bar > (len / 2))
        attroff(COLOR_PAIR(2));
    else
        attroff(COLOR_PAIR(1));
    for (int i = bar; i < len; i++)
        printw(" ");
    printw("] ");
    // for (int i = 0; i < (int)(9 - Unit.length() - (std::to_string((int)Value)).length()); i++)
    //     printw(" ");
    printw("%.2f", ((Value / Max) * 100));
    printw(Unit.c_str());
}
