/*
** EPITECH PROJECT, 2018
** PSU_2018_malloc
** File description:
** free.c
*/

#include "../include/malloc.h"

metadata_t *first_alloc(int type, void *set)
{
    static void *first = NULL;

    if (type == 1)
        first = set;
    return (first);
}

void free(void *ptr)
{
    metadata_t *data = get_metadata(ptr);

    if (!data)
        return;
    data->free = 1;
}