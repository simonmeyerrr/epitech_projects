/*
** EPITECH PROJECT, 2018
** bootstrap_plazza
** File description:
** IMutex.hpp
*/

#ifndef BOOTSTRAP_PLAZZA_IMUTEX_HPP
#define BOOTSTRAP_PLAZZA_IMUTEX_HPP

class  Imutex {
public:
    virtual ~Imutex () = default;
    virtual  void  lock() = 0;
    virtual  void  unlock () = 0;
    virtual  void  trylock () = 0;
};

#endif //BOOTSTRAP_PLAZZA_IMUTEX_HPP
