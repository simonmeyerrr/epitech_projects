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

# define TAB "           "

class Yams {
public:
    ~Yams() = default;
    Yams(int ac, const char **av);

    bool hasError() const;
    int printUsage() const;
    void dump();

private:
    bool parseCombination(std::string);
    bool parsePair(std::string);
    bool parseThree(std::string);
    bool parseFour(std::string);
    bool parseYams(std::string);
    bool parseStraight(std::string);
    bool parseFull(std::string);

    void computePair();
    void computeThree();
    void computeFour();
    void computeYams();
    void computeStraight();
    void computeFull();

    bool _error;
    std::string _cmd;
    int _dices[5];
    int _values[2];
    std::string _figure;
};

#endif /* INC_201YAMS_2018_YAMS_HPP */
