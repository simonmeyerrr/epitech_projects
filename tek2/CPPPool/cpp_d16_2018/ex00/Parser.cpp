/*
** EPITECH PROJECT, 2018
** cpp_d16_2018
** File description:
** Parser.cpp
*/

#include <iostream>
#include "Parser.hpp"

Parser::~Parser()
{
}

Parser::Parser() :  _first(nullptr), _second(nullptr), _result(0)
{
}

int Parser::calcul(int a, int b, char op)
{
    if (op == '+')
        return (a + b);
    if (op == '-')
        return (a - b);
    if (op == '*')
        return (a * b);
    if (op == '/')
        return (a / b);
    if (op == '%')
        return (a % b);
    return (a);
}

void Parser::addNumber(int nb)
{
    auto elem = new Elem(nb, 0);
    elem->next = _first;
    _first = elem;
}

int  Parser::getlevel(char op)
{
    if (op == '+' || op == '-')
        return (2);
    if (op == '*' || op == '/' || op == '%')
        return (3);
    return (0);
}

void Parser::addOp(char op)
{
    if (!_second) {
        _second = new Elem(0, op);
        return;
    }
    if (_second && _second->op != '(' && op != ')' && op != '(') {
        int level1 = getlevel(_second->op);
        int level2 = getlevel(op);
        if (level2 == 2 &&  level1 == 3) {
            while (_second && _second->op != '(')
                destack();
            auto elem = new Elem(0, op);
            elem->next = _second;
            _second = elem;
        } else if (level1 == 2 && level2 == 1) {
            destack();
            auto elem = new Elem(0, op);
            elem->next = _second;
            _second = elem;
        } else if (level2 == 3 && level1 == 2) {
            auto elem = new Elem(0, op);
            elem->next = _second;
            _second = elem;
        } else {
            destack();
            auto elem = new Elem(0, op);
            elem->next = _second;
            _second = elem;
        }
    } else if (op == ')') {
        while (_second && _second->op != '(')
            destack();
        if (_second && _second->op == '(') {
            auto tmp = _second;
            _second = _second->next;
            delete tmp;
        }
    } else {
        auto elem = new Elem(0, op);
        elem->next = _second;
        _second = elem;
    }
}

void Parser::destack()
{
    auto tmp = _second->next;

    _second->next = _first;
    _first = _second;
    _second = tmp;
}

void Parser::solveNPI()
{
    Elem *one = _first;
    Elem *two = one->next;
    Elem *three = two->next;
    while (one && two && three && (!one->op || two->op || three->op)) {
        one = two;
        two = three;
        three = three->next;
    }
    if (one && two && three) {
        one->nb = calcul(three->nb, two->nb, one->op);
        one->op = 0;
        one->next = three->next;
        delete two;
        delete three;
    }
}

void Parser::feed(const std::string &expression)
{
    const char *str = expression.c_str();
    int nb = 0;
    for (int i = 0; str && str[i]; i++) {
        if (str[i] >= '0' && str[i] <= '9') {
            nb = (nb * 10) + str[i] - '0';
        } else if (str[i] == '+' || str[i] == '-' || str[i] == '*' ||
            str[i] == '/' || str[i] == '%' || str[i] == '('  || str[i] == ')') {
            if (nb) {
                addNumber(nb);
                nb = 0;
            }
            addOp(str[i]);
        } else {
            if (nb) {
                addNumber(nb);
                nb = 0;
            }
        }
    }
    if (nb)
        addNumber(nb);
    while (_second)
        destack();
    while (_first && _first->next && _first->next->next)
        solveNPI();
    int res = 0;
    if (_first) {
        res = _first->nb;
        delete _first;
    }
    _first = nullptr;
    _second = nullptr;
    _result += res;
}

int Parser::result() const
{
    return (_result);
}

void Parser::reset()
{
    _result = 0;
}