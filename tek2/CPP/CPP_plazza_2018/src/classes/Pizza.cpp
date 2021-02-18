/*
** EPITECH PROJECT, 2018
** CPP_plazza_2018
** File description:
** Pizza.cpp
*/

#include <regex>
#include <iostream>
#include "Pizza.hpp"

const std::vector<std::pair<PizzaSize, std::string>> SIZES_NAMES = {
    {S, "S"}, {M, "M"}, {L, "L"}, {XL, "XL"}, {XXL, "XXL"}};

const std::vector<std::pair<PizzaType, std::string>> TYPES_NAMES = {
    {Margarita, "margarita"}, {Regina, "regina"}, {Americana, "americana"},
    {Fantasia, "fantasia"}};

const std::vector<std::pair<PizzaType, Recipe>> RECIPES = {
    {Margarita, {1, {DOE, TOMATO, GRUYERE}}},
    {Regina, {2, {DOE, TOMATO, GRUYERE, HAM, MUSHROOMS}}},
    {Americana, {2, {DOE, TOMATO, GRUYERE, STEAK}}},
    {Fantasia, {4, {DOE, TOMATO, EGGPLANT, GOAT_CHEESE}}}};

PizzaSize Pizza::strToSize(const std::string &size)
{
    PizzaSize ret = UNDEFINED_SIZE;
    for (auto i = SIZES_NAMES.begin(); i != SIZES_NAMES.end(); ++i)
        if (std::get<1>(*i) == size)
            ret = std::get<0>(*i);
    // throw
    return ret;
}

std::string Pizza::sizeToStr(PizzaSize size)
{
    std::string ret("UNDEFINED_SIZE");
    for (auto i = SIZES_NAMES.begin(); i != SIZES_NAMES.end(); ++i)
        if (std::get<0>(*i) == size)
            ret = std::get<1>(*i);
    // throw
    return ret;
}

PizzaType Pizza::strToType(const std::string &type)
{
    PizzaType ret = UNDEFINED_TYPE;
    for (auto i = TYPES_NAMES.begin(); i != TYPES_NAMES.end(); ++i)
        if (std::get<1>(*i) == type)
            ret = std::get<0>(*i);
    // throw
    return ret;
}

std::string Pizza::typeToStr(PizzaType type)
{
    std::string ret("UNDEFINED_TYPE");
    for (auto i = TYPES_NAMES.begin(); i != TYPES_NAMES.end(); ++i)
        if (std::get<0>(*i) == type)
            ret = std::get<1>(*i);
    // throw
    return ret;
}

Ingredients Pizza::getIngredients(PizzaType type)
{
    Ingredients ret;
    for (auto i = RECIPES.begin(); i != RECIPES.end(); ++i)
        if (std::get<0>(*i) == type) {
            auto tmp = std::get<1>(*i);
            ret = std::get<1>(tmp);
        }
// throw
    return ret;
}

int Pizza::getTime(PizzaType type)
{
    int ret = -1;
    for (auto i = RECIPES.begin(); i != RECIPES.end(); ++i)
        if (std::get<0>(*i) == type) {
            auto tmp = std::get<1>(*i);
            ret = std::get<0>(tmp);
        }
// throw
    return ret;
}

Recipe Pizza::getRecipe(PizzaType type)
{
    Recipe ret;
    for (auto i = RECIPES.begin(); i != RECIPES.end(); ++i)
        if (std::get<0>(*i) == type)
            ret = std::get<1>(*i);
    // throw
    return ret;
}

std::deque<std::tuple<PizzaType, PizzaSize, int>> Pizza::parsePizzas(const std::string &str)
{
    std::string tmp(str);
    std::deque<std::tuple<PizzaType, PizzaSize, int>> commands;
    std::regex rgx("([a-zA-Z]+) ([SMXL]+) x([0-9]+)");
    std::smatch rgxBuf;

    while (std::regex_search(tmp, rgxBuf, rgx)) {
        // if (strToType(rgxBuf.str(1) == UNDEFINED_TYPE || strToSize(rgxBuf.str(2) == UNDEFINED_SIZE)
        // throw
        commands.push_back(std::tuple<PizzaType, PizzaSize, int>(
            strToType(rgxBuf.str(1)), strToSize(rgxBuf.str(2)),
            std::stoi(rgxBuf.str(3))));
        tmp = rgxBuf.suffix();
    }

    return commands;
}


