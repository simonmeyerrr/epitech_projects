/*
** EPITECH PROJECT, 2018
** cpp_d15_2018
** File description:
** ex03.hpp
*/

#ifndef CPP_D15_2018_EX03_HPP_
# define CPP_D15_2018_EX03_HPP_

# include <string>
# include <iostream>

template<typename T>
void foreach(const T *tab, void func(const T &), size_t size)
{
    for (size_t i = 0; i < size; i++)
        func(tab[i]);
}

template<typename T>
void print(const T &elem)
{
    std::cout << elem << std::endl;
}

#endif /* CPP_D15_2018_EX03_HPP_ */
