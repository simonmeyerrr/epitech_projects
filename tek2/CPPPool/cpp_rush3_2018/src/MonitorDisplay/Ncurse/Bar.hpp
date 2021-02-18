/*
** EPITECH PROJECT, 2018
** cpp_rush3_2018
** File description:
** bar.hpp
*/

#include <string>
#include <ncurses.h>

namespace Ncurses {
    class Bar {
    public:
        ~Bar() = default;
        Bar(std::string const &name, float max, unsigned w, unsigned x,
            unsigned y, bool percent = true, std::string const &unit = "%%");

        void setValue(float value);
        void display() const;

    private:
        std::string const Name;
        float const Max;

        unsigned const W;
        unsigned const X;
        unsigned const Y;

        bool const PercentMode;
        std::string const Unit;
        float Value = 0;
    };
};
