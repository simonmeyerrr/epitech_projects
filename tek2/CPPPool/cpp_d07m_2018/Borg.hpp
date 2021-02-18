/*
** EPITECH PROJECT, 2018
** cpp_d07m_2018
** File description:
** Borg.hpp
*/

#ifndef CPP_D07M_2018_BORG_HPP_
# define CPP_D07M_2018_BORG_HPP_

# include <string>
# include "Destination.hpp"
# include "WarpSystem.hpp"

namespace Borg
{

    class Ship {
    public:
        // Ctor
        Ship();

        //Dtor
        ~Ship();

        // Member functions
        void setupCore(WarpSystem::Core *);
        void checkCore();
        bool move(int, Destination);
        bool move(int);
        bool move(Destination);
        bool move();

        private:
        // Properties
        int _side;
        short _maxWarp;
        WarpSystem::Core *_core;
        Destination _location;
        Destination _home;
    };

}

#endif /* CPP_D07M_2018_BORG_HPP_ */
