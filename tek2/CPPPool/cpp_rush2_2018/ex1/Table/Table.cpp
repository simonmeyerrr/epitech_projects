/*
** EPITECH PROJECT, 2018
** cpp_rush2_2018
** File description:
** Table.cpp
*/

#include <string>
#include <iostream>
#include "../Object/Object.hpp"
#include "../Object/Wrap/Wrap.hpp"
#include "Table.hpp"

Table::Table()
    :_isBroken(false)
{
    for (int i = 0 ; i < 10 ; i++)
        _objTab[i] = nullptr;
    say("created");
}

Table::~Table()
{
    deleteTabContent();
    say("destroyed");
}

void Table::say(const std::string &message) const
{
    std::cout << "[TABLE] " << message << std::endl;
}

bool Table::isBroken() const
{
    return (_isBroken);
}

void Table::deleteTabContent()
{
    for (int i = 0; i < 10; i++) {
        if (_objTab[i])
            delete _objTab[i];
        _objTab[i] = nullptr;
    }
}

int Table::getObjCount() const
{
    int count = 0;

    for (int i = 0; i < 10; i++) {
        if (_objTab[i])
            count += _objTab[i]->getObjectCount();
    }
    return (count);
}

Object *const *Table::getObjTab() const
{
    return (_objTab);
}

bool Table::setObj(Object *obj, int index)
{
    if (index < 0 || index > 9) {
        say("invalid index");
        return (false);
    } else if (_objTab[index] == nullptr) {
        _objTab[index] = obj;
        say("placed a " + obj->describe() + " at index " +
        std::to_string(index));
        return (true);
    } else {
        return (_objTab[index]->wrapMeThat(obj));
    }
}

bool Table::setObjAtPos(Object *obj, int index)
{
    if (!obj)
        return (false);
    if (_isBroken) {
        say("is broken, you can't place anything on it");
        return (false);
    }
    if (getObjCount() + obj->getObjectCount() <= 10) {
        return (setObj(obj, index));
    } else {
        say("Too much things on the table! It collapses!");
        deleteTabContent();
        delete obj;
        _isBroken = true;
        return (false);
    }
}

Object *Table::takeObjAtPos(int index)
{
    Object *tmp;

    if (_isBroken) {
        say("The table is broken, there is nothing to take");
        return (nullptr);
    }
    if (index < 0 || index > 9 || _objTab[index] == nullptr) {
        say("There is nothing at this position");
        return (nullptr);
    } else {
        tmp = _objTab[index];
        _objTab[index] = nullptr;
        say("took a " + tmp->describe());
        tmp->isTaken();
        return (tmp);
    }
}