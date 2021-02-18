/*
** EPITECH PROJECT, 2018
** OOP_nanotekspice_2018
** File description:
** Link.cpp
*/

#include "../Errors.hpp"
#include "Link.hpp"

namespace nts {
    Link::Link(IComponent &comp, std::size_t p) : component(comp), pin(p)
    {}

    std::string tristateToString(Tristate tri)
    {
        if (tri == TRUE) {
            return (std::string("1"));
        } else if (tri == FALSE) {
            return (std::string("0"));
        } else {
            return (std::string("U"));
        }
    }

    Tristate stringToTristate(const std::string &str)
    {
        if (str == "1") {
            return (TRUE);
        } else if (str == "0") {
            return (FALSE);
        } else if (str == "U") {
            return (UNDEFINED);
        } else {
            throw nts::InputError("Invalid state", "LINK");
        }
    }
}