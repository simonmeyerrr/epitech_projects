/*
** EPITECH PROJECT, 2018
** cpp_d13_2018
** File description:
** ToyStory.hpp
*/

#ifndef CPP_D13_2018_TOYSTORY_HPP_
# define CPP_D13_2018_TOYSTORY_HPP_

#include <string>
#include "Toy.hpp"

class ToyStory {
public:
    ToyStory();
    ~ToyStory();

    static void tellMeAStory(const std::string &file,
        Toy &toy1, bool(Toy::*func1)(const std::string &),
        Toy &toy2, bool (Toy::*func2)(const std::string &));

    static int continueStory(int i, const std::string &line, Toy &toy, bool
        (Toy::*func)(const std::string &));

private:
};

#endif /* CPP_D13_2018_TOYSTORY_HPP_ */
