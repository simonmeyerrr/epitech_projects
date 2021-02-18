/*
** EPITECH PROJECT, 2018
** cpp_rush3_2018
** File description:
** Container.hpp
*/

#include <ncurses.h>
#include <tuple>

namespace Ncurses
{
    class Container
    {
    public:
        ~Container() = default;
        Container(unsigned x, unsigned y, unsigned w, unsigned h,
            unsigned color);

        void display() const;
        std::tuple<int, int> getPrev() const;
        std::tuple<int, int> getNext() const;

        unsigned X;
        unsigned Y;
        unsigned W;
        unsigned H;
        unsigned Color;
    };
};
