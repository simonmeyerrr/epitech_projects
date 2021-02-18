/*
** EPITECH PROJECT, 2018
** cpp_rush2_2018
** File description:
** XMLDeserializer.hpp
*/

#ifndef CPP_RUSH2_2018_XMLDESERIALIZER_HPP
#define CPP_RUSH2_2018_XMLDESERIALIZER_HPP

# include <fstream>
# include <string>
# include <regex>

#include "../../ex1/Object/Toy/LittlePony.hpp"
#include "../../ex1/Object/Toy/Teddy.hpp"
#include "../../ex1/Object/Wrap/Box.hpp"
#include "../../ex1/Object/Wrap/Paper.hpp"

class XMLDeserializer {
public:
    XMLDeserializer() = default;
    ~XMLDeserializer() = default;

    Object *openGift(const std::string &fileName);
    const std::string readParam(const std::string &line,
                                 const std::string &paramName);
    Object *readPaperTag(std::ifstream &fileStream);
    Object *readBoxTag(std::ifstream &fileStream);
    Object *readToyTag(std::ifstream &fileStream);

    bool isValidTag(const std::string &line, const std::string &tagName);
};

#endif //CPP_RUSH2_2018_XMLDESERIALIZER_HPP
