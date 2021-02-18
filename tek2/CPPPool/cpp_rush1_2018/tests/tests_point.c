/*
** EPITECH PROJECT, 2018
** cpp_rush1_2018
** File description:
** tests_point.c
*/

#include <criterion/criterion.h>
#include <limits.h>
#include <signal.h>
#include "provided_files/object.h"
#include "provided_files/point.h"
#include "provided_files/new.h"

void redirect_all_stdout(void);

Test(point, basics)
{
    Object *point = new(Point, 3, 8);

    cr_assert_not_null(point);
    delete(point);
}

Test(point, str)
{
    Object *point = new(Point, -4, 2);

    cr_assert_not_null(point);
    cr_assert_str_eq(str(point), "<Point (-4, 2)>");
    delete(point);
}

Test(point, addition)
{
    Object *point1 = new(Point, 3, 8);
    Object *point2 = new(Point, -4, 2);
    Object *point3 = addition(point1, point2);

    cr_assert_not_null(point3);
    cr_assert_str_eq(str(point3), "<Point (-1, 10)>");
    delete(point1);
    delete(point2);
    delete(point3);
}

Test(point, subtraction)
{
    Object *point1 = new(Point, 3, 8);
    Object *point2 = new(Point, -4, 2);
    Object *point3 = subtraction(point1, point2);

    cr_assert_not_null(point3);
    cr_assert_str_eq(str(point3), "<Point (7, 6)>");
    delete(point1);
    delete(point2);
    delete(point3);
}

Test(point, multiplication)
{
    Object *point1 = new(Point, 3, 8);
    Object *point2 = new(Point, -4, 2);
    Object *point3 = multiplication(point1, point2);

    cr_assert_not_null(point3);
    cr_assert_str_eq(str(point3), "<Point (-12, 16)>");
    delete(point1);
    delete(point2);
    delete(point3);
}

Test(point, division)
{
    Object *point1 = new(Point, 12, 8);
    Object *point2 = new(Point, -4, 2);
    Object *point3 = division(point1, point2);

    cr_assert_not_null(point3);
    cr_assert_str_eq(str(point3), "<Point (-3, 4)>");
    delete(point1);
    delete(point2);
    delete(point3);
}

Test(point, division_zero, .init=redirect_all_stdout, .signal = SIGABRT)
{
    Object *point1 = new(Point, 3, 8);
    Object *point2 = new(Point, -4, 0);
    division(point1, point2);
}


Test(point, int_limits)
{
    Object *point1 = new(Point, INT_MIN, INT_MIN);
    Object *point2 = new(Point, INT_MAX, INT_MAX);

    cr_assert_not_null(point1);
    cr_assert_not_null(point2);
    cr_assert_str_eq(str(point1), "<Point (-2147483648, -2147483648)>");
    cr_assert_str_eq(str(point2), "<Point (2147483647, 2147483647)>");
    delete(point1);
    delete(point2);
}