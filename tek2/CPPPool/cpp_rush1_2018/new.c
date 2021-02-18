/*
** EPITECH PROJECT, 2018
** cpp_rush1_2018
** File description:
** Exercice 01
*/

#include <stdarg.h>
#include <stdlib.h>
#include <string.h>
#include "object.h"
#include "raise.h"
#include "new.h"

Object *new(Class *my_class, ...)
{
    va_list list;
    Object *obj;

    if (!my_class)
        raise("Initialization of a null class");
    va_start(list, my_class);
    obj = va_new(my_class, &list);
    va_end(list);
    return (obj);
}

Object *va_new(Class *my_class, va_list *args)
{
    Object *obj = malloc(my_class->__size__);

    if (!obj)
        raise("Out of memory");
    obj = memcpy(obj, my_class, my_class->__size__);
    if (!obj)
        raise("Can't access to memory");
    if (my_class->__ctor__)
        my_class->__ctor__(obj, args);
    return (obj);
}

void delete(Object *obj)
{
    Class *my_class = obj;

    if (!my_class)
        raise("Deleting null object");
    if (my_class->__dtor__)
        my_class->__dtor__(obj);
    free(obj);
}