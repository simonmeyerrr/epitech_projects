/*
** EPITECH PROJECT, 2018
** OOP_nanotekspice_2018
** File description:
** tests_c4069.cpp
*/

#include "tests.hpp"
#include "../src/Components/Factory.hpp"
#include "../src/Errors.hpp"

Test(C4069, basic)
{
    auto in = nts::Factory::createComponent("4069", "name");

    in->updateState(nts::TRUE);
    cr_assert_eq(in->getType(), nts::OTHER);
    cr_assert_eq(in->getName(), "name");
    cr_assert_eq(in->getPinType(0), nts::NONE);
    cr_assert_eq(in->getPinType(1), nts::IN);
    cr_assert_eq(in->getPinType(2), nts::OUT);
    cr_assert_eq(in->getPinType(3), nts::IN);
    cr_assert_eq(in->getPinType(4), nts::OUT);
    cr_assert_eq(in->getPinType(5), nts::IN);
    cr_assert_eq(in->getPinType(6), nts::OUT);
    cr_assert_eq(in->getPinType(7), nts::NONE);
    cr_assert_eq(in->getPinType(8), nts::OUT);
    cr_assert_eq(in->getPinType(9), nts::IN);
    cr_assert_eq(in->getPinType(10), nts::OUT);
    cr_assert_eq(in->getPinType(11), nts::IN);
    cr_assert_eq(in->getPinType(12), nts::OUT);
    cr_assert_eq(in->getPinType(13), nts::IN);
    cr_assert_eq(in->getPinType(14), nts::NONE);
    cr_assert_eq(in->getPinType(15), nts::NONE);
}

Test(C4069, errors)
{
    bool toPass = false;
    auto in = nts::Factory::createComponent("4069", "");

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
    toPass = false;
    try {
        in->setLink(2, *in, 2);
    } catch (...) {
        toPass = true;
    }
    cr_assert(toPass);
}

Test(C4069, linked, .init=redirect_all_std)
{
    auto out = nts::Factory::createComponent("4069", "out");
    auto in = nts::Factory::createComponent("input", "in");

    out->setLink(1, *in, 1);
    cr_assert_eq(out->compute(2), nts::UNDEFINED);
    in->updateState(nts::TRUE);
    cr_assert_eq(out->compute(2), nts::FALSE);
    in->updateState(nts::FALSE);
    cr_assert_eq(out->compute(2), nts::TRUE);
    out->dump();
    out->setLink(3, *in, 1);
    out->setLink(5, *in, 1);
    out->setLink(9, *in, 1);
    out->setLink(11, *in, 1);
    out->setLink(13, *in, 1);
    cr_assert_eq(out->compute(4), nts::TRUE);
    cr_assert_eq(out->compute(6), nts::TRUE);
    cr_assert_eq(out->compute(8), nts::TRUE);
    cr_assert_eq(out->compute(10), nts::TRUE);
    cr_assert_eq(out->compute(12), nts::TRUE);
}