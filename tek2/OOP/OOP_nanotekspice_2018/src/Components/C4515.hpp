/*
** EPITECH PROJECT, 2018
** OOP_nanotekspice_2018
** File description:
** C4415.hpp
*/

#ifndef OOP_NANOTEKSPICE_2018_C4515_HPP
#define OOP_NANOTEKSPICE_2018_C4515_HPP

#include <map>
#include "../Errors.hpp"
#include "IComponent.hpp"
#include "Link.hpp"

namespace nts {

    class C4515 : public IComponent {

    public:
        C4515(const std::string &name);
        ~C4515() override = default;

        nts::Tristate compute(std::size_t = 1) override;
        void setLink(std::size_t, nts::IComponent &, std::size_t) override;
        void dump() const override;
        PinType getPinType(std::size_t pin) const override;
        void updateState(nts::Tristate) override;

        std::string getName() const override { return _name; }
        nts::ComponentType getType() const override { return OTHER; }

    private:
        nts::Tristate exec_compute_any(std::size_t, std::size_t,
            std::size_t, std::size_t,  std::size_t, std::size_t);
        nts::Tristate exec_compute_one(std::size_t, std::size_t,
            std::size_t, std::size_t, std::size_t, std::size_t);
        nts::Tristate exec_compute_two(std::size_t, std::size_t,
            std::size_t, std::size_t, std::size_t, std::size_t);
        nts::Tristate exec_compute_three(std::size_t, std::size_t,
            std::size_t, std::size_t, std::size_t, std::size_t);
        nts::Tristate exec_compute_four(std::size_t, std::size_t,
            std::size_t, std::size_t, std::size_t, std::size_t);

        std::string _name;
        std::map<std::size_t, Link *> _pins;
    };
};

#endif /* OOP_NANOTEKSPICE_2018_C4515_HPP */
