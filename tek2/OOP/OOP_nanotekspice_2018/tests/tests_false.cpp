/*
** EPITECH PROJECT, 2018
** OOP_nanotekspice_2018
** File description:
** tests_false.cpp
*/

#include "tests.hpp"
#include "../src/Components/Factory.hpp"
#include "../src/Errors.hpp"

Test(False, basic)
{
    auto in = nts::Factory::createComponent("false", "name");

    cr_assert_eq(in->getType(), nts::BOOL);
    cr_assert_eq(in->getName(), "name");
    cr_assert_eq(in->getPinType(0), nts::NONE);
    cr_assert_eq(in->getPinType(1), nts::OUT);
    cr_assert_eq(in->getPinType(2), nts::NONE);
}

Test(False, errors)
{
    bool toPass = false;
    auto in = nts::Factory::createComponent("false", "");

    try {
        in->compute(0);
    } catch (...) {
        toPass = true;
    }
    cr_assert(toPass);
    toPass = false;
    try {
        in->compute(2);
    } catch (...) {
        toPass = true;
    }
    cr_assert(toPass);
    toPass = false;
    try {
        in->setLink(1, *in, 1);
    } catch (...) {
        toPass = true;
    }
    cr_assert(toPass);
}

Test(False, linked, .init=redirect_all_std)
{
    auto in = nts::Factory::createComponent("false", "in");

    cr_assert_eq(in->compute(1), nts::FALSE);
    in->dump();
    in->updateState(nts::TRUE);
    cr_assert_eq(in->compute(1), nts::FALSE);
    in->dump();
    in->updateState(nts::FALSE);
    cr_assert_eq(in->compute(1), nts::FALSE);
    in->dump();
    cr_assert_stdout_eq_str("False in\nFalse in\nFalse in\n");
}
