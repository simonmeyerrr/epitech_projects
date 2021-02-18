    /*
** EPITECH PROJECT, 2018
** bootstrap_plazza
** File description:
** Thread.hpp
*/

#ifndef BOOTSTRAP_PLAZZA_THREAD_HPP
#define BOOTSTRAP_PLAZZA_THREAD_HPP

class Thread {

public:
    ~Thread();
    Thread(void *(*start_routine) (void *), void *arg);

    void join();
private:
    bool _join;
    pthread_t _thre;
};

#endif /* BOOTSTRAP_PLAZZA_THREAD_HPP */
