/*
** EPITECH PROJECT, 2018
** cpp_d06_2018
** File description:
** KoalaNurseList.cpp
*/

#include <iostream>
#include <string>
#include "KoalaNurseList.hpp"
#include "KoalaNurse.hpp"

KoalaNurseList::KoalaNurseList(KoalaNurse *koala)
    : _prev(NULL), _next(NULL), _content(koala)
{}

KoalaNurseList::~KoalaNurseList()
{}

bool KoalaNurseList::isBegin()
{
    return (this->_prev ? false : true);
}

bool KoalaNurseList::isEnd()
{
    return (this->_next ? false : true);
}

KoalaNurseList *KoalaNurseList::getPrev()
{
    return (this->_prev);
}

KoalaNurseList *KoalaNurseList::getNext()
{
    return (this->_next);
}

KoalaNurseList *KoalaNurseList::getBegin()
{
    auto *tmp = this;

    while (!tmp->isBegin())
        tmp = tmp->getPrev();
    return (tmp);
}

KoalaNurseList *KoalaNurseList::getEnd()
{
    auto *tmp = this;

    while (!tmp->isEnd())
        tmp = tmp->getNext();
    return (tmp);
}

void KoalaNurseList::append(KoalaNurseList *node)
{
    auto *tmp = this->getEnd();
    tmp->_next = node;

    if (node) {
        node->_prev = tmp;
        node->_next = NULL;
    }
}

KoalaNurseList *KoalaNurseList::remove(KoalaNurseList *node)
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

KoalaNurse *KoalaNurseList::getFromID(int id)
{
    auto *tmp = this->getBegin();

    while (!tmp->isEnd() && (!tmp->_content || tmp->_content->getID() != id))
        tmp = tmp->getNext();
    if (tmp->_content && tmp->_content->getID() == id)
        return (tmp->_content);
    return (NULL);
}

KoalaNurseList *KoalaNurseList::removeFromID(int id)
{
    auto *tmp = this->getBegin();

    while (!tmp->isEnd() &&
        (!tmp->_content || tmp->_content->getID() != id))
        tmp = tmp->getNext();
    if (tmp->_content && tmp->_content->getID() == id)
        return (this->remove(tmp));
    return (this->getBegin());
}

KoalaNurse *KoalaNurseList::getContent()
{
    return (this->_content);
}

void KoalaNurseList::dump()
{
    auto *tmp = this->getBegin();

    while (!tmp->isEnd()) {
        if (tmp->_content)
            std::cout << tmp->_content->getID() << ", ";
        tmp = tmp->getNext();
    }
    if (tmp->_content)
        std::cout << tmp->_content->getID() << "." << std::endl;
}
