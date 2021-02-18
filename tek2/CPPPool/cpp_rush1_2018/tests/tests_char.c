/*
** EPITECH PROJECT, 2018
** cpp_rush1_2018
** File description:
** tests_char.c
*/

#include <criterion/criterion.h>
#include <limits.h>
#include <signal.h>
#include "provided_files/object.h"
#include "provided_files/char.h"
#include "provided_files/new.h"

void redirect_all_stdout(void);

Test(char, basics)
{
    Object *char1 = new(Char, 'a');

    cr_assert_not_null(char1);
    delete(char1);
}

Test(char, str)
{
    Object *char1 = new(Char, 'r');

    cr_assert_not_null(char1);
    cr_assert_str_eq(str(char1), "<Char (r)>");
    delete(char1);
}

Test(char, addition)
{
    Object *char1 = new(Char, 'b');
    Object *char2 = new(Char, 2);
    Object *char3 = addition(char1, char2);

    cr_assert_not_null(char3);
    cr_assert_str_eq(str(char3), "<Char (d)>");
    delete(char1);
    delete(char2);
    delete(char3);
}

Test(char, subtraction)
{
    Object *char1 = new(Char, 'r');
    Object *char2 = new(Char, 1);
    Object *char3 = subtraction(char1, char2);

    cr_assert_not_null(char3);
    cr_assert_str_eq(str(char3), "<Char (q)>");
    delete(char1);
    delete(char2);
    delete(char3);
}

Test(char, multiplication)
{
    Object *char1 = new(Char, 'R');
    Object *char2 = new(Char, 1);
    Object *char3 = multiplication(char1, char2);

    cr_assert_not_null(char3);
    cr_assert_str_eq(str(char3), "<Char (R)>");
    delete(char1);
    delete(char2);
    delete(char3);
}

Test(char, division)
{
    Object *char1 = new(Char, 'i');
    Object *char2 = new(Char, 1);
    Object *char3 = division(char1, char2);

    cr_assert_not_null(char3);
    cr_assert_str_eq(str(char3), "<Char (i)>");
    delete(char1);
    delete(char2);
    delete(char3);
}

Test(char, division_zero, .init=redirect_all_stdout, .signal = SIGABRT)
{
    Object *char1 = new(Char, 3);
    Object *char2 = new(Char, 0);

    division(char1, char2);
}