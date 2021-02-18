/*
** EPITECH PROJECT, 2018
** OOP_nanotekspice_2018
** File description:
** tests_clock.cpp
*/

#include "tests.hpp"
#include "../src/Components/Factory.hpp"
#include "../src/Errors.hpp"

Test(Clock, basic)
{
    auto in = nts::Factory::createComponent("clock", "name");

    cr_assert_eq(in->getType(), nts::CLOCK);
    cr_assert_eq(in->getName(), "name");
    cr_assert_eq(in->getPinType(0), nts::NONE);
    cr_assert_eq(in->getPinType(1), nts::OUT);
    cr_assert_eq(in->getPinType(2), nts::NONE);
}

Test(Clock, errors)
{
    bool toPass = false;
    auto in = nts::Factory::createComponent("clock", "");

    try {
        in->compute(0);
    } catch (...) {
        toPass = true;
    }
    cr_assert(toPass);
    toPass = false;
    try {
        in->compute(1);
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

Test(Clock, linked, .init=redirect_all_std)
{
    auto out = nts::Factory::createComponent("output", "out");
    auto in = nts::Factory::createComponent("clock", "in");

    out->setLink(1, *in, 1);
    in->updateState(nts::TRUE);
    cr_assert_eq(out->compute(0), nts::TRUE);
    in->dump();
    in->updateState(nts::UNDEFINED);
    cr_assert_eq(out->compute(0), nts::FALSE);
    in->dump();
    in->updateState(nts::FALSE);
    cr_assert_eq(out->compute(0), nts::FALSE);
    cr_assert_stdout_eq_str("Clock in = 1\nClock in = 0\n");
}