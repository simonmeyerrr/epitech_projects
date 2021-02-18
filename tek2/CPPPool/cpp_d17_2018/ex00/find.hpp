/*
** EPITECH PROJECT, 2018
** cpp_d17_2018
** File description:
** find.hpp
*/

#ifndef CPP_D17_2018_FIND_HPP_
# define CPP_D17_2018_FIND_HPP_

# include <algorithm>

template<typename T>
auto do_find(T &a, int b)
{
    return (std::find(a.begin(), a.end(), b));
}

#endif /* CPP_D17_2018_FIND_HPP_ */
