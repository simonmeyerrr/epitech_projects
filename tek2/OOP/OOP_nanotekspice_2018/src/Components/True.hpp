/*
** EPITECH PROJECT, 2018
** OOP_nanotekspice_2018
** File description:
** True.hpp
*/
#ifndef OOP_NANOTEKSPICE_2018_TRUE_HPP
# define OOP_NANOTEKSPICE_2018_TRUE_HPP

# include <string>
# include "IComponent.hpp"

namespace nts {

    class True : public IComponent {
        public:
        ~True() = default;
        True(const std::string &name);

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

#endif /* OOP_NANOTEKSPICE_2018_TRUE_HPP */
