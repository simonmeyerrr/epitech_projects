/*
** EPITECH PROJECT, 2018
** cpp_rush1_2018
** File description:
** tests_int.c
*/

#include <criterion/criterion.h>
#include <limits.h>
#include <signal.h>
#include "provided_files/object.h"
#include "provided_files/int.h"
#include "provided_files/new.h"

void redirect_all_stdout(void);

Test(int, basics)
{
    Object *int1 = new(Int, 3);

    cr_assert_not_null(int1);
    delete(int1);
}

Test(int, str)
{
    Object *int1 = new(Int, -4);

    cr_assert_not_null(int1);
    cr_assert_str_eq(str(int1), "<Int (-4)>");
    delete(int1);
}

Test(int, addition)
{
    Object *int1 = new(Int, 3);
    Object *int2 = new(Int, -4);
    Object *int3 = addition(int1, int2);

    cr_assert_not_null(int3);
    cr_assert_str_eq(str(int3), "<Int (-1)>");
    delete(int1);
    delete(int2);
    delete(int3);
}

Test(int, subtraction)
{
    Object *int1 = new(Int, 3);
    Object *int2 = new(Int, -4);
    Object *int3 = subtraction(int1, int2);

    cr_assert_not_null(int3);
    cr_assert_str_eq(str(int3), "<Int (7)>");
    delete(int1);
    delete(int2);
    delete(int3);
}

Test(int, multiplication)
{
    Object *int1 = new(Int, 3);
    Object *int2 = new(Int, -4);
    Object *int3 = multiplication(int1, int2);

    cr_assert_not_null(int3);
    cr_assert_str_eq(str(int3), "<Int (-12)>");
    delete(int1);
    delete(int2);
    delete(int3);
}

Test(int, division)
{
    Object *int1 = new(Int, 12);
    Object *int2 = new(Int, -4);
    Object *int3 = division(int1, int2);

    cr_assert_not_null(int3);
    cr_assert_str_eq(str(int3), "<Int (-3)>");
    delete(int1);
    delete(int2);
    delete(int3);
}

Test(int, division_zero, .init=redirect_all_stdout, .signal = SIGABRT)
{
    Object *int1 = new(Int, 3);
    Object *int2 = new(Int, 0);

    division(int1, int2);
}


Test(int, int_limits)
{
    Object *int1 = new(Int, INT_MIN);
    Object *int2 = new(Int, INT_MAX);

    cr_assert_not_null(int1);
    cr_assert_not_null(int2);
    cr_assert_str_eq(str(int1), "<Int (-2147483648)>");
    cr_assert_str_eq(str(int2), "<Int (2147483647)>");
    delete(int1);
    delete(int2);
}