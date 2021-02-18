/*
** EPITECH PROJECT, 2018
** OOP_nanotekspice_2018
** File description:
** tests_c4503.cpp
*/

#include "tests.hpp"
#include "../src/Components/Factory.hpp"
#include "../src/Errors.hpp"

Test(C4503, basic)
{
    auto in = nts::Factory::createComponent("4503", "name");

    in->updateState(nts::TRUE);
    cr_assert_eq(in->getType(), nts::OTHER);
    cr_assert_eq(in->getName(), "name");
    cr_assert_eq(in->getPinType(0), nts::NONE);
    cr_assert_eq(in->getPinType(1), nts::IN);
    cr_assert_eq(in->getPinType(2), nts::IN);
    cr_assert_eq(in->getPinType(3), nts::OUT);
    cr_assert_eq(in->getPinType(4), nts::IN);
    cr_assert_eq(in->getPinType(5), nts::OUT);
    cr_assert_eq(in->getPinType(6), nts::IN);
    cr_assert_eq(in->getPinType(7), nts::OUT);
    cr_assert_eq(in->getPinType(8), nts::NONE);
    cr_assert_eq(in->getPinType(9), nts::OUT);
    cr_assert_eq(in->getPinType(10), nts::IN);
    cr_assert_eq(in->getPinType(11), nts::OUT);
    cr_assert_eq(in->getPinType(12), nts::IN);
    cr_assert_eq(in->getPinType(13), nts::OUT);
    cr_assert_eq(in->getPinType(14), nts::IN);
    cr_assert_eq(in->getPinType(15), nts::IN);
    cr_assert_eq(in->getPinType(16), nts::NONE);
    cr_assert_eq(in->getPinType(17), nts::NONE);
}

Test(C4503, errors)
{
    bool toPass = false;
    auto in = nts::Factory::createComponent("4503", "");

    try {
        in->compute(1);
    } catch (...) {
        toPass = true;
    }
    cr_assert(toPass);
    toPass = false;
    try {
        in->compute(3);
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
        in->setLink(3, *in, 3);
    } catch (...) {
        toPass = true;
    }
    cr_assert(toPass);
}

Test(C4503, linked, .init=redirect_all_std)
{
    auto out = nts::Factory::createComponent("4503", "out");
    auto in1 = nts::Factory::createComponent("input", "in");
    auto in2 = nts::Factory::createComponent("input", "in");

    out->setLink(1, *in1, 1);
    out->setLink(2, *in2, 1);
    cr_assert_eq(out->compute(3), nts::UNDEFINED);
    in1->updateState(nts::TRUE);
    in2->updateState(nts::TRUE);
    cr_assert_eq(out->compute(3), nts::FALSE);
    in1->updateState(nts::TRUE);
    in2->updateState(nts::FALSE);
    cr_assert_eq(out->compute(3), nts::FALSE);
    in1->updateState(nts::TRUE);
    in2->updateState(nts::UNDEFINED);
    cr_assert_eq(out->compute(3), nts::FALSE);
    in1->updateState(nts::FALSE);
    in2->updateState(nts::TRUE);
    cr_assert_eq(out->compute(3), nts::TRUE);
    in1->updateState(nts::FALSE);
    in2->updateState(nts::FALSE);
    cr_assert_eq(out->compute(3), nts::FALSE);
    in1->updateState(nts::FALSE);
    in2->updateState(nts::UNDEFINED);
    cr_assert_eq(out->compute(3), nts::UNDEFINED);
    in1->updateState(nts::UNDEFINED);
    in2->updateState(nts::TRUE);
    cr_assert_eq(out->compute(3), nts::UNDEFINED);
    in1->updateState(nts::UNDEFINED);
    in2->updateState(nts::FALSE);
    cr_assert_eq(out->compute(3), nts::FALSE);
    out->dump();
    out->setLink(4, *in2, 1);
    cr_assert_eq(out->compute(5), nts::FALSE);
    out->setLink(6, *in2, 1);
    cr_assert_eq(out->compute(7), nts::FALSE);
    out->setLink(10, *in2, 1);
    cr_assert_eq(out->compute(9), nts::FALSE);
    out->setLink(15, *in1, 1);
    out->setLink(12, *in2, 1);
    cr_assert_eq(out->compute(11), nts::FALSE);
    out->setLink(14, *in2, 1);
    cr_assert_eq(out->compute(13), nts::FALSE);
}