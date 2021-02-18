/*
** EPITECH PROJECT, 2018
** OOP_nanotekspice_2018
** File description:
** tests_c4515.cpp
*/

#include "tests.hpp"
#include "../src/Components/Factory.hpp"
#include "../src/Errors.hpp"

Test(C4515, basic)
{
    auto in = nts::Factory::createComponent("4515", "name");

    in->updateState(nts::TRUE);
    cr_assert_eq(in->getType(), nts::OTHER);
    cr_assert_eq(in->getName(), "name");
    cr_assert_eq(in->getPinType(0), nts::NONE);
    cr_assert_eq(in->getPinType(1), nts::IN);
    cr_assert_eq(in->getPinType(2), nts::IN);
    cr_assert_eq(in->getPinType(3), nts::IN);
    cr_assert_eq(in->getPinType(4), nts::OUT);
    cr_assert_eq(in->getPinType(5), nts::OUT);
    cr_assert_eq(in->getPinType(6), nts::OUT);
    cr_assert_eq(in->getPinType(7), nts::OUT);
    cr_assert_eq(in->getPinType(8), nts::OUT);
    cr_assert_eq(in->getPinType(9), nts::OUT);
    cr_assert_eq(in->getPinType(10), nts::OUT);
    cr_assert_eq(in->getPinType(11), nts::OUT);
    cr_assert_eq(in->getPinType(12), nts::NONE);
    cr_assert_eq(in->getPinType(13), nts::OUT);
    cr_assert_eq(in->getPinType(14), nts::OUT);
    cr_assert_eq(in->getPinType(15), nts::OUT);
    cr_assert_eq(in->getPinType(16), nts::OUT);
    cr_assert_eq(in->getPinType(17), nts::OUT);
    cr_assert_eq(in->getPinType(18), nts::OUT);
    cr_assert_eq(in->getPinType(19), nts::OUT);
    cr_assert_eq(in->getPinType(20), nts::OUT);
    cr_assert_eq(in->getPinType(21), nts::IN);
    cr_assert_eq(in->getPinType(22), nts::IN);
    cr_assert_eq(in->getPinType(23), nts::IN);
    cr_assert_eq(in->getPinType(24), nts::NONE);
    cr_assert_eq(in->getPinType(25), nts::NONE);
}

Test(C4515, errors)
{
    bool toPass = false;
    auto in = nts::Factory::createComponent("4515", "");

    try {
        in->compute(1);
    } catch (...) {
        toPass = true;
    }
    cr_assert(toPass);
    toPass = false;
    try {
        in->compute(4);
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
    toPass = false;
    try {
        in->setLink(4, *in, 4);
    } catch (...) {
        toPass = true;
    }
    cr_assert(toPass);
}

Test(C4515, linked, .init=redirect_all_std)
{
    auto out = nts::Factory::createComponent("4515", "out");
    auto a = nts::Factory::createComponent("input", "in");
    auto b = nts::Factory::createComponent("input", "in");
    auto c = nts::Factory::createComponent("input", "in");
    auto d = nts::Factory::createComponent("input", "in");
    auto inhibit = nts::Factory::createComponent("input", "in");
    auto strobe = nts::Factory::createComponent("input", "in");

    out->setLink(1, *strobe, 1);
    out->setLink(2, *a, 1);
    out->setLink(3, *b, 1);
    out->setLink(21, *c, 1);
    out->setLink(22, *d, 1);
    out->setLink(23, *inhibit, 1);
    cr_assert_eq(out->compute(4), nts::UNDEFINED);
    out->dump();
}