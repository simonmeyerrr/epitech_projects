/*
** EPITECH PROJECT, 2018
** OOP_nanotekspice_2018
** File description:
** Errors.cpp
*/

#include <iostream>
#include "Errors.hpp"

namespace nts {

    const char *Errors::what() const noexcept
    {
        return (_what.c_str());
    }

    std::string Errors::where() const noexcept
    {
        return (_where);
    }

    void Errors::dump() const noexcept
    {
        std::cerr << where() << " : " << std::string(what()) << std::endl;
    }

    PinError::PinError(const PinError &other) noexcept
    {
        _what = other._what;
        _where = other._where;
    }

    PinError::PinError(const std::string &what,
        const std::string &where) noexcept
    {
        _what = what;
        _where = where;
    }

    FactoryError::FactoryError(const FactoryError &other) noexcept
    {
        _what = other._what;
        _where = other._where;
    }

    FactoryError::FactoryError(const std::string &what,
        const std::string &where) noexcept
    {
        _what = what;
        _where = where;
    }

    InputError::InputError(const InputError &other) noexcept
    {
        _what = other._what;
        _where = other._where;
    }

    InputError::InputError(const std::string &what,
        const std::string &where) noexcept
    {
        _what = what;
        _where = where;
    }
}