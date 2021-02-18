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
# include "../Object/Toy/LittlePony.hpp"
# include "../Object/Toy/Teddy.hpp"
# include "../Object/Wrap/Paper.hpp"
# include "../Object/Wrap/Box.hpp"

class XMLDeserializer {
public:
    XMLDeserializer() = default;
    ~XMLDeserializer() = default;

    Object *openGift(const std::string &fileName);

    Object *readPaperTag(std::ifstream &fileStream);
    Object *readBoxTag(std::ifstream &fileStream);
    Object *readToyTag(std::ifstream &fileStream);

    bool isValidTag(const std::string &line, const std::string &tagName);
};

#endif //CPP_RUSH2_2018_XMLDESERIALIZER_HPP
