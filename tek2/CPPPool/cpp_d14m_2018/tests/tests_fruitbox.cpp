/*
** EPITECH PROJECT, 2018
** cpp_d14m_2018
** File description:
** tests_fruitbox.cpp
*/

#include <criterion/criterion.h>
#include "Banana.hpp"
#include "Lemon.hpp"
#include "FruitBox.hpp"

Test(FruitBox, size_zero)
{
    FruitBox box(0);

    cr_assert_null(box.head());
    cr_assert_null(box.pickFruit());
    cr_assert_eq(0, box.nbFruits());
    cr_assert_eq(false, box.putFruit(nullptr));
    cr_assert_eq(false, box.putFruit(new Banana));
}

Test(FruitBox, normal)
{
    FruitBox box(3);
    Fruit *fruit = new Banana;

    cr_assert_null(box.head());
    cr_assert_null(box.pickFruit());
    cr_assert_eq(0, box.nbFruits());

    cr_assert_eq(false, box.putFruit(nullptr));
    cr_assert_eq(true, box.putFruit(fruit));
    cr_assert_eq(false, box.putFruit(fruit));
    cr_assert_eq(true, box.putFruit(new Banana));
    cr_assert_eq(2, box.nbFruits());
    cr_assert_eq(true, box.putFruit(new Banana));
    cr_assert_eq(3, box.nbFruits());
    cr_assert_eq(false, box.putFruit(new Banana));
    cr_assert_eq(3, box.nbFruits());
}

Test(FruitBox, pick)
{
    FruitBox box(3);

    cr_assert_null(box.head());
    cr_assert_null(box.pickFruit());
    cr_assert_eq(0, box.nbFruits());

    cr_assert_eq(true, box.putFruit(new Banana));
    cr_assert_eq(true, box.putFruit(new Lemon));
    cr_assert_eq(2, box.nbFruits());
    cr_assert_eq(std::string("banana"), box.pickFruit()->getName());
    cr_assert_eq(1, box.nbFruits());
    cr_assert_eq(std::string("lemon"), box.pickFruit()->getName());
    cr_assert_eq(0, box.nbFruits());
    cr_assert_null(box.pickFruit());
}