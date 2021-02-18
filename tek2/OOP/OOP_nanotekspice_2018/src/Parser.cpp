/*
** EPITECH PROJECT, 2018
** OOP_nanotekspice_2018
** File description:
** Parser.cpp
*/

#include <exception>
#include <fstream>
#include <iostream>
#include "Parser.hpp"
#include "Errors.hpp"

namespace nts {

    std::string Parser::cleanString(std::string str)
    {
        size_t pos = str.find("#");

        if (pos != std::string::npos)
            str.replace(pos, str.size() - pos, "");

        pos = str.find("\t");
        while (pos != std::string::npos) {
            str.replace(pos, 1, " ");
            pos = str.find("\t");
        }
        pos = str.find("  ");
        while (pos != std::string::npos) {
            str.replace(pos, 2, " ");
            pos = str.find("  ");
        }

        pos = str.find(" ");
        if (pos != std::string::npos && pos == 0)
            str.replace(pos, 1, "");

        pos = str.find(" ");
        if (pos != std::string::npos && pos == str.size() - 1)
            str.replace(pos, 1, "");
        return (str);
    }

    bool Parser::valid_nb(std::string str)
    {
        size_t i = 0;

        for (i = 0; i < str.size(); i++) {
            if (str[i] < '0' || str[i] > '9')
                return (false);
        }
        return (i > 0);
    }

    int Parser::type0(std::string line, Chipset &chipset)
    {
        (void)chipset;
        if (line != ".chipsets:")
            throw nts::InputError("Missing .chipsets", "Nts file");
        return (1);
    }

    int Parser::type1(std::string line, Chipset &chipset)
    {
        if (line == ".links:")
            return (2);
        size_t pos = line.find(" ");
        if (pos == std::string::npos)
            throw nts::InputError("Invalid component initializer", "Nts file");
        std::string type = line.substr(0, pos);
        std::string value = line.substr(pos + 1, line.size());
        pos = value.find(" ");
        if (pos != std::string::npos)
            throw nts::InputError("Invalid component initializer", "Nts file");
        chipset[value] = nts::Factory::createComponent(type, value);
        return (1);
    }

    int Parser::type2(std::string line, Chipset &chipset)
    {
        size_t pos = line.find(" ");
        if (pos == std::string::npos)
            throw nts::InputError("Invalid link", "Nts file");
        std::string from = line.substr(0, pos);
        std::string to = line.substr(pos + 1, line.size());
        pos = to.find(" ");
        if (pos != std::string::npos)
            throw nts::InputError("Invalid link", "Nts file");
        pos = from.find(":");
        if (pos == std::string::npos)
            throw nts::InputError("Invalid link", "Nts file");
        std::string from1 = from.substr(0, pos);
        std::string from2 = from.substr(pos + 1, from.size());
        if (!valid_nb(from2))
            throw nts::InputError("Invalid link", "Nts file");
        chipset.at(from1);
        pos = to.find(":");
        if (pos == std::string::npos)
            throw nts::InputError("Invalid link", "Nts file");
        std::string to1 = to.substr(0, pos);
        std::string to2 = to.substr(pos + 1, to.size());
        if (!valid_nb(to2))
            throw nts::InputError("Invalid link", "Nts file");
        chipset.at(to1);
        if (chipset.at(from1)->getPinType((size_t)atoi(from2.c_str())) == OUT)
            chipset.at(to1)->setLink((size_t)atoi(to2.c_str()),
                *(chipset.at(from1)), (size_t)atoi(from2.c_str()));
        else
            chipset.at(from1)->setLink((size_t)atoi(from2.c_str()),
                *(chipset.at(to1)), (size_t)atoi(to2.c_str()));
        return (2);
    }

    int Parser::manageLine(std::string line, Chipset &chipset, int type)
    {
        int (*func[])(std::string, Chipset &) = {&type0, &type1, &type2};
        line = cleanString(line);
        if (line.empty())
            return (type);
        return (func[type](line, chipset));
    }

    Chipset Parser::getChipset(const std::string &file,
        std::vector<std::string> values)
    {
        (void)values;

        Chipset chipset;
        std::string line;
        int type = 0;
        std::ifstream in(file);

        if (!in)
            throw std::exception();
        while (std::getline(in, line)) {
            type = manageLine(line, chipset, type);
        }
        return (chipset);
    }
}