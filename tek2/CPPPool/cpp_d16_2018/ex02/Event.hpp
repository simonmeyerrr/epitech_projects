/*
** EPITECH PROJECT, 2018
** cpp_d16_2018
** File description:
** Event.hpp
*/

#ifndef CPP_D16_2018_EVENT_HPP_
# define CPP_D16_2018_EVENT_HPP_

# include <iostream>
# include <string>

class Event {
public:
    ~Event();
    Event();
    Event(unsigned int time , const std:: string &event);
    Event(const Event &);
    Event &operator=(const Event &);

    unsigned int getTime() const;
    const std::string &getEvent() const;
    void setTime(unsigned int time);
    void setEvent(const std::string &event);

private:
    unsigned int _time;
    std::string _event;
};

std::ostream &operator<<(std::ostream &, const Event &);

#endif /* CPP_D16_2018_EVENT_HPP_ */
