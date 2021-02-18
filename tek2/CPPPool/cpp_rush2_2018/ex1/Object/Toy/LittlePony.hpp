/*
** EPITECH PROJECT, 2018
** cpp_rush2_2018
** File description:
** LittlePony.hpp
*/

#ifndef CPP_RUSH2_2018_LITTLEPONY_HPP_
# define CPP_RUSH2_2018_LITTLEPONY_HPP_

# include "Toy.hpp"

class LittlePony : public Toy {
public:
    LittlePony(const std::string & = "happy pony");
    ~LittlePony();

    void say(const std::string &) const;
    std::string describe() const;

    void isTaken() const final;
};

#endif /* CPP_RUSH2_2018_LITTLEPONY_HPP_ */
