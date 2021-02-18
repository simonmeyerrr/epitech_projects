/*
** EPITECH PROJECT, 2018
** cpp_rush3_2018
** File description:
** MonitorSfml.hpp
*/

#ifndef CPP_RUSH3_2018_MONITORSFML_HPP_
# define CPP_RUSH3_2018_MONITORSFML_HPP_

#include "../IMonitorEvent.hpp"

class EventSfml : public IMonitorEvent {
public:
    ~EventSfml() override = default;
    EventSfml() = default;

    bool get(IMonitorDisplay *, IMonitorModule **, Settings &) override;

private:
    bool manageKey(sf::Event &, sf::RenderWindow *, Settings &,
        IMonitorModule **);

    bool manageMouse(sf::Event &, Settings &, IMonitorModule **);

    void changeModule(IMonitorModule **, int, Types::Offset);
};

#endif /* CPP_RUSH3_2018_MONITORSFML_HPP_ */
