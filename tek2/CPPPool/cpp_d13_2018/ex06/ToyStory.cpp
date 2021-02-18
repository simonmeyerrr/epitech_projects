/*
** EPITECH PROJECT, 2018
** cpp_d13_2018
** File description:
** ToyStory.cpp
*/

#include <iostream>
#include <fstream>
#include "ToyStory.hpp"

ToyStory::ToyStory()
{
}

ToyStory::~ToyStory()
{
}

void ToyStory::tellMeAStory(const std::string &file,
    Toy &toy1, bool(Toy::*func1)(const std::string &),
    Toy &toy2, bool (Toy::*func2)(const std::string &))
{
    std::ifstream input(file);
    std::string line;
    int i = 0;
    if (input.is_open()) {
        std::cout << toy1.getAscii() << std::endl << toy2.getAscii() <<
            std::endl;
        while (std::getline(input, line) &&
            toy1.getLastError().type == Toy::Error::UNKNOWN &&
            toy2.getLastError().type == Toy::Error::UNKNOWN) {
            i = continueStory(i, line, (i ? toy2 : toy1), (i ? func2 : func1));
        }
    } else {
        std::cout << "Bad Story" << std::endl;
    }
    input.close();
    if (toy1.getLastError().type != Toy::Error::UNKNOWN) {
        std::cout << toy1.getLastError().where() << ": " <<
            toy1.getLastError().what() << std::endl;
    }
    if (toy2.getLastError().type != Toy::Error::UNKNOWN) {
        std::cout << toy2.getLastError().where() << ": " <<
            toy2.getLastError().what() << std::endl;
    }
}

int ToyStory::continueStory(int i, const std::string &line, Toy &toy,
    bool (Toy::*func)(const std::string &))
{
    if (line.size() >= 8 && !line.compare(0, 8, "picture:")) {
        if (toy.setAscii(line.substr(8, line.size() - 8)))
            std::cout << toy.getAscii() << std::endl;
        return (i);
    } else {
        (toy.*func)(line);
        return (i ? 0 : 1);
    }
}
