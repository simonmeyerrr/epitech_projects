/*
** EPITECH PROJECT, 2018
** cpp_d06_2018
** File description:
** SickKoalaList.cpp
*/

#include <iostream>
#include <string>
#include "SickKoalaList.hpp"
#include "SickKoala.hpp"

SickKoalaList::SickKoalaList(SickKoala *koala)
    : _prev(NULL), _next(NULL), _content(koala)
{}

SickKoalaList::~SickKoalaList()
{}

bool SickKoalaList::isBegin()
{
    return (this->_prev ? false : true);
}

bool SickKoalaList::isEnd()
{
    return (this->_next ? false : true);
}

SickKoalaList *SickKoalaList::getPrev()
{
    return (this->_prev);
}

SickKoalaList *SickKoalaList::getNext()
{
    return (this->_next);
}

SickKoalaList *SickKoalaList::getBegin()
{
    auto *tmp = this;

    while (!tmp->isBegin())
        tmp = tmp->getPrev();
    return (tmp);
}

SickKoalaList *SickKoalaList::getEnd()
{
    auto *tmp = this;

    while (!tmp->isEnd())
        tmp = tmp->getNext();
    return (tmp);
}

void SickKoalaList::append(SickKoalaList *node)
{
    auto *tmp = this->getEnd();
    tmp->_next = node;

    if (node) {
        node->_prev = tmp;
        node->_next = NULL;
    }
}

SickKoalaList *SickKoalaList::remove(SickKoalaList *node)
{
    auto *tmp = this->getBegin();

    while (tmp && tmp != node)
        tmp = tmp->getNext();
    if (!tmp)
        return (this->getBegin());
    if (tmp->_next)
        tmp->_next->_prev = tmp->_prev;
    if (tmp->_prev)
        tmp->_prev->_next = tmp->_next;
    auto *tmp2 = tmp;
    if (tmp->_prev)
        tmp = tmp->_prev;
    else
        tmp = tmp->_next;
    tmp2->_next = NULL;
    tmp2->_prev = NULL;
    return (tmp->getBegin());
}

SickKoala *SickKoalaList::getFromName(std::string name)
{
    auto *tmp = this->getBegin();

    while (!tmp->isEnd() &&
        (!tmp->_content || tmp->_content->getName() != name))
        tmp = tmp->getNext();
    if (tmp->_content && tmp->_content->getName() == name)
        return (tmp->_content);
    return (NULL);
}

SickKoalaList *SickKoalaList::removeFromName(std::string name)
{
    auto *tmp = this->getBegin();

    while (!tmp->isEnd() &&
        (!tmp->_content || tmp->_content->getName() != name))
        tmp = tmp->getNext();
    if (tmp->_content && tmp->_content->getName() == name)
        return (this->remove(tmp));
    return (this->getBegin());
}

SickKoala *SickKoalaList::getContent()
{
    return (this->_content);
}

void SickKoalaList::dump()
{
    auto *tmp = this->getBegin();

    while (!tmp->isEnd()) {
        if (tmp->_content)
            std::cout << tmp->_content->getName() << ", ";
        tmp = tmp->getNext();
    }
    if (tmp->_content)
        std::cout << tmp->_content->getName() << "." << std::endl;
}
