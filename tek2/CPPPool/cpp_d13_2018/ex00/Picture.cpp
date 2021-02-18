/*
** EPITECH PROJECT, 2018
** cpp_d13_2018
** File description:
** Picture.cpp
*/

#include <iostream>
#include <fstream>
#include "Picture.hpp"

Picture::Picture(const std::string &file)
{
    data = "";
    if (!file.empty())
        getPictureFromFile(file);
}

Picture::Picture(const Picture &other)
{
    data = other.data;
}

Picture::~Picture()
{
}

bool Picture::getPictureFromFile(const std::string &file)
{
    std::ifstream input(file);

    data = "";
    if (input.is_open()) {
        char c = input.get();
        while (input.good()) {
            data += c;
            c = input.get();
        }
        input.close();
        return (true);
    } else {
        input.close();
        data = "ERROR";
        return (false);
    }
}

Picture &Picture::operator=(const Picture &other)
{
    data = other.data;
    return (*this);
}