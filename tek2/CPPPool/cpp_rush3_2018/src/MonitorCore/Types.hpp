/*
** EPITECH PROJECT, 2018
** cpp_rush3_2018
** File description:
** Types.hpp
*/

#ifndef CPP_RUSH3_2018_TYPES_HPP_
# define CPP_RUSH3_2018_TYPES_HPP_

namespace Types {
    enum DisplayMode {
        SFML,
        NCURSE,
        UNKNOWN
    };

    enum Modules {
        INFO,
        CPU,
        MEMORY,
        NETWORK,
        REPORTS,
        BATTERY,
        DAN,
        NONE
    };

    enum Offset {
        LEFT,
        NORMAL,
        RIGHT
    };
}

#endif /* CPP_RUSH3_2018_TYPES_HPP_ */
