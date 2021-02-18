/*
** EPITECH PROJECT, 2018
** 201yams_2018
** File description:
** Yams.cpp
*/

#include "Yams.hpp"

Yams::Yams(int ac, const char **av)
    : _error(false)
{
    if (ac >= 1)
        _cmd = std::string(av[0]);
    if (ac == 2 && (!strcmp("-h", av[1]) || !strcmp("--help", av[1]))) {
        printUsage();
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
    _error = parseCombination(std::string(av[6]));
}

bool Yams::parseCombination(std::string fmt)
{
    if (!parsePair(fmt))
        return (false);
    if (!parseThree(fmt))
        return (false);
    if (!parseFour(fmt))
        return (false);
    if (!parseYams(fmt))
        return (false);
    if (!parseStraight(fmt))
        return (false);
    if (!parseFull(fmt))
        return (false);
    return (true);
}

bool Yams::parsePair(std::string fmt)
{
    if (fmt.size() == 6) {
        auto pos = fmt.find("pair_");
        if (pos != 0)
            return (true);
        if (fmt[5] < '1' || fmt[5] > '6')
            return (true);
        _figure = "pair";
        _values[0] = fmt[5] - '0';
        return (false);
    }
    return (true);
}

bool Yams::parseThree(std::string fmt)
{
    if (fmt.size() == 7) {
        auto pos = fmt.find("three_");
        if (pos != 0)
            return (true);
        if (fmt[6] < '1' || fmt[6] > '6')
            return (true);
        _figure = "three";
        _values[0] = fmt[6] - '0';
        return (false);
    }
    return (true);
}

bool Yams::parseFour(std::string fmt)
{
    if (fmt.size() == 6) {
        auto pos = fmt.find("four_");
        if (pos != 0)
            return (true);
        if (fmt[5] < '1' || fmt[5] > '6')
            return (true);
        _figure = "four";
        _values[0] = fmt[5] - '0';
        return (false);
    }
    return (true);
}

bool Yams::parseYams(std::string fmt)
{
    if (fmt.size() == 6) {
        auto pos = fmt.find("yams_");
        if (pos != 0)
            return (true);
        if (fmt[5] < '1' || fmt[5] > '6')
            return (true);
        _figure = "yams";
        _values[0] = fmt[5] - '0';
        return (false);
    }
    return (true);
}

bool Yams::parseStraight(std::string fmt)
{
    if (fmt.size() == 10) {
        auto pos = fmt.find("straight_");
        if (pos != 0)
            return (true);
        if (fmt[9] != '5' && fmt[9] != '6')
            return (true);
        _figure = "straight";
        _values[0] = fmt[9] - '0';
        return (false);
    }
    return (true);
}

bool Yams::parseFull(std::string fmt)
{
    if (fmt.size() == 8) {
        auto pos = fmt.find("full_");
        if (pos != 0)
            return (true);
        if (fmt[5] < '1' || fmt[5] > '6')
            return (true);
        if (fmt[6] != '_')
            return (true);
        if (fmt[7] < '1' || fmt[7] > '6' || fmt[7] == fmt[5])
            return (true);
        _figure = "full";
        _values[0] = fmt[5] - '0';
        _values[1] = fmt[7] - '0';
        return (false);
    }
    return (true);
}

bool Yams::hasError() const
{
    return (_error);
}

int Yams::printUsage() const
{
    if (hasError()) {
        std::cerr << "USAGE\n" << TAB << _cmd << " d1 d2 d3 d4 d5 c\n";
        std::cerr << "\nDESCRIPTION\n";
        std::cerr << TAB << "d1   value of the first dice (0 if not throw)\n";
        std::cerr << TAB << "d2   value of the second dice (0 if not throw)\n";
        std::cerr << TAB << "d3   value of the third dice (0 if not throw)\n";
        std::cerr << TAB << "d4   value of the fourth dice (0 if not throw)\n";
        std::cerr << TAB << "d5   value of the fifth dice (0 if not throw)\n";
        std::cerr << TAB << "c    expected combination\n";
    } else {
        std::cout << "USAGE\n" << TAB << _cmd << " d1 d2 d3 d4 d5 c\n";
        std::cout << "\nDESCRIPTION\n";
        std::cout << TAB << "d1   value of the first dice (0 if not throw)\n";
        std::cout << TAB << "d2   value of the second dice (0 if not throw)\n";
        std::cout << TAB << "d3   value of the third dice (0 if not throw)\n";
        std::cout << TAB << "d4   value of the fourth dice (0 if not throw)\n";
        std::cout << TAB << "d5   value of the fifth dice (0 if not throw)\n";
        std::cout << TAB << "c    expected combination\n";
    }
    return (hasError() ? 84 : 0);
}

long double my_pow(long double a, int b)
{
    long double res = 1.0;

    for (int i = 0; i < b; i++)
        res = res * a;
    return (res);
}

int my_factorial(int nb)
{
    if (nb == 0)
        return 1;
    return (nb * my_factorial(nb - 1));
}

long double calcul_binomial(int a, int b)
{
    long double facto = ((long double)my_factorial(a)) / ((long double)
        my_factorial(b) * (long double)my_factorial(a - b));
    long double res = facto * my_pow(1.0 / 6.0, b) * my_pow(1.0 / 5.0,  a - b);
    return (res);
}

long double calcul_proba(int needed, int toReload)
{
    long double res = 0;
    int goodDices = 5 - toReload;

    for (int i = needed - goodDices; i < 5 - goodDices + 1; i++) {
        res += calcul_binomial(5 - goodDices, i);
    }
    return (res * (long double)100.0);
}

void Yams::computePair()
{
    int toReload = 0;
    long double chance = 0;

    for (int i = 0; i < 6; i++) {
        if (_dices[i] != _values[0])
            toReload++;
    }
    if (toReload <= 3)
        chance = 100.0;
    else if (toReload == 4)
        chance = 51.77;
    else if (toReload == 5)
        chance = 19.62;
    else
        chance = calcul_proba(2, toReload);
    printf("chances to get a %d pair:  %.2LF%%\n", _values[0],
        chance);
}

void Yams::computeThree()
{
    int toReload = 0;
    long double chance = 0;

    for (int i = 0; i < 6; i++) {
        if (_dices[i] != _values[0])
            toReload++;
    }
    if (toReload <= 2)
        chance = 100.0;
    else if (toReload == 3)
        chance = 42.13;
    else if (toReload == 4)
        chance = 13.19;
    else if (toReload == 5)
        chance = 3.55;
    else
        chance = calcul_proba(3, toReload);
    printf("chances to get a %d three-of-a-kind:  %.2LF%%\n", _values[0],
        chance);
}

void Yams::computeFour()
{
    int toReload = 0;
    long double chance = 0;

    for (int i = 0; i < 6; i++) {
        if (_dices[i] != _values[0])
            toReload++;
    }
    if (toReload <= 1)
        chance = 100.0;
    else
        chance = calcul_proba(4, toReload);
    printf("chances to get a %d four-of-a-kind:  %.2LF%%\n", _values[0],
        chance);
}

void Yams::computeYams()
{
    int toReload = 0;
    long double chance = 0;

    for (int i = 0; i < 6; i++) {
        if (_dices[i] != _values[0])
            toReload++;
    }
    if (toReload <= 0)
        chance = 100.0;
    else
        chance = calcul_proba(5, toReload);
    printf("chances to get a %d yams:  %.2LF%%\n", _values[0], chance);
}

void Yams::computeStraight()
{
    int toReload = 0;
    long double chance = 0;

    for (int i = 0; i < 6; i++) {
        if (_dices[i] != _values[0])
            toReload++;
    }
    if (toReload <= 0)
        chance = 100.0;
    else
        chance = calcul_proba(5, toReload);
    printf("chances to get a %d straight:  %.2LF%%\n", _values[0], chance);
}

void Yams::computeFull()
{
}

void Yams::dump()
{
    if (_figure == "pair")
        computePair();
    else if (_figure == "three")
        computeThree();
    else if (_figure == "four")
        computeFour();
    else if (_figure == "yams")
        computeYams();
    else if (_figure == "straight")
        computeStraight();
    else if (_figure == "full")
        computeFull();
}