/*
** EPITECH PROJECT, 2018
** cpp_d16_2018
** File description:
** EventManager.hpp
*/

#ifndef CPP_D16_2018_EVENTMANAGER_HPP_
# define CPP_D16_2018_EVENTMANAGER_HPP_

# include <iostream>
# include <string>
# include <list>
# include "Event.hpp"

class EventManager {
public:
    ~EventManager();
    EventManager();
    EventManager(const EventManager &);
    EventManager &operator=(const EventManager &);

    void addEvent(const Event &e);
    void removeEventsAt(unsigned int time);
    void dumpEvents() const;
    void dumpEventAt(unsigned int time) const;
    void addTime(unsigned int time);
    void addEventList(std::list <Event> &events);

private:
    unsigned int _time;
    std::list <Event> _list;
};

#endif /* CPP_D16_2018_EVENTMANAGER_HPP_ */
