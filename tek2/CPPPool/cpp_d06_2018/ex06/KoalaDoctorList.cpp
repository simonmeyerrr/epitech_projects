/*
** EPITECH PROJECT, 2018
** cpp_d06_2018
** File description:
** KoalaDoctorList.cpp
*/

#include <iostream>
#include <string>
#include "KoalaDoctorList.hpp"
#include "KoalaDoctor.hpp"

KoalaDoctorList::KoalaDoctorList(KoalaDoctor *koala)
    : _prev(NULL), _next(NULL), _content(koala)
{}

KoalaDoctorList::~KoalaDoctorList()
{}

bool KoalaDoctorList::isBegin()
{
    auto *tmp = this;

    if (!tmp)
        return (true);
    return (!this->_prev);
}

bool KoalaDoctorList::isEnd()
{
    auto *tmp = this;

    if (!tmp)
        return (true);
    return (!this->_next);
}

KoalaDoctorList *KoalaDoctorList::getPrev()
{
    auto *tmp = this;

    if (!tmp)
        return (NULL);
    return (this->_prev);
}

KoalaDoctorList *KoalaDoctorList::getNext()
{
    auto *tmp = this;

    if (!tmp)
        return (NULL);
    return (this->_next);
}

KoalaDoctorList *KoalaDoctorList::getBegin()
{
    auto *tmp = this;

    while (tmp && !tmp->isBegin())
        tmp = tmp->getPrev();
    return (tmp);
}

KoalaDoctorList *KoalaDoctorList::getEnd()
{
    auto *tmp = this;

    while (tmp && !tmp->isEnd())
        tmp = tmp->getNext();
    return (tmp);
}

void KoalaDoctorList::append(KoalaDoctorList *node)
{
    auto *tmp = this->getEnd();

    if (!node)
        return;
    node->_prev = tmp;
    node->_next = NULL;
    if (tmp)
        tmp->_next = node;
}

KoalaDoctorList *KoalaDoctorList::remove(KoalaDoctorList *node)
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

KoalaDoctor *KoalaDoctorList::getFromName(std::string name)
{
    auto *tmp = this->getBegin();

    while (!tmp->isEnd() &&
        (!tmp->_content || tmp->_content->getName() != name))
        tmp = tmp->getNext();
    if (tmp->_content && tmp->_content->getName() == name)
        return (tmp->_content);
    return (NULL);
}

KoalaDoctorList *KoalaDoctorList::removeFromName(std::string name)
{
    auto *tmp = this->getBegin();

    while (!tmp->isEnd() &&
        (!tmp->_content || tmp->_content->getName() != name))
        tmp = tmp->getNext();
    if (tmp->_content && tmp->_content->getName() == name)
        return (this->remove(tmp));
    return (this->getBegin());
}

bool KoalaDoctorList::contain(KoalaDoctorList *node)
{
    auto *tmp = this->getBegin();

    while (tmp) {
        if (tmp == node)
            return (true);
        tmp = tmp->getNext();
    }
    return (false);
}

KoalaDoctor *KoalaDoctorList::getContent()
{
    return (this->_content);
}

void KoalaDoctorList::dump()
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