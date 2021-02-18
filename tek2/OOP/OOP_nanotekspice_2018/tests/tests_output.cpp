/*
** EPITECH PROJECT, 2018
** OOP_nanotekspice_2018
** File description:
** tests_output.cpp
*/

#include "tests.hpp"
#include "../src/Components/Factory.hpp"
#include "../src/Errors.hpp"

Test(Output, basic)
{
    auto out = nts::Factory::createComponent("output", "name");

    cr_assert_eq(out->getType(), nts::OUTPUT);
    cr_assert_eq(out->getName(), "name");
    cr_assert_eq(out->getPinType(0), nts::NONE);
    cr_assert_eq(out->getPinType(1), nts::IN);
    cr_assert_eq(out->getPinType(2), nts::NONE);
    out->updateState(nts::UNDEFINED);
}

Test(Output, errors)
{
    bool toPass = false;
    auto out = nts::Factory::createComponent("output", "");
    auto in = nts::Factory::createComponent("input", "");

    try {
        out->compute(0);
    } catch (const nts::Errors &e) {
        cr_assert_eq(e.where(), "Output");
        toPass = true;
    }
    cr_assert(toPass);
    toPass = false;
    try {
        out->setLink(2, *in, 1);
    } catch (const nts::Errors &e) {
        cr_assert_eq(e.where(), "Output");
        toPass = true;
    }
    cr_assert(toPass);
    toPass = false;
    try {
        out->setLink(1, *in, 2);
    } catch (const nts::Errors &e) {
        cr_assert_eq(e.where(), "Output");
        toPass = true;
    }
    cr_assert(toPass);
}

Test(Output, dump, .init=redirect_all_std)
{
    auto out = nts::Factory::createComponent("output", "out");
    auto in = nts::Factory::createComponent("input", "in");

    out->dump();
    out->setLink(1, *in, 1);
    out->dump();
    out->compute(1);
    cr_assert_stdout_eq_str("Output out:\n-pin1: input not linked\n" \
    "Output out:\n-pin1: input linked\n");
}