/*
** EPITECH PROJECT, 2018
** OOP_nanotekspice_2018
** File description:
** Output.hpp
*/

#ifndef OOP_NANOTEKSPICE_2018_OUTPUT_HPP_
# define OOP_NANOTEKSPICE_2018_OUTPUT_HPP_

# include <map>
# include <string>
# include "IComponent.hpp"
#include "Link.hpp"

namespace nts {

    class Output : public IComponent {
    public:
        ~Output() override = default;
        explicit Output(const std::string &name);

        nts::Tristate compute(std::size_t = 1) override;
        void setLink(std::size_t, nts::IComponent &, std::size_t) override;
        void dump() const override;

        nts::ComponentType getType() const override;
        void updateState(nts::Tristate) override;
        std::string getName() const override;
        PinType getPinType(std::size_t pin) const override;

    private:
        std::string _name;
        nts::Tristate _state;

        std::map<std::size_t, Link *> _pins;
    };
}

#endif /* OOP_NANOTEKSPICE_2018_OUTPUT_HPP_ */
