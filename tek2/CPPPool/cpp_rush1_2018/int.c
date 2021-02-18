/*
** EPITECH PROJECT, 2022
** cpp_rush1
** File description:
** Exerice 04
*/

#include <stdio.h>
#include "int.h"
#include "new.h"

typedef struct {
    Class base;
    int _val;
} IntClass;

static void Int_ctor(IntClass *int_class, va_list *args)
{
    if (!int_class)
        raise("Int: creator with null class");
    if (!args)
        raise("Int: creator with null args");
    int_class->_val = va_arg(*args, int);
}

static void Int_dtor(IntClass *this)
{
    (void)this;
}

static const char *Int_str(IntClass *int_class)
{
    char *str;

    if (!int_class)
        raise("Int: str with null object");
    str = malloc(sizeof(char) * 20);
    if (!str)
        raise("Out of memory");
    sprintf(str, "<Int (%d)>", int_class->_val);
    return (str);
}

static IntClass *Int_add(IntClass *first, IntClass *second)
{
    if (!first || !second)
        raise("Int: add with null object");
    return (new(Int, first->_val + second->_val));
}

static IntClass *Int_sub(IntClass *first, IntClass *second)
{
    if (!first || !second)
        raise("Int: sub with null object");
    return (new(Int, first->_val - second->_val));
}

static IntClass *Int_mul(IntClass *first, IntClass *second)
{
    if (!first || !second)
        raise("Int: mul with null object");
    return (new(Int, first->_val * second->_val));
}

static IntClass *Int_div(IntClass *first, IntClass *second)
{
    if (!first || !second)
        raise("Int: div with null object");
    if (second->_val == 0)
        raise("Int: div by zero");
    return (new(Int, first->_val / second->_val));
}

static bool Int_eq(const IntClass *first, const IntClass *second)
{
    if (!first || !second)
        raise("Int: eq with null object");
    if (first->_val == second->_val)
        return (true);
    return (false);
}

static bool Int_gt(const IntClass *first, const IntClass *second)
{
    if (!first || !second)
        raise("Int: gt with null object");
    if (first->_val > second->_val)
        return (true);
    return (false);
}

static bool Int_lt(const IntClass *first, const IntClass *second)
{
    if (!first || !second)
        raise("Int: lt with null object");
    if (first->_val < second->_val)
        return (true);
    return (false);
}

static IntClass _description = {
    {   /* Class struct */
        .__size__ = sizeof(IntClass),
        .__name__ = "Int",
        .__ctor__ = (ctor_t)&Int_ctor,
        .__dtor__ = (dtor_t)&Int_dtor,
        .__str__ = (to_string_t)&Int_str,
        .__add__ = (binary_operator_t)&Int_add,
        .__sub__ = (binary_operator_t)&Int_sub,
        .__mul__ = (binary_operator_t)&Int_mul,
        .__div__ = (binary_operator_t)&Int_div,
        .__eq__ = (binary_comparator_t)&Int_eq,
        .__gt__ = (binary_comparator_t)&Int_gt,
        .__lt__ = (binary_comparator_t)&Int_lt
    },
    ._val = 0
};

Class *Int = (Class *)&_description;