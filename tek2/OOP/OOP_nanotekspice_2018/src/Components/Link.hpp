/*
** EPITECH PROJECT, 2018
** OOP_nanotekspice_2018
** File description:
** Link.hpp
*/

#ifndef OOP_NANOTEKSPICE_2018_LINK_HPP_
# define OOP_NANOTEKSPICE_2018_LINK_HPP_

#include "IComponent.hpp"

namespace nts {

    class Link {
    public:
        ~Link() = default;
        Link(IComponent &comp, std::size_t p);

        IComponent &component;
        std::size_t pin;
    };

    std::string tristateToString(Tristate);
    Tristate stringToTristate(const std::string &str);

}

#endif /* OOP_NANOTEKSPICE_2018_LINK_HPP_ */
