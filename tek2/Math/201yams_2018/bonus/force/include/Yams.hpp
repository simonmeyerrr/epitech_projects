/*
** EPITECH PROJECT, 2018
** 201yams_2018
** File description:
** Yams.hpp
*/

#ifndef INC_201YAMS_2018_YAMS_HPP
# define INC_201YAMS_2018_YAMS_HPP

# include <iostream>
# include <string.h>
# include <string>
# include "ICombination.hpp"

class Yams {
public:
    ~Yams();
    Yams(int ac, const char **av);

    bool hasError() const;
    bool needHelp() const;
    int printUsage() const;
    void compute();
    void dump() const;

private:
    bool _error;
    bool _help;
    std::string _cmd;

    int _dices[5];
    ICombination *_combination;
};

#endif /* INC_201YAMS_2018_YAMS_HPP */
