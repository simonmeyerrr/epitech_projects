/*
** EPITECH PROJECT, 2018
** cpp_d16_2018
** File description:
** DomesticKoala.cpp
*/

#include "DomesticKoala.hpp"

DomesticKoala::~DomesticKoala()
{}

DomesticKoala::DomesticKoala(KoalaAction &action)
    : _action(action)
{}

DomesticKoala::DomesticKoala(const DomesticKoala &other)
    : _action(other._action), _methods(other._methods),
    _commands(other._commands)
{}

DomesticKoala &DomesticKoala::operator=(const DomesticKoala &other)
{
    _methods = other._methods;
    _commands = other._commands;
    return (*this);
}

const std::vector <methodPointer_t> *DomesticKoala::getActions() const
{
    return (&_methods);
}

void DomesticKoala::learnAction(unsigned char command, methodPointer_t action)
{
    std::vector<unsigned char>::iterator it = _commands.begin();
    while (it != _commands.end()) {
        if (*it == command)
            return;
        it++;
    }
    _methods.push_back(action);
    _commands.push_back(command);
}

void DomesticKoala::unlearnAction(unsigned char command)
{
    std::vector<unsigned char>::iterator it = _commands.begin();
    std::vector<methodPointer_t>::iterator itt = _methods.begin();
    while (it != _commands.end()) {
        if (*it == command) {
            _commands.erase(it);
            _methods.erase(itt);
            return;
        }
        it++;
        itt++;
    }
}

void DomesticKoala::doAction(unsigned char command, const std::string &param)
{
    std::vector<unsigned char>::iterator it = _commands.begin();
    std::vector<methodPointer_t>::iterator itt = _methods.begin();
    while (it != _commands.end()) {
        if (*it == command) {
            (_action.**itt)(param);
            return;
        }
        it++;
        itt++;
    }
}

void DomesticKoala::setKoalaAction(KoalaAction &action)
{
    _action = action;
}