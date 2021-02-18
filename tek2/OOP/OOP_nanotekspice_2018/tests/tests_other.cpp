/*
** EPITECH PROJECT, 2018
** OOP_nanotekspice_2018
** File description:
** tests_other.cpp
*/

#include "tests.hpp"
#include "../src/Errors.hpp"
#include "../src/Components/Link.hpp"
#include "../src/Components/IComponent.hpp"

Test(Tristate, tristate, .init=redirect_all_std)
{
    bool toPass = false;

    cr_assert_eq(nts::tristateToString(nts::TRUE), std::string("1"));
    cr_assert_eq(nts::tristateToString(nts::FALSE), std::string("0"));
    cr_assert_eq(nts::tristateToString(nts::UNDEFINED), std::string("U"));
    cr_assert_eq(nts::stringToTristate("1"), nts::TRUE);
    cr_assert_eq(nts::stringToTristate("0"), nts::FALSE);
    cr_assert_eq(nts::stringToTristate("U"), nts::UNDEFINED);
    try {
        nts::stringToTristate("bite");
    } catch(...) {
        toPass = true;
    }
    cr_assert(toPass);
    toPass = false;
    try {
        nts::stringToTristate("bite");
    } catch(const nts::Errors &e) {
        e.dump();
        toPass = true;
    }
    cr_assert(toPass);
}