/*
** EPITECH PROJECT, 2018
** OOP_nanotekspice_2018
** File description:
** Clock.hpp
*/

#ifndef OOP_NANOTEKSPICE_2018_CLOCK_HPP_
# define OOP_NANOTEKSPICE_2018_CLOCK_HPP_

# include <string>
# include "IComponent.hpp"

namespace nts {

    class Clock : public IComponent {
    public:
        ~Clock() = default;
        Clock(const std::string &name);

        nts::Tristate compute(std::size_t pin = 1);
        void setLink(std::size_t, nts::IComponent &, std::size_t);
        void dump() const;

        nts::ComponentType getType() const;
        void updateState(nts::Tristate);
        std::string getName() const;
        PinType getPinType(std::size_t pin) const;

    private:
        std::string _name;
        nts::Tristate _state;
    };
}

#endif /* OOP_NANOTEKSPICE_2018_CLOCK_HPP_ */
