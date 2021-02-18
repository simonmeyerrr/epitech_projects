/*
** EPITECH PROJECT, 2018
** OOP_nanotekspice_2018
** File description:
** Gates.hpp
*/

#ifndef OOP_NANOTEKSPICE_2018_GATES_HPP
#define OOP_NANOTEKSPICE_2018_GATES_HPP

#include "IComponent.hpp"

namespace nts {

    class Gates {
        public:
            static nts::Tristate andGate(nts::Tristate, nts::Tristate);
            static nts::Tristate reverseState(nts::Tristate);
            static nts::Tristate xorGate(nts::Tristate, nts::Tristate);
            static nts::Tristate orGate(nts::Tristate, nts::Tristate);
            static nts::Tristate anyTrue(
                nts::Tristate, nts::Tristate, nts::Tristate, nts::Tristate
            );
            static nts::Tristate oneTrue(
                nts::Tristate, nts::Tristate, nts::Tristate, nts::Tristate
            );
            static nts::Tristate twoTrue(
                nts::Tristate, nts::Tristate, nts::Tristate, nts::Tristate
            );
            static nts::Tristate threeTrue(
                nts::Tristate, nts::Tristate, nts::Tristate, nts::Tristate
            );
            static nts::Tristate fourTrue(
                nts::Tristate, nts::Tristate, nts::Tristate, nts::Tristate
            );
    };
}


#endif /* OOP_NANOTEKSPICE_2018_GATES_HPP */
