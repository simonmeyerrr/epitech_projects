/*
** EPITECH PROJECT, 2018
** cpp_rush3_2018
** File description:
** text.hpp
*/

#include <string>
#include <ncurses.h>

namespace Ncurses {
    class Text {
    public:
        ~Text() = default;
        Text(std::string const &name, std::string const &value, unsigned x,
            unsigned y, unsigned nameColor, unsigned valueColor);

        void setValue(std::string const &value);
        void display() const;

    private:
        std::string const Name;
        std::string Value;
        unsigned X;
        unsigned Y;
        unsigned nameColor;
        unsigned valueColor;
    };
}
