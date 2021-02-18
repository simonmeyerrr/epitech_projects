/*
** EPITECH PROJECT, 2018
** cpp_d14a_2018
** File description:
** Error.cpp
*/

#include "Errors.hpp"

NasaError::NasaError(std::string const &message, std::string const &component)
    : _message(message), _component(component)
{}

const char *NasaError::what() const noexcept
{
    return (_message.c_str());
}

std::string const &NasaError::getComponent() const
{
    return (_component);
}

MissionCriticalError::MissionCriticalError(std::string const &message,
    std::string const &component) : NasaError(message, component)
{}

LifeCriticalError::LifeCriticalError(std::string const &message,
    std::string const &component) : NasaError(message, component)
{}

UserError::UserError(std::string const &message, std::string const &component)
    : NasaError(message, component)
{}

CommunicationError::CommunicationError(std::string const &message)
    : NasaError(message, "CommunicationDevice")
{}