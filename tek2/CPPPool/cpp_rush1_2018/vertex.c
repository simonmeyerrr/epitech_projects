/*
** EPITECH PROJECT, 2018
** cpp_rush1_2018
** File description:
** Exercice 02
*/

#include <stdio.h>
#include "vertex.h"
#include "new.h"

typedef struct
{
    Class base;
    int x, y, z;
}   VertexClass;

static void Vertex_ctor(VertexClass *vertex, va_list *args)
{
    if (!vertex)
        raise("Vertex: creator with null class");
    if (!args)
        raise("Vertex: creator with null args");
    vertex->x = va_arg(*args, int);
    vertex->y = va_arg(*args, int);
    vertex->z = va_arg(*args, int);
}

static void Vertex_dtor(VertexClass *vertex)
{
    (void)vertex;
}

static char const *Vertex_str(VertexClass *vertex)
{
    char *str;

    if (!vertex)
        raise("Vertex: str with null object");
    str = malloc(sizeof(char) * 49);
    if (!str)
        raise("Out of memory");
    sprintf(str, "<Vertex (%d, %d, %d)>", vertex->x, vertex->y, vertex->z);
    return (str);
}

static VertexClass *Vertex_add(VertexClass *first, VertexClass *second)
{
    if (!first || !second)
        raise("Vertex: add with null object");
    return (new(Vertex, first->x + second->x, first->y + second->y,
        first->z + second->z));
}

static VertexClass *Vertex_sub(VertexClass *first, VertexClass *second)
{
    if (!first || !second)
        raise("Vertex: sub with null object");
    return (new(Vertex, first->x - second->x, first->y - second->y,
        first->z - second->z));
}

static VertexClass *Vertex_mul(VertexClass *first, VertexClass *second)
{
    if (!first || !second)
        raise("Vertex: mul with null object");
    return (new(Vertex, first->x * second->x, first->y * second->y,
        first->z * second->z));
}

static VertexClass *Vertex_div(VertexClass *first, VertexClass *second)
{
    if (!first || !second)
        raise("Vertex: div with null object");
    if (second->x == 0 || second->y == 0 || second->z == 0)
        raise("Vertex: div by zero");
    return (new(Vertex, first->x / second->x, first->y / second->y,
        first->z / second->z));
}

static VertexClass _description = {
        {   /* Class struct */
                .__size__ = sizeof(VertexClass),
                .__name__ = "Vertex",
                .__ctor__ = (ctor_t)&Vertex_ctor,
                .__dtor__ = (dtor_t)&Vertex_dtor,
                .__str__ = (to_string_t)&Vertex_str,
                .__add__ = (binary_operator_t)&Vertex_add,
                .__sub__ = (binary_operator_t)&Vertex_sub,
                .__mul__ = (binary_operator_t)&Vertex_mul,
                .__div__ = (binary_operator_t)&Vertex_div,
                .__eq__ = NULL,
                .__gt__ = NULL,
                .__lt__ = NULL
        },
        .x = 0,
        .y = 0
};

Class *Vertex = (Class *)&_description;
