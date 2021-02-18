/*
** EPITECH PROJECT, 2018
** PSU_2018_malloc
** File description:
** calloc.c
*/

#include <string.h>
#include "../include/malloc.h"

void *calloc(size_t size)
{
    void *ptr = malloc(size);

    if (ptr == NULL)
        return (NULL);
    memset(ptr, 0, size);
}
