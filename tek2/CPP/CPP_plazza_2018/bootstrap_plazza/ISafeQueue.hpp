/*
** EPITECH PROJECT, 2018
** bootstrap_plazza
** File description:
** ISafeQueue.hpp
*/

#ifndef BOOTSTRAP_PLAZZA_ISAFEQUEUE_HPP
#define BOOTSTRAP_PLAZZA_ISAFEQUEUE_HPP

class  ISafeQueue {
public:
    virtual ~ISafeQueue () = default;
    virtual  void  push(int  value) = 0;
    virtual  bool  tryPop(int &value) = 0;
};


#endif /* BOOTSTRAP_PLAZZA_ISAFEQUEUE_HPP */
