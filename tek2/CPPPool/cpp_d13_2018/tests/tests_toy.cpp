/*
** EPITECH PROJECT, 2018
** cpp_d13_2018
** File description:
** tests_toy.cpp
*/

#include <criterion/criterion.h>
#include <string>
#include "Toy.hpp"

Test(Toy, without_arg)
{
    Toy toy;

    cr_assert_eq(Toy::BASIC_TOY, toy.getType());
    cr_assert_eq(std::string("toy"), toy.getName());
    cr_assert_eq(std::string(""), toy.getAscii());
}

Test(Toy, full_arg)
{
    Toy toy(Toy::ALIEN, "ET", "picture.test");

    cr_assert_eq(Toy::ALIEN, toy.getType());
    cr_assert_eq(std::string("ET"), toy.getName());
    cr_assert_eq(std::string("/--\\\n|  |\n\\--/"), toy.getAscii());
}

Test(Toy, setter)
{
    Toy toy;

    cr_assert_eq(Toy::BASIC_TOY, toy.getType());
    toy.setName("name");
    cr_assert_eq(std::string("name"), toy.getName());
    toy.setAscii("picture.test");
    cr_assert_eq(std::string("/--\\\n|  |\n\\--/"), toy.getAscii());
}

Test(Toy, copy_constructor)
{
    Toy old_toy(Toy::ALIEN, "ET", "picture.test");
    Toy toy(old_toy);

    cr_assert_eq(Toy::ALIEN, toy.getType());
    cr_assert_eq(std::string("ET"), toy.getName());
    cr_assert_eq(std::string("/--\\\n|  |\n\\--/"), toy.getAscii());
}

Test(Toy, operator_equal)
{
    Toy old_toy(Toy::ALIEN, "ET", "picture.test");
    Toy toy;

    toy = old_toy;
    cr_assert_eq(Toy::ALIEN, toy.getType());
    cr_assert_eq(std::string("ET"), toy.getName());
    cr_assert_eq(std::string("/--\\\n|  |\n\\--/"), toy.getAscii());
}