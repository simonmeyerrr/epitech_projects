/*
** EPITECH PROJECT, 2018
** 201yams_2018
** File description:
** Yams.cpp
*/

#include "Yams.hpp"
#include "Factory.hpp"

Yams::~Yams()
{
    delete _combination;
}

Yams::Yams(int ac, const char **av)
    : _error(false), _help(false), _combination(nullptr)
{
    if (ac >= 1)
        _cmd = std::string(av[0]);
    if (ac == 2 && (!strcmp("-h", av[1]) || !strcmp("--help", av[1]))) {
        _help = true;
        return;
    }
    if (ac != 7) {
        _error = true;
        return;
    }
    for (int i = 0; i < 5; i++) {
        if (strlen(av[i + 1]) == 1 && av[i + 1][0] >= '0' && av[i + 1][0] < '7')
            _dices[i] = av[i + 1][0] - '0';
        else {
            _error = true;
            return;
        }
    }
    bool zero = (_dices[0] == 0);
    for (int i = 1; i < 5; i++) {
        if ((zero && _dices[i] != 0) || (!zero && _dices[i] == 0)) {
            _error = true;
            return;
        }
    }
    _combination = Factory::getCombination(std::string(av[6]));
    if (!_combination)
        _error = true;
}

bool Yams::hasError() const
{
    return (_error);
}

bool Yams::needHelp() const
{
    return (_help);
}

int Yams::printUsage() const
{
    if (hasError()) {
        std::cerr << "USAGE\n\t" << _cmd << " d1 d2 d3 d4 d5 c\n\nDESCRIPTION"
                     "\n\td1\tvalue of the first dice (0 if not throw)"
                     "\n\td2\tvalue of the second dice (0 if not throw)"
                     "\n\td3\tvalue of the third dice (0 if not throw)"
                     "\n\td4\tvalue of the fourth dice (0 if not throw)"
                     "\n\td5\tvalue of the fifth dice (0 if not throw)"
                     "\n\tc\texpected combination" << std::endl;
    } else {
        std::cout << "USAGE\n\t" << _cmd << " d1 d2 d3 d4 d5 c\n\nDESCRIPTION"
                     "\n\td1\tvalue of the first dice (0 if not throw)"
                     "\n\td2\tvalue of the second dice (0 if not throw)"
                     "\n\td3\tvalue of the third dice (0 if not throw)"
                     "\n\td4\tvalue of the fourth dice (0 if not throw)"
                     "\n\td5\tvalue of the fifth dice (0 if not throw)"
                     "\n\tc\texpected combination" << std::endl;
    }
    return (hasError() ? 84 : 0);
}

void Yams::compute()
{
    if (_combination)
        _combination->compute(_dices);
}

void Yams::dump() const
{
    if (_combination)
        _combination->dump();
}