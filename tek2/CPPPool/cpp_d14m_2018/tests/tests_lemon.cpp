/*
** EPITECH PROJECT, 2018
** cpp_d14m_2018
** File description:
** tests_lemon.cpp
*/

#include <criterion/criterion.h>
#include "Lemon.hpp"

Test(Lemon, constructor_normal)
{
    Lemon f;

    cr_assert_eq(f.getName(), "lemon");
    cr_assert_eq(f.getVitamins(), 3);
}
