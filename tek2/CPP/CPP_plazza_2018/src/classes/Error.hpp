/*
** EPITECH PROJECT, 2018
** CPP_plazza_2018
** File description:
** Error.hpp
*/

#ifndef CPP_PLAZZA_2018_ERROR_HPP
#define CPP_PLAZZA_2018_ERROR_HPP

#include <iostream>
#include <exception>

class PlazzaError : public std::exception {
public:
    ~PlazzaError() override = default;
    PlazzaError() = default;
    PlazzaError(const std::string &error);

    const char *what() const noexcept override;
    std::string where() const noexcept;
    virtual void printError() const;

protected:
    std::string _what;
    std::string _where;
};

std::ostream &operator<<(std::ostream &out, const PlazzaError &error);

class InputError : public PlazzaError {
    ~InputError() override = default;
    InputError(const std::string &error);
    void printError() const override;
};

class ArgumentError : public PlazzaError {
    ~ArgumentError() override = default;
    ArgumentError(const std::string &error);
    void printError() const override;
};

class FormatError : public PlazzaError {
    ~FormatError() override = default;
    FormatError(const std::string &error);
    void printError() const override;
};

class RunTimeError : public PlazzaError {
    ~RunTimeError() override = default;
    RunTimeError(const std::string &error);
    void printError() const override;
};

class TimeOutError : public PlazzaError {
    ~TimeOutError() override = default;
    TimeOutError(const std::string &error);
    void printError() const override;
};

class CommunicationError : public PlazzaError {
    ~CommunicationError() override = default;
    CommunicationError(const std::string &error);
    void printError() const override;
};

#endif /* CPP_PLAZZA_2018_ERROR_HPP */
