/*
** EPITECH PROJECT, 2018
** OOP_nanotekspice_2018
** File description:
** Parser.hpp
*/

#ifndef OOP_NANOTEKSPICE_2018_PARSER_HPP_
# define OOP_NANOTEKSPICE_2018_PARSER_HPP_

#include <map>
#include <vector>
#include "Components/Factory.hpp"

namespace nts {

    typedef std::map<std::string, Component> Chipset;

    class Parser {
    public:
        ~Parser() = default;
        Parser() = default;

        static Chipset getChipset(const std::string &file,
            std::vector<std::string> values);
    private:
        static std::string cleanString(std::string str);
        static bool valid_nb(std::string str);
        static int type0(std::string line, Chipset &chipset);
        static int type1(std::string line, Chipset &chipset);
        static int type2(std::string line, Chipset &chipset);
        static int manageLine(std::string line, Chipset &chipset, int type);
    };
}

#endif /* OOP_NANOTEKSPICE_2018_PARSER_HPP_ */
