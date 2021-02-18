/*
** EPITECH PROJECT, 2018
** cpp_rush1_2018
** File description:
** Exercice 02
*/

#include <stdio.h>
#include "point.h"
#include "new.h"

typedef struct {
    Class base;
    int x;
    int y;
} PointClass;

static void Point_ctor(PointClass *point, va_list *args)
{
    if (!point)
        raise("Point: creator with null class");
    if (!args)
        raise("Point: creator with null args");
    point->x = va_arg(*args, int);
    point->y = va_arg(*args, int);
}

static void Point_dtor(PointClass *point)
{
    (void)point;
}

static const char *Point_str(PointClass *point)
{
    char *str;

    if (!point)
        raise("Point: str with null object");
    str = malloc(sizeof(char) * 35);
    if (!str)
        raise("Out of memory");
    sprintf(str, "<Point (%d, %d)>", point->x, point->y);
    return (str);
}

static PointClass *Point_add(PointClass *first, PointClass *second)
{
    if (!first || !second)
        raise("Point: add with null object");
    return (new(Point, first->x + second->x, first->y + second->y));
}

static PointClass *Point_sub(PointClass *first, PointClass *second)
{
    if (!first || !second)
        raise("Point: sub with null object");
    return (new(Point, first->x - second->x, first->y - second->y));
}

static PointClass *Point_mul(PointClass *first, PointClass *second)
{
    if (!first || !second)
        raise("Point: mul with null object");
    return (new(Point, first->x * second->x, first->y * second->y));
}

static PointClass *Point_div(PointClass *first, PointClass *second)
{
    if (!first || !second)
        raise("Point: div with null object");
    if (second->x == 0 || second->y == 0)
        raise("Point: div by zero");
    return (new(Point, first->x / second->x, first->y / second->y));
}

static PointClass _description = {
    {   /* Class struct */
        .__size__ = sizeof(PointClass),
        .__name__ = "Point",
        .__ctor__ = (ctor_t)&Point_ctor,
        .__dtor__ = (dtor_t)&Point_dtor,
        .__str__ = (to_string_t)&Point_str,
        .__add__ = (binary_operator_t)&Point_add,
        .__sub__ = (binary_operator_t)&Point_sub,
        .__mul__ = (binary_operator_t)&Point_mul,
        .__div__ = (binary_operator_t)&Point_div,
        .__eq__ = NULL,
        .__gt__ = NULL,
        .__lt__ = NULL
    },
    .x = 0,
    .y = 0
};

Class *Point = (Class *)&_description;
