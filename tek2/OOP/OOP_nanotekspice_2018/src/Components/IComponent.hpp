/*
** EPITECH PROJECT, 2018
** OOP_nanotekspice_2018
** File description:
** IComponent.hpp
*/

#ifndef OOP_NANOTEKSPICE_2018_ICOMPONENT_HPP_
# define OOP_NANOTEKSPICE_2018_ICOMPONENT_HPP_

#include <string>

namespace nts {
    enum Tristate {
        UNDEFINED = (-true),
        TRUE = true,
        FALSE = false
    };

    enum PinType {
        IN,
        OUT,
        NONE
    };

    enum ComponentType {
        INPUT,
        BOOL,
        CLOCK,
        OUTPUT,
        OTHER
    };

    class IComponent {
    public:
        virtual ~IComponent() = default;

        virtual Tristate compute(std::size_t = 1) = 0;
        virtual void setLink(std::size_t, IComponent &, std::size_t) = 0;
        virtual void dump() const = 0;

        virtual ComponentType getType() const = 0;
        virtual void updateState(Tristate) = 0;
        virtual std::string getName() const = 0;
        virtual PinType getPinType(std::size_t) const = 0;
    };
}

#endif /* OOP_NANOTEKSPICE_2018_ICOMPONENT_HPP_ */
