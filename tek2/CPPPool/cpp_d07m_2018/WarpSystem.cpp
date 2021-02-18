/*
** EPITECH PROJECT, 2018
** cpp_d07m_2018
** File description:
** WarpSystem.cpp
*/

#include <string>
#include "WarpSystem.hpp"

namespace WarpSystem {

    QuantumReactor::QuantumReactor()
        : _stability(true)
    {}

    QuantumReactor::~QuantumReactor()
    {}

    bool QuantumReactor::isStable()
    {
        return (this->_stability);
    }

    void QuantumReactor::setStability(bool stability)
    {
        this->_stability = stability;
    }

    Core::Core(QuantumReactor *reactor)
        : _coreReactor(reactor)
    {}

    Core::~Core()
    {}

    QuantumReactor *Core::checkReactor()
    {
        return (this->_coreReactor);
    }
}