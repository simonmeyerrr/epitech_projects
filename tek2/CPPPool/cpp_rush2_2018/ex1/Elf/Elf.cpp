/*
** EPITECH PROJECT, 2018
** cpp_rush2_2018
** File description:
** Elf.cpp
*/

#include <iostream>
#include "Elf.hpp"

Elf::Elf() : _obj(nullptr)
{
    say("created");
}

Elf::~Elf()
{
    if (_obj)
        delete _obj;
    say("deleted");
}

void Elf::say(const std::string &message) const
{
    std::cout << "[ELF] " << message << std::endl;
}

bool Elf::put(ITable &table, int pos)
{
    if (!_obj) {
        say("I don't have any object to put on this table");
        return (false);
    } else if (table.setObjAtPos(_obj, pos)) {
        _obj = nullptr;
        return (true);
    } else {
        say("I can't put that here !");
        return (false);
    }
}

bool Elf::take(ITable &table, int pos)
{
    if (_obj) {
        say("I already have something in my hand !");
        return (false);
    }

    _obj = table.takeObjAtPos(pos);
    if (_obj) {
        say("I took a " + _obj->describe());
        return (true);
    } else {
        say("There where nothing at this place");
        return (false);
    }
}

Object *const *Elf::look(const ITable &table) const
{
    auto tab = table.getObjTab();

    say("Look at the table :");
    for (int i = 0; i < 10; i++) {
        if (tab[i])
            std::cout << "[" << i << "] " << *(tab[i]) << std::endl;
        else
            std::cout << "[" << i << "] nothing" << std::endl;
    }
    return (tab);
}

bool Elf::put(IConveyorBelt &conv)
{
    if (!_obj) {
        say("I don't have any object to put on this conveyor belt");
        return (false);
    } else if (conv.put(_obj)) {
        _obj = nullptr;
        return (true);
    } else {
        say("I can't put that here !");
        return (false);
    }
}

bool Elf::take(IConveyorBelt &conv)
{
    if (_obj) {
        say("I already have something in my hand !");
        return (false);
    }

    _obj = conv.take();
    if (_obj) {
        say("I took a " + _obj->describe());
        return (true);
    } else {
        say("There is nothing on the Conveyor belt you stupid little thing");
        return (false);
    }
}

const Object *Elf::look(const IConveyorBelt &conv) const
{
    auto obj = conv.getOnConv();

    say("Look at the conveyor belt :");
    if (obj)
        std::cout << *obj << std::endl;
    else
        std::cout << "nothing" << std::endl;
    return (obj);
}

bool Elf::in(IConveyorBelt &conv, Object::Types type) const
{
    return (conv.in(type));
}

bool Elf::out(IConveyorBelt &conv) const
{
    if (!conv.getOnConv()) {
        say(std::string("What do you want to send ??? There is nothing on the ")
                + std::string("Conveyor belt you stupid little thing"));
        return (false);
    }
    return (conv.out());
}

bool Elf::carrySomething() const
{
    return (_obj != nullptr);
}

const Object *Elf::inMyHand() const
{
    if (_obj)
        say("I'm carrying a " + _obj->describe());
    else
        say("I'm carrying nothing");
    return (_obj);
}