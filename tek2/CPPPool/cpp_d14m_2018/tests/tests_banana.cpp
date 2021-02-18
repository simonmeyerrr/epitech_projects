/*
** EPITECH PROJECT, 2018
** cpp_d14m_2018
** File description:
** tests_banana.cpp
*/

#include <criterion/criterion.h>
#include "Banana.hpp"

Test(Banana, constructor_normal)
{
    Banana f;

    cr_assert_eq(f.getName(), "banana");
    cr_assert_eq(f.getVitamins(), 5);
}
