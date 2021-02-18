/*
** EPITECH PROJECT, 2018
** PSU_2018_malloc
** File description:
** realloc.c
*/

#include "../include/malloc.h"

void split(metadata_t *old, metadata_t *new_alloc)
{
    new_alloc->free = 1;
    new_alloc->total = old->total - (ALIGN(old->size) + METADATA_SIZE);
    old->total = ALIGN(old->size);
    new_alloc->size = new_alloc->total;
    new_alloc->ptr = new_alloc->data;
    new_alloc->next = old->next;
    old->next->prev = new_alloc;
    new_alloc->prev = old;
    old->next = new_alloc;
}

metadata_t *get_metadata(void *ptr)
{
    char *ptr_c = ptr;
    metadata_t *data;

    if (!ptr || !first_alloc(0, NULL) || ptr > sbrk(0) ||
        ptr < (void *)first_alloc(0, NULL))
        return (NULL);
    data = (void *)(ptr_c - METADATA_SIZE);
    if (data->ptr != ptr)
        return (NULL);
    return (data);
}

void *realloc(void *ptr, size_t size)
{
    metadata_t *data = get_metadata(ptr);

    if (!ptr)
        return (malloc(size));
    if (!data)
        return (ptr);
    if (ALIGN(size) <= ALIGN(data->total)) {
        data->size = size;
        return (ptr);
    }
    metadata_t *new_data = get_metadata(malloc(size));
    char *tmp1 = data->data;
    char *tmp2 = new_data->data;
    for (size_t i = 0; i < data->size; i++)
        tmp2[i] = tmp1[i];
    free(data->ptr);
    return (new_data->ptr);
}