/*
** EPITECH PROJECT, 2018
** CPP_plazza_2018
** File description:
** Error.cpp
*/

#include "Error.hpp"

PlazzaError::PlazzaError(const std::string &error)
    : _what(error)
{
}

const char *PlazzaError::what() const noexcept
{
    return (_what.c_str());
}

std::string PlazzaError::where() const noexcept
{
    return (_where);
}

void PlazzaError::printError() const
{
    std::cerr << where() << " : " << std::string(what()) << std::endl;
}

std::ostream &operator<<(std::ostream &out, const PlazzaError &error)
{
    out << error.where() << " : " << std::string(error.what()) << std::endl;
    return (out);
}

InputError::InputError(const std::string &error)
    : PlazzaError(error)
{
}

void InputError::printError() const
{
    std::cerr << "Bad Input : " << std::string(what()) << std::endl;
}

ArgumentError::ArgumentError(const std::string &error)
    : PlazzaError(error)
{
}

void ArgumentError::printError() const
{
    std::cerr << "Bad Argument : " << std::string(what()) << std::endl;
}

FormatError::FormatError(const std::string &error)
    : PlazzaError(error)
{
}

void FormatError::printError() const
{
    std::cerr << "Bad Format : " << std::string(what()) << std::endl;
}

RunTimeError::RunTimeError(const std::string &error)
    : PlazzaError(error)
{
}

void RunTimeError::printError() const
{
    std::cerr << "Run Time Error : " << std::string(what()) << std::endl;
}

TimeOutError::TimeOutError(const std::string &error)
    : PlazzaError(error)
{
}

void TimeOutError::printError() const
{
    std::cerr << "Time Out Error : " << std::string(what()) << std::endl;
}

CommunicationError::CommunicationError(const std::string &error)
    : PlazzaError(error)
{
}

void CommunicationError::printError() const
{
    std::cerr << "Communication failed : " << std::string(what()) << std::endl;
}
