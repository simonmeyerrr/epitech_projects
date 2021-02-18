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
        return (tmp);
    return (this->_prev);
}

KoalaDoctorList *KoalaDoctorList::getNext()
{
    auto *tmp = this;

    if (!tmp)
        return (tmp);
    return (this->_next);
}

KoalaDoctorList *KoalaDoctorList::getBegin()
{
    auto *tmp = this;

    while (!tmp->isBegin())
        tmp = tmp->getPrev();
    return (tmp);
}

KoalaDoctorList *KoalaDoctorList::getEnd()
{
    auto *tmp = this;

    while (!tmp->isEnd())
        tmp = tmp->getNext();
    return (tmp);
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

void KoalaDoctorList::append(KoalaDoctorList *node)
{
    if (this->contain(node))
        return;

    auto *tmp = this->getEnd();
    if (tmp)
        tmp->_next = node;
    if (node) {
        node->_prev = tmp;
        node->_next = NULL;
    }
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
        (!tmp->getContent() || tmp->getContent()->getName() != name))
        tmp = tmp->getNext();
    if (tmp->getContent() && tmp->getContent()->getName() == name)
        return (tmp->getContent());
    return (NULL);
}

KoalaDoctorList *KoalaDoctorList::removeFromName(std::string name)
{
    auto *tmp = this->getBegin();

    while (!tmp->isEnd() &&
        (!tmp->getContent() || tmp->getContent()->getName() != name))
        tmp = tmp->getNext();
    if (tmp->_content && tmp->getContent()->getName() == name)
        return (this->remove(tmp));
    return (this->getBegin());
}

KoalaDoctor *KoalaDoctorList::getContent()
{
    return (this->_content);
}

void KoalaDoctorList::dump()
{
    auto *tmp = this->getBegin();

    while (!tmp->isEnd()) {
        if (tmp->getContent())
            std::cout << tmp->_content->getName() << ", ";
        else
            std::cout << "[NULL]" << ", ";
        tmp = tmp->getNext();
    }
    if (tmp->getContent())
        std::cout << tmp->_content->getName() << "." << std::endl;
    else
        std::cout << "[NULL]" << "." << std::endl;
}