/*
** EPITECH PROJECT, 2018
** cpp_d15_2018
** File description:
** ex02.hpp
*/

#ifndef CPP_D15_2018_EX02_HPP_
# define CPP_D15_2018_EX02_HPP_

# include <iostream>

template<typename T>
T min(const T &a, const T &b)
{
    std::cout << "template min" << std::endl;
    if (b < a)
        return (b);
    return (a);
}

int min(const int &a, const int &b)
{
    std::cout << "non-template min" << std::endl;
    if (b < a)
        return (b);
    return (a);
}

template<typename T>
T templateMin(const T *tab, size_t size)
{
    T mini = tab[0];
    for (size_t i = 1; i < size; i++)
        mini = min<T>(mini, tab[i]);
    return (mini);
}

int nonTemplateMin(const int *tab, size_t size)
{
    if (size == 0)
        return (0);
    int mini = tab[0];
    for (size_t i = 1; i < size; i++)
        mini = min(mini, tab[i]);
    return (mini);
}

#endif /* CPP_D15_2018_EX02_HPP_ */
