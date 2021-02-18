/*
** EPITECH PROJECT, 2018
** cpp_d15_2018
** File description:
** ex04.cpp
*/

#include <string>
#include "ex04.hpp"

template<>
bool equal<int>(const int &a, const int &b)
{
    return (a == b);
}

template<>
bool equal<float>(const float &a, const float &b)
{
    return (a == b);
}

template<>
bool equal<double>(const double &a, const double &b)
{
    return (a == b);
}

template<>
bool equal<std::string>(const std::string &a, const std::string &b)
{
    return (a == b);
}

template<>
bool Tester<int>::equal(const int &a, const int &b)
{
    return (a == b);
}

template<>
bool Tester<float>::equal(const float &a, const float &b)
{
    return (a == b);
}

template<>
bool Tester<double>::equal(const double &a, const double &b)
{
    return (a == b);
}

template<>
bool Tester<std::string>::equal(const std::string &a, const std::string &b)
{
    return (a == b);
}