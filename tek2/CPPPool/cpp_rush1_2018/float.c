/*
** EPITECH PROJECT, 2019
** cpp_rush1_2018
** File description:
** float.c
*/

#include <string.h>
#include "float.h"
#include "new.h"

typedef struct {
    Class base;
    float _val;
} FloatClass;

static void Float_ctor(FloatClass *float_class, va_list *args)
{
    if (!float_class)
        raise("Float: creator with null class");
    if (!args)
        raise("Float: creator with null args");
    float_class->_val = va_arg(*args, double);
}

static void Float_dtor(FloatClass *float_class)
{
    (void)float_class;
}

static const char *Float_str(FloatClass *float_class)
{
    char *str;

    if (!float_class)
        raise("Float: str with null object");
    str = malloc(sizeof(char) * 26);
    if (!str)
        raise("Out of memory");
    sprintf(str, "<Float (%f)>", float_class->_val);
    return (str);
}

static FloatClass *Float_add(FloatClass *first, FloatClass *second)
{
    if (!first || !second)
        raise("Float: add with null object");
    return (new(Float, first->_val + second->_val));
}

static FloatClass *Float_sub(FloatClass *first, FloatClass *second)
{
    if (!first || !second)
        raise("Float: sub with null object");
    return (new(Float, first->_val - second->_val));
}

static FloatClass *Float_mul(FloatClass *first, FloatClass *second)
{
    if (!first || !second)
        raise("Float: mul with null object");
    return (new(Float, first->_val * second->_val));
}

static FloatClass *Float_div(FloatClass *first, FloatClass *second)
{
    if (!first || !second)
        raise("Float: div with null object");
    if (second->_val == 0)
        raise("Float: div by zero");
    return (new(Float, first->_val / second->_val));
}

static bool Float_eq(FloatClass *first, FloatClass *second)
{
    if (!first || !second)
        raise("Float: eq with null object");
    if (first->_val == second->_val)
        return (true);
    return (false);
}

static bool Float_gt(FloatClass *first, FloatClass *second)
{
    if (!first || !second)
        raise("Float: gt with null object");
    if (first->_val > second->_val)
        return (true);
    return (false);
}

static bool Float_lt(FloatClass *first, FloatClass *second)
{
    if (!first || !second)
        raise("Float: lt with null object");
    if (first->_val < second->_val)
        return (true);
    return (false);
}

static FloatClass _description = {
    {   /* Class struct */
        .__size__ = sizeof(FloatClass),
        .__name__ = "Float",
        .__ctor__ = (ctor_t)&Float_ctor,
        .__dtor__ = (dtor_t)&Float_dtor,
        .__str__ = (to_string_t)&Float_str,
        .__add__ = (binary_operator_t)&Float_add,
        .__sub__ = (binary_operator_t)&Float_sub,
        .__mul__ = (binary_operator_t)&Float_mul,
        .__div__ = (binary_operator_t)&Float_div,
        .__eq__ = (binary_comparator_t)&Float_eq,
        .__gt__ = (binary_comparator_t)&Float_gt,
        .__lt__ = (binary_comparator_t)&Float_lt
    },
    ._val = 0.0
};

Class *Float = (Class *)&_description;
