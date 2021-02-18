/*
** EPITECH PROJECT, 2018
** cpp_rush3_2018
** File description:
** IMonitorEvent.hpp
*/

#ifndef CPP_RUSH3_2018_IMONITOREVENT_HPP_
# define CPP_RUSH3_2018_IMONITOREVENT_HPP_

# include "../MonitorModule/IMonitorModule.hpp"
# include "../MonitorDisplay/IMonitorDisplay.hpp"

class IMonitorEvent {
public:
    virtual ~IMonitorEvent() = default;

    virtual bool get(IMonitorDisplay *, IMonitorModule **, Settings &) = 0;
};

IMonitorEvent *createMonitorEvent(Types::DisplayMode mode);

#endif /* CPP_RUSH3_2018_IMONITOREVENT_HPP_ */
