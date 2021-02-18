/*
** EPITECH PROJECT, 2018
** cpp_rush3_2018
** File description:
** EventNcurse.hpp
*/

#ifndef CPP_RUSH3_2018_EVENTNCURSE_HPP_
# define CPP_RUSH3_2018_EVENTNCURSE_HPP_

#include <ncurses.h>
# include "../IMonitorEvent.hpp"

class EventNcurse : public IMonitorEvent {
public:
    ~EventNcurse() = default;
    EventNcurse() = default;

    bool get(IMonitorDisplay *display, IMonitorModule **modules,
        Settings &settings);

private:
    void changeModule(IMonitorModule **modules, int i, Types::Offset);
    void manageClick(MEVENT event, IMonitorModule **modules);
};

#endif /* CPP_RUSH3_2018_EVENTNCURSE_HPP_ */
