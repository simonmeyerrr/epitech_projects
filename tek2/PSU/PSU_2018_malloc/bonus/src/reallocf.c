/*
** EPITECH PROJECT, 2018
** PSU_2018_malloc
** File description:
** reallocf.c
*/

#include "../include/malloc.h"

void *reallocf(void *ptr, size_t size)
{
    void *new_ptr = realloc(ptr, size);

    if (new_ptr == NULL)
        free(ptr);
    return (new_ptr);
}
