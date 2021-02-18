/*
** EPITECH PROJECT, 2019
** char
** File description:
** rush1
*/

#include <stdio.h>
#include "char.h"
#include "new.h"

typedef struct
{
    Class base;
    char _val;
}   CharClass;

static void Char_ctor(CharClass *char_class, va_list *args)
{
    if (!char_class)
        raise("Char: creator with null class");
    if (!args)
        raise("Char: creator with null args");
    char_class->_val = va_arg(*args, int);
}

static void Char_dtor(CharClass *char_class)
{
    (void)char_class;
}

static const char *Char_str(CharClass *char_class)
{
    char *str;

    if (!char_class)
        raise("Char: str with null object");
    str = malloc(sizeof(char) * 11);
    if (!str)
        raise("Out of memory");
    sprintf(str, "<Char (%c)>", char_class->_val);
    return (str);
}

static CharClass *Char_add(CharClass *first, CharClass *second)
{
    if (!first || !second)
        raise("Char: add with null object");
    return (new(Char, first->_val + second->_val));
}

static CharClass *Char_sub(CharClass *first, CharClass *second)
{
    if (!first || !second)
        raise("Char: sub with null object");
    return (new(Char, first->_val - second->_val));
}

static CharClass *Char_mul(CharClass *first, CharClass *second)
{
    if (!first || !second)
        raise("Char: mul with null object");
    return (new(Char, first->_val * second->_val));
}

static CharClass *Char_div(CharClass *first, CharClass *second)
{
    if (!first || !second)
        raise("Char: div with null object");
    if (first->_val == 0 || second->_val == 0)
        raise("Char: div by zero");
    return (new(Char, first->_val / second->_val));
}

static bool Char_eq(CharClass *first, CharClass *second)
{
    if (!first || !second)
        raise("Char: eq with null object");
    if (first->_val == second->_val)
        return (true);
    return (false);
}

static bool Char_gt(CharClass *first, CharClass *second)
{
    if (!first || !second)
        raise("Char: gt with null object");
    if (first->_val > second->_val)
        return (true);
    return (false);
}

static bool Char_lt(CharClass *first, CharClass *second)
{
    if (!first || !second)
        raise("Char: lt with null object");
    if (first->_val < second->_val)
        return (true);
    return (false);
}

static CharClass _description = {
        {   /* Class struct */
                .__size__ = sizeof(CharClass),
                .__name__ = "Char",
                .__ctor__ = (ctor_t)&Char_ctor,
                .__dtor__ = (dtor_t)&Char_dtor,
                .__str__ = (to_string_t)&Char_str,
                .__add__ = (binary_operator_t)&Char_add,
                .__sub__ = (binary_operator_t)&Char_sub,
                .__mul__ = (binary_operator_t)&Char_mul,
                .__div__ = (binary_operator_t)&Char_div,
                .__eq__ = (binary_comparator_t)&Char_eq,
                .__gt__ = (binary_comparator_t)&Char_gt,
                .__lt__ = (binary_comparator_t)&Char_lt
        },
        ._val = 0,
};

Class *Char = (Class *)&_description;
