/*
** EPITECH PROJECT, 2018
** cpp_d16_2018
** File description:
** EventManager.cpp
*/

#include "EventManager.hpp"

EventManager::~EventManager()
{
    _list.clear();
}

EventManager::EventManager() : _time(0)
{
}

EventManager::EventManager(const EventManager &other) : _time(other._time),
    _list(other._list)
{
}

EventManager &EventManager::operator=(const EventManager &other)
{
    if (this == &other)
        return (*this);
    _list.clear();
    _time = other._time;
    _list = other._list;
    return (*this);
}

void EventManager::addEvent(const Event &e)
{
    if (e.getTime() < _time)
        _list.push_back(e);
    std::list<Event>::iterator it = _list.begin();
    while (it != _list.end() && (*it).getTime() <= e.getTime())
        it++;
    _list.insert(it, e);
}

void EventManager::removeEventsAt(unsigned int time)
{
    std::list<Event>::const_iterator it = _list.begin();
    while (it != _list.end()) {
        if ((*it).getTime() == time) {
            _list.erase(it);
            it = _list.begin();
        } else {
            it++;
        }
    }
}

void EventManager::dumpEvents() const
{
    std::list<Event>::const_iterator it = _list.begin();
    for (it = it; it != _list.end(); it++)
        std::cout << *it << std::endl;
}

void EventManager::dumpEventAt(unsigned int time) const
{
    std::list<Event>::const_iterator it = _list.begin();
    for (it = it; it != _list.end(); it++) {
        if ((*it).getTime() == time)
            std::cout << *it << std::endl;
    }
}

void EventManager::addTime(unsigned int time)
{
    std::list<Event>::const_iterator it = _list.begin();
    while (_list.size() && (*it).getTime() <= _time + time) {
        std::cout << (*it).getEvent() << std::endl;
        _list.erase(it);
        it = _list.begin();
    }
    _time += time;
}

static bool my_cmp(const Event &a, const Event &b)
{
    return (a.getTime() < b.getTime());
}

void EventManager::addEventList(std::list <Event> &events)
{
    events.sort(my_cmp);
    _list.merge(events, my_cmp);
    std::list<Event>::const_iterator it = _list.begin();
    while (_list.size() && (*it).getTime() <= _time) {
        _list.erase(it);
        it = _list.begin();
    }
}