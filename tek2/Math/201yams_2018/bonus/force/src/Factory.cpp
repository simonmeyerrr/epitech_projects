/*
** EPITECH PROJECT, 2018
** 201yams_2018
** File description:
** Factory.cpp
*/

#include <iostream>
#include "Factory.hpp"
#include "Pair.hpp"
#include "Four.hpp"

ICombination *Factory::getPair(const std::string &fmt)
{
    if (fmt.size() != 6)
        return nullptr;
    auto pos = fmt.find("pair_");
    if (pos != 0)
        return (nullptr);
    if (fmt[5] < '1' || fmt[5] > '6')
        return (nullptr);
    return (new Pair((int)(fmt[5] - '0')));
}

ICombination *Factory::getThree(const std::string &fmt)
{
    if (fmt.size() != 8)
        return nullptr;
    auto pos = fmt.find("three_");
    if (pos != 0)
        return (nullptr);
    if (fmt[7] < '1' || fmt[7] > '6')
        return (nullptr);
    return (new Pair((int)(fmt[7] - '0')));
}

ICombination *Factory::getFour(const std::string &fmt)
{
    if (fmt.size() != 6)
        return nullptr;
    auto pos = fmt.find("four_");
    if (pos != 0)
        return (nullptr);
    if (fmt[5] < '1' || fmt[5] > '6')
        return (nullptr);
    return (new Four((int)(fmt[5] - '0')));
}

ICombination *Factory::getFull(const std::string &)
{
    return (nullptr);
}

ICombination *Factory::getStraight(const std::string &)
{
    return (nullptr);
}

ICombination *Factory::getYams(const std::string &fmt)
{
    if (fmt.size() != 6)
        return nullptr;
    auto pos = fmt.find("yams_");
    if (pos != 0)
        return (nullptr);
    if (fmt[5] < '1' || fmt[5] > '6')
        return (nullptr);
    return (new Pair((int)(fmt[5] - '0')));
}

ICombination *Factory::getCombination(const std::string &value)
{
    ICombination *(*funcs[])(const std::string &) =
    {
        &getPair, &getThree, &getFour, &getFull, &getStraight, &getYams
    };
    for (size_t i = 0; i < 6; i++) {
        ICombination *ptr = funcs[i](value);
        if (ptr != nullptr)
            return (ptr);
    }
    return (nullptr);
}