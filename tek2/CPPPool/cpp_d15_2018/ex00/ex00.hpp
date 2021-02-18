/*
** EPITECH PROJECT, 2018
** cpp_d15_2018
** File description:
** ex00.hpp
*/

#ifndef CPP_D15_2018_EX00_HPP_
# define CPP_D15_2018_EX00_HPP_

template<typename T>
void swap(T &a, T &b)
{
    T tmp = a;
    a = b;
    b = tmp;
}

template<typename T>
T min(T a, T b)
{
    if (a < b)
        return (a);
    return (b);
}

template<typename T>
T max(T a, T b)
{
    if (a > b)
        return (a);
    return (b);
}

template<typename T>
T add(T a, T b)
{
    return (a + b);
}

#endif /* CPP_D15_2018_EX00_HPP_ */
