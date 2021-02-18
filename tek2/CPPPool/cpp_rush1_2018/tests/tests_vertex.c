/*
** EPITECH PROJECT, 2018
** cpp_rush1_2018
** File description:
** tests_vertex.c
*/

#include <criterion/criterion.h>
#include <limits.h>
#include <signal.h>
#include "provided_files/object.h"
#include "provided_files/vertex.h"
#include "provided_files/new.h"

void redirect_all_stdout(void);

Test(vertex, basics)
{
    Object *vertex = new(Vertex, 3, 8, 4);

    cr_assert_not_null(vertex);
    delete(vertex);
}

Test(vertex, str)
{
    Object *vertex = new(Vertex, -4, 2, 13);

    cr_assert_not_null(vertex);
    cr_assert_str_eq(str(vertex), "<Vertex (-4, 2, 13)>");
    delete(vertex);
}

Test(vertex, addition)
{
    Object *vertex1 = new(Vertex, 3, 8, 4);
    Object *vertex2 = new(Vertex, -4, 2, 13);
    Object *vertex3 = addition(vertex1, vertex2);

    cr_assert_not_null(vertex3);
    cr_assert_str_eq(str(vertex3), "<Vertex (-1, 10, 17)>");
    delete(vertex1);
    delete(vertex2);
    delete(vertex3);
}

Test(vertex, subtraction)
{
    Object *vertex1 = new(Vertex, 3, 8, 4);
    Object *vertex2 = new(Vertex, -4, 2, 13);
    Object *vertex3 = subtraction(vertex1, vertex2);

    cr_assert_not_null(vertex3);
    cr_assert_str_eq(str(vertex3), "<Vertex (7, 6, -9)>");
    delete(vertex1);
    delete(vertex2);
    delete(vertex3);
}

Test(vertex, multiplication)
{
    Object *vertex1 = new(Vertex, 3, 8, 4);
    Object *vertex2 = new(Vertex, -4, 2, 13);
    Object *vertex3 = multiplication(vertex1, vertex2);

    cr_assert_not_null(vertex3);
    cr_assert_str_eq(str(vertex3), "<Vertex (-12, 16, 52)>");
    delete(vertex1);
    delete(vertex2);
    delete(vertex3);
}

Test(vertex, division)
{
    Object *vertex1 = new(Vertex, 12, 8, 4);
    Object *vertex2 = new(Vertex, -4, 2, 4);
    Object *vertex3 = division(vertex1, vertex2);

    cr_assert_not_null(vertex3);
    cr_assert_str_eq(str(vertex3), "<Vertex (-3, 4, 1)>");
    delete(vertex1);
    delete(vertex2);
    delete(vertex3);
}

Test(vertex, division_zero, .init=redirect_all_stdout, .signal = SIGABRT)
{
    Object *vertex1 = new(Vertex, 3, 8, 4);
    Object *vertex2 = new(Vertex, -4, 0, 13);
    division(vertex1, vertex2);
}


Test(vertex, int_limits)
{
    Object *vertex1 = new(Vertex, INT_MIN, INT_MIN, INT_MIN);
    Object *vertex2 = new(Vertex, INT_MAX, INT_MAX, INT_MAX);

    cr_assert_not_null(vertex1);
    cr_assert_not_null(vertex2);
    cr_assert_str_eq(str(vertex1),
        "<Vertex (-2147483648, -2147483648, -2147483648)>");
    cr_assert_str_eq(str(vertex2),
        "<Vertex (2147483647, 2147483647, 2147483647)>");
    delete(vertex1);
    delete(vertex2);
}