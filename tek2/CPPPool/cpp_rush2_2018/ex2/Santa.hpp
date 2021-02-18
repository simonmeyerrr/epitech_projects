/*
** EPITECH PROJECT, 2022
** cpp_rush2_2018
** File description:
** Created by arnaud,
*/

#include "../ex1/Object/Object.hpp"
#include "../ex1/Object/Wrap/Wrap.hpp"

#ifndef CPP_RUSH2_2018_SANTA_HPP
#define CPP_RUSH2_2018_SANTA_HPP

class Santa
{
public:
    ~Santa();
    Santa(int, char**);
    void yells(const Object *) const;

    void open(Object *);
    void close(Object *);
    Object *takeIn(Object *wrap);
    bool wrap(Object *wrapper, Object *wrapped);
};

#endif //CPP_RUSH2_2018_SANTA_HPP
