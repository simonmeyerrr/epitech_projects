/*
** EPITECH PROJECT, 2018
** cpp_d15_2018
** File description:
** ex01.hpp
*/

#ifndef CPP_D15_2018_EX01_HPP_
# define CPP_D15_2018_EX01_HPP_

#include <string>

template <typename T>
int compare(const T &a, const T &b)
{
    if (a < b)
        return (-1);
    if (a > b)
        return (1);
    return (0);
}

template<>
int compare<const char *>(const char * const &a, const char * const &b)
{
    if (!a || !b)
        return (0);
    int i = 0;
    while (a[i] && b[i] && a[i] == b[i])
        i++;
    if (a[i] < b[i])
        return (-1);
    if (a[i] > b[i])
        return (1);
    return (0);
}

#endif /* CPP_D15_2018_EX01_HPP_ */
