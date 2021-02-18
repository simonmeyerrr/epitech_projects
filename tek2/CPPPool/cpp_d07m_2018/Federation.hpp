/*
** EPITECH PROJECT, 2018
** cpp_d07m_2018
** File description:
** Federation.hpp
*/

#ifndef CPP_D07M_2018_FEDERATION_HPP_
# define CPP_D07M_2018_FEDERATION_HPP_

# include <string>
# include "WarpSystem.hpp"
# include "Destination.hpp"

namespace Federation
{
    namespace Starfleet {

        class Ensign {
        public:
            // Ctor
            Ensign(std::string);

            //Dtor
            ~Ensign();

            // Member functions

        private:
            // Properties
            std::string _name;
        };

        class Captain {
        public:
            // Ctor
            Captain(std::string);

            //Dtor
            ~Captain();

            // Member functions
            std::string getName();
            int getAge();
            void setAge(int);

        private:
            // Properties
            std::string _name;
            int _age;
        };

        class Ship {
        public:
            // Ctor
            Ship(int, int, std::string, short);

            //Dtor
            ~Ship();

            // Member functions
            void setupCore(WarpSystem::Core *);
            void checkCore();
            void promote(Captain *);
            bool move(int, Destination);
            bool move(int);
            bool move(Destination);
            bool move();
            int getShield();
            void setShield(int);
            int getTorpedo();
            void setTorpedo(int);

        private:
            // Properties
            int _length;
            int _width;
            std::string _name;
            short _maxWarp;
            WarpSystem::Core *_core;
            Captain *_captain;
            Destination _location;
            Destination _home;
            int _shield;
            int _photonTorpedo;
        };

    }

    class Ship {
    public:
        // Ctor
        Ship(int, int, std::string);

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
        int _length;
        int _width;
        std::string _name;
        short _maxWarp;
        WarpSystem::Core *_core;
        Destination _location;
        Destination _home;
    };
}

#endif /* CPP_D07M_2018_FEDERATION_HPP_ */
