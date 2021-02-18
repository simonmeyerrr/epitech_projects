/*
** EPITECH PROJECT, 2018
** cpp_rush3_2018
** File description:
** Parser.hpp
*/

#ifndef CPP_RUSH3_2018_PARSER_HPP_
# define CPP_RUSH3_2018_PARSER_HPP_

# include "../MonitorCore/Types.hpp"
# include <iostream>
# include <vector>
# include <string>

class Parser {
public:
    ~Parser() = default;
    Parser(int ac, const char **av);
    Parser(const Parser &);
    Parser &operator=(const Parser &);

    Types::DisplayMode getMode() const;
    Types::Modules *getModules();
    void printUsage() const;

private:
    int _ac;
    std::vector<std::string> _av;
    Types::Modules _mods[4];
};

#endif /* CPP_RUSH3_2018_PARSER_HPP_ */
