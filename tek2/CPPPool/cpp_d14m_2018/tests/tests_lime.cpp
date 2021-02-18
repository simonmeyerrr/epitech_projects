/*
** EPITECH PROJECT, 2018
** cpp_d14m_2018
** File description:
** tests_lime.cpp
*/

#include <criterion/criterion.h>
#include "Lime.hpp"

Test(Lime, constructor_normal)
{
    Lime f;

    cr_assert_eq(f.getName(), "lime");
    cr_assert_eq(f.getVitamins(), 2);
}
