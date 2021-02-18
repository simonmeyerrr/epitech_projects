/*
** EPITECH PROJECT, 2018
** OOP_nanotekspice_2018
** File description:
** C4001.hpp
*/

#ifndef OOP_NANOTEKSPICE_2018_C4001_HPP
#define OOP_NANOTEKSPICE_2018_C4001_HPP

#include <map>
#include "../Errors.hpp"
#include "IComponent.hpp"
#include "Link.hpp"

namespace nts {

    class C4001 : public IComponent {

    public:
        C4001(const std::string &name);
        ~C4001() override = default;

        nts::Tristate compute(std::size_t = 1) override;
        void setLink(std::size_t, nts::IComponent &, std::size_t) override;
        void dump() const override;
        void updateState(nts::Tristate) override;
        PinType getPinType(std::size_t pin) const override;

        nts::ComponentType getType() const override { return OTHER; }
        std::string getName() const override { return _name; }

    private:
        nts::Tristate exec_compute(std::size_t, std::size_t);

        std::string _name;
        std::map<std::size_t, Link *> _pins;
    };
};

#endif /* OOP_NANOTEKSPICE_2018_C4001_HPP */
