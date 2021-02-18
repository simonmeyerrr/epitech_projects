/*
** EPITECH PROJECT, 2018
** OOP_nanotekspice_2018
** File description:
** tests_true.cpp
*/

#include "tests.hpp"
#include "../src/Components/Factory.hpp"
#include "../src/Errors.hpp"

Test(True, basic)
{
    auto in = nts::Factory::createComponent("true", "name");

    cr_assert_eq(in->getType(), nts::BOOL);
    cr_assert_eq(in->getName(), "name");
    cr_assert_eq(in->getPinType(0), nts::NONE);
    cr_assert_eq(in->getPinType(1), nts::OUT);
    cr_assert_eq(in->getPinType(2), nts::NONE);
}

Test(True, errors)
{
    bool toPass = false;
    auto in = nts::Factory::createComponent("true", "");

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

Test(True, linked, .init=redirect_all_std)
{
    auto in = nts::Factory::createComponent("true", "in");

    cr_assert_eq(in->compute(1), nts::TRUE);
    in->dump();
    in->updateState(nts::TRUE);
    cr_assert_eq(in->compute(1), nts::TRUE);
    in->dump();
    in->updateState(nts::FALSE);
    cr_assert_eq(in->compute(1), nts::TRUE);
    in->dump();
    cr_assert_stdout_eq_str("True in\nTrue in\nTrue in\n");
}
