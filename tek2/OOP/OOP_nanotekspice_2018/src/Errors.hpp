/*
** EPITECH PROJECT, 2018
** OOP_nanotekspice_2018
** File description:
** Errors.hpp
*/

#ifndef OOP_NANOTEKSPICE_2018_ERRORS_HPP_
# define OOP_NANOTEKSPICE_2018_ERRORS_HPP_

# include <exception>
# include <string>

namespace nts {

    class Errors : public std::exception {
    public:
        Errors() = default;
        ~Errors() override = default;

        const char *what() const noexcept override;
        std::string where() const noexcept;
        void dump() const noexcept;

    protected:
        std::string _what;
        std::string _where;
    };

    class PinError : public Errors {
    public:
        ~PinError() override = default;
        PinError(const std::string &what, const std::string &where) noexcept;
        PinError(const PinError &other) noexcept;
    };

    class FactoryError : public Errors {
    public:
        ~FactoryError() override = default;
        FactoryError(const std::string &what,
            const std::string &where) noexcept;
        FactoryError(const FactoryError &other) noexcept;
    };

    class InputError : public Errors {
    public:
        ~InputError() override = default;
        InputError(const std::string &what, const std::string &where) noexcept;
        InputError(const InputError &other) noexcept;
    };
}

#endif /* OOP_NANOTEKSPICE_2018_ERRORS_HPP_ */
