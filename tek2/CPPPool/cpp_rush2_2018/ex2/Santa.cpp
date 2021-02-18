/*
** EPITECH PROJECT, 2022
** cpp_rush2_2018
** File description:
** Created by arnaud,
*/

#include <string>
#include <fstream>
#include <iostream>
#include "Santa.hpp"
#include "../ex1/XMLDeserializer/XMLDeserializer.hpp"

Santa::~Santa()
{
}

Santa::Santa(int ac, char **av)
{
    XMLDeserializer xml;
    Object *paper = nullptr;
    Object *box = nullptr;
    Object *toy = nullptr;

    for (int i = 1; i < ac; i++) {
        paper = xml.openGift(std::string(av[i]));
        if (paper) {
            open(paper);
            box = takeIn(paper);
        } else {
            std::cout << "There is no gift ..." << std::endl;
            break;
        }
        if (box) {
            open(box);
            toy = takeIn(box);
        } else {
            std::cout << "The paper was empty ..." << std::endl;
            break;
        }
        yells(toy);
        wrap(box, toy);
        wrap(paper, box);
    }
}

void Santa::yells(const Object *toy) const
{
    if (toy == nullptr) {
        std::cerr << "Box empty, SHEH!!!" << std::endl;
        return;
    }
    std::cout << std::endl << "* yells *" << std::endl << toy->getTitle()
        << " !!!" << std::endl;
}

void Santa::open(Object *wrap)
{
    wrap->openMe();
    std::cout << "Santa opens a " << *wrap << std::endl;
}

void Santa::close(Object *wrap)
{
    wrap->closeMe();
    std::cout << "Santa closes a " << *wrap << std::endl;
}

Object *Santa::takeIn(Object *wrap)
{
    Object *content = wrap->takeObject();
    std::cout << "Santa takes a " << *content << std::endl;
    return content;
}

bool Santa::wrap(Object *wrapper, Object *wrapped)
{
    std::cout << "Santa wraps a " << *wrapped << " in a " << wrapper->describe()
        << std::endl;
    return wrapper->wrapMeThat(wrapped);
}
