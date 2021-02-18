/*
** EPITECH PROJECT, 2018
** cpp_d15_2018
** File description:
** ex04.hpp
*/

#ifndef CPP_D15_2018_EX04_HPP_
# define CPP_D15_2018_EX04_HPP_

#include <string>

template<typename T>
bool equal(const T &a, const T &b);

template<typename T>
class Tester {
public:
    Tester() = default;
    ~Tester() = default;

    bool equal(const T &a, const T &b);
};

#endif /* CPP_D15_2018_EX04_HPP_ */
