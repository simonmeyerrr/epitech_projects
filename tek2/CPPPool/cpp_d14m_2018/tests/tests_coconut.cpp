/*
** EPITECH PROJECT, 2018
** cpp_d14m_2018
** File description:
** tests_coconut.cpp
*/

#include <criterion/criterion.h>
#include "Coconut.hpp"

Test(Coconut, constructor_normal)
{
    Coconut f;

    cr_assert_eq(f.getName(), "coconut");
    cr_assert_eq(f.getVitamins(), 15);
}