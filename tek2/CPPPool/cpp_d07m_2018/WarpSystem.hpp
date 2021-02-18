/*
** EPITECH PROJECT, 2018
** cpp_d07m_2018
** File description:
** WarpSystem.hpp
*/

#ifndef CPP_D07M_2018_WARPSYSTEM_HPP_
# define CPP_D07M_2018_WARPSYSTEM_HPP_

# include <string>

namespace WarpSystem {

    class QuantumReactor {
    public:
        // Ctor
        QuantumReactor();

        //Dtor
        ~QuantumReactor();

        // Member functions
        bool isStable();
        void setStability(bool);

    private:
        // Properties
        bool _stability;
    };

    class Core {
    public:
        // Ctor
        Core(QuantumReactor *);

        //Dtor
        ~Core();

        // Member functions
        QuantumReactor *checkReactor();

    private:
        // Properties
        QuantumReactor *_coreReactor;
    };
}

#endif /* CPP_D07M_2018_WARPSYSTEM_HPP_ */
