/*
** EPITECH PROJECT, 2018
** OOP_nanotekspice_2018
** File description:
** C4011.hpp
*/

#ifndef OOP_NANOTEKSPICE_2018_C4011_HPP
#define OOP_NANOTEKSPICE_2018_C4011_HPP

#include <map>
#include "../Errors.hpp"
#include "IComponent.hpp"
#include "Link.hpp"

namespace nts {

    class C4011 : public IComponent {

    public:
        C4011(const std::string &name);
        ~C4011() override = default;

        nts::Tristate compute(std::size_t = 1) override;
        void setLink(std::size_t, nts::IComponent &, std::size_t) override;
        void dump() const override;
        void updateState(nts::Tristate) override;
        PinType getPinType(std::size_t pin) const override;

        std::string getName() const override { return _name; }
        nts::ComponentType getType() const override { return OTHER; }

    private:
        nts::Tristate exec_compute(std::size_t, std::size_t);

        std::string _name;
        std::map<std::size_t, Link *> _pins;
    };
};

#endif /* OOP_NANOTEKSPICE_2018_C4011_HPP */
