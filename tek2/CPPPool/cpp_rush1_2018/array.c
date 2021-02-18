/*
** EPITECH PROJECT, 2019
** cpp_rush1
** File description:
** Exercice 05
*/

#include <stdlib.h>
#include <stdarg.h>
#include "raise.h"
#include "array.h"
#include "new.h"

typedef struct
{
    Container   base;
    Class       *_type;
    size_t      _size;
    Object      **_tab;
}   ArrayClass;

typedef struct {
    Iterator    base;
    ArrayClass  *_array;
    size_t      _idx;
}   ArrayIteratorClass;

static void ArrayIterator_ctor(ArrayIteratorClass *iterator, va_list *args)
{
    if (!iterator)
        raise("ArrayIterator: creator with null class");
    if (!args)
        raise("ArrayIterator: creator with null args");
    iterator->_array = va_arg(*args, ArrayClass *);
    iterator->_idx = va_arg(*args, int);
}

static bool ArrayIterator_eq(ArrayIteratorClass *first, ArrayIteratorClass *second)
{
    if (!first || !second)
        raise("ArrayIterator: eq with null object");
    if (first->_idx == second->_idx)
        return (true);
    return (false);
}

static bool ArrayIterator_gt(ArrayIteratorClass *first, ArrayIteratorClass *second)
{
    if (!first || !second)
        raise("ArrayIterator: gt with null object");
    if (first->_idx > second->_idx)
        return (true);
    return (false);
}

static bool ArrayIterator_lt(ArrayIteratorClass *first, ArrayIteratorClass *second)
{
    if (!first || !second)
        raise("ArrayIterator: lt with null object");
    if (first->_idx < second->_idx)
        return (true);
    return (false);
}

static void ArrayIterator_incr(ArrayIteratorClass *iterator)
{
    if (!iterator)
        raise("ArrayIterator: incr with null object");
    iterator->_idx += 1;
}

static Object *ArrayIterator_getval(ArrayIteratorClass *iterator)
{
    if (!iterator)
        raise("ArrayIterator: getval with null object");
    if (iterator->_idx >= iterator->_array->_size)
        raise("ArrayIterator: getval out of range");
    return (iterator->_array->_tab[iterator->_idx]);
}

static void ArrayIterator_setval(ArrayIteratorClass *iterator, ...)
{
    va_list list;
    Class *obj;

    if (!iterator)
        raise("ArrayIterator: setval with null object");
    if (iterator->_idx >= iterator->_array->_size)
        raise("ArrayIterator: setval out of range");
    va_start(list, iterator);
    obj = iterator->_array->_tab[iterator->_idx];
    if (obj->__ctor__)
        obj->__ctor__(obj, &list);
    va_end(list);
}

static ArrayIteratorClass   ArrayIteratorDescr = {
    {   /* Iterator struct */
        {   /* Class struct */
            .__size__ = sizeof(ArrayIteratorClass),
            .__name__ = "ArrayIterator",
            .__ctor__ = (ctor_t)&ArrayIterator_ctor,
            .__dtor__ = NULL,
            .__str__ = NULL,
            .__add__ = NULL,
            .__sub__ = NULL,
            .__mul__ = NULL,
            .__div__ = NULL,
            .__eq__ = (binary_comparator_t)&ArrayIterator_eq,
            .__gt__ = (binary_comparator_t)&ArrayIterator_gt,
            .__lt__ = (binary_comparator_t)&ArrayIterator_lt,
        },
        .__incr__ = (incr_t)&ArrayIterator_incr,
        .__getval__ = (getval_t)&ArrayIterator_getval,
        .__setval__ = (setval_t)&ArrayIterator_setval,
    },
    ._array = NULL,
    ._idx = 0
};

static Class *ArrayIterator = (Class *)&ArrayIteratorDescr;

static void Array_ctor(ArrayClass *array, va_list *args)
{
    va_list args_copy;

    if (!array)
        raise("Array: creator with null class");
    if (!args)
        raise("Array: creator with null args");
    array->_size = va_arg(*args, size_t);
    array->_type = va_arg(*args, Class *);
    array->_tab = malloc(sizeof(Object *) * array->_size);
    if (!array->_tab)
        raise("Out of memory");
    for (size_t i = 0; i < array->_size; i++) {
        va_copy(args_copy, *args);
        array->_tab[i] = va_new(array->_type, &args_copy);
        va_end(args_copy);
    }
}

static void Array_dtor(ArrayClass *array)
{
    if (!array)
        return;
    for (size_t i = 0; i < array->_size; i++)
        delete(array->_tab[i]);
    free(array->_tab);
}

static size_t Array_len(ArrayClass *array)
{
    if (!array)
        raise("Array: len with null object");
    return (array->_size);
}

static Iterator *Array_begin(ArrayClass *array)
{
    if (!array)
        raise("Array: begin with null object");
    return (new(ArrayIterator, array, 0));
}

static Iterator *Array_end(ArrayClass *array)
{
    if (!array)
        raise("Array: end with null object");
    return (new(ArrayIterator, array, array->_size));
}

static Object *Array_getitem(ArrayClass *array, ...)
{
    size_t pos;
    va_list list;

    if (!array)
        raise("Array: getitem with null object");
    va_start(list, array);
    pos = va_arg(list, size_t);
    if (pos >= array->_size)
        raise("Array: getitem out of range");
    va_end(list);
    return (array->_tab[pos]);
}

static void Array_setitem(ArrayClass *array, ...)
{
    size_t pos;
    Class *obj;
    va_list list;

    if (!array)
        raise("Array: setitem with null object");
    va_start(list, array);
    pos = va_arg(list, size_t);
    if (pos >= array->_size)
        raise("Array: setitem out of range");
    obj = array->_tab[pos];
    if (obj->__ctor__)
        obj->__ctor__(obj, &list);
    va_end(list);
}

static ArrayClass   _description = {
    {   /* Container struct */
        {   /* Class struct */
            .__size__ = sizeof(ArrayClass),
            .__name__ = "Array",
            .__ctor__ = (ctor_t)&Array_ctor,
            .__dtor__ = (dtor_t)&Array_dtor,
            .__str__ = NULL,
            .__add__ = NULL,
            .__sub__ = NULL,
            .__mul__ = NULL,
            .__div__ = NULL,
            .__eq__ = NULL,
            .__gt__ = NULL,
            .__lt__ = NULL,
        },
        .__len__ = (len_t)&Array_len,
        .__begin__ = (iter_t)&Array_begin,
        .__end__ = (iter_t)&Array_end,
        .__getitem__ = (getitem_t)&Array_getitem,
        .__setitem__ = (setitem_t)&Array_setitem,
    },
    ._type = NULL,
    ._size = 0,
    ._tab = NULL
};

Class *Array = (Class *)&_description;
