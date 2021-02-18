/*
** EPITECH PROJECT, 2018
** OOP_nanotekspice_2018
** File description:
** tests_input.cpp
*/

#include "tests.hpp"
#include "../src/Components/Factory.hpp"
#include "../src/Errors.hpp"

Test(Input, basic)
{
    auto in = nts::Factory::createComponent("input", "name");

    cr_assert_eq(in->getType(), nts::INPUT);
    cr_assert_eq(in->getName(), "name");
    cr_assert_eq(in->getPinType(0), nts::NONE);
    cr_assert_eq(in->getPinType(1), nts::OUT);
    cr_assert_eq(in->getPinType(2), nts::NONE);
}

Test(Input, errors)
{
    bool toPass = false;
    auto in = nts::Factory::createComponent("input", "");

    try {
        nts::Factory::createComponent("bite", "");
    } catch (...) {
        toPass = true;
    }
    cr_assert(toPass);
    toPass = false;
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

Test(Input, linked, .init=redirect_all_std)
{
    auto in = nts::Factory::createComponent("input", "in");

    cr_assert_eq(in->compute(1), nts::UNDEFINED);
    in->dump();
    in->updateState(nts::TRUE);
    cr_assert_eq(in->compute(1), nts::TRUE);
    in->dump();
    in->updateState(nts::FALSE);
    cr_assert_eq(in->compute(1), nts::FALSE);
    in->dump();
    cr_assert_stdout_eq_str("Input in = U\nInput in = 1\nInput in = 0\n");
}
