/*
** EPITECH PROJECT, 2018
** cpp_rush2_2018
** File description:
** XMLSerializer.hpp
*/

#ifndef CPP_RUSH2_2018_XMLSERIALIZER_HPP
#define CPP_RUSH2_2018_XMLSERIALIZER_HPP

#include <string>
#include <iostream>
#include <fstream>
#include "../Object/Toy/Toy.hpp"
#include "../Object/Wrap/Paper.hpp"
#include "../Object/Wrap/Box.hpp"

class XMLSerializer {
public:
    const std::string typeName[4] = {"teddy", "pony", "paper", "box"};

    XMLSerializer(Object *obj);
    ~XMLSerializer() = default;

    void writeToyTag(std::ofstream &fileStream, const Object *toy);
    void writePaperTag(std::ofstream &fileStream, const Object *paper);
    void writeBoxTag(std::ofstream &fileStream, const Object *box);

    void writeChild(std::ofstream &fileStream, const std::string &child);

    void writeOpen(std::ofstream &fileStream, const std::string &name);
    void writeClose(std::ofstream &fileStream, const std::string &name);
    void writeParam(std::ofstream &fileStream, const std::string &name,
        const std::string &value);
    void writeParam(std::ofstream &fileStream, const std::string &name,
        bool value);

private:
    int _offset;
};

#endif //CPP_RUSH2_2018_XMLSERIALIZER_HPP
