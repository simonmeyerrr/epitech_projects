/*
** EPITECH PROJECT, 2018
** PSU_2018_malloc
** File description:
** malloc.c
*/

#include "../include/malloc.h"

static void *init_alloc(size_t size)
{
    metadata_t *last = first_alloc(0, NULL)->prev;
    metadata_t *new_zone = sbrk(0);
    size_t to_alloc = PAGE_SIZE;

    while (to_alloc < ALIGN(size) + METADATA_SIZE)
        to_alloc += PAGE_SIZE;
    if (sbrk(to_alloc) == (void *)-1)
        return (NULL);
    new_zone->free = 0;
    new_zone->total = to_alloc - METADATA_SIZE;
    new_zone->size = size;
    new_zone->ptr = new_zone->data;
    new_zone->prev = last;
    last->next = new_zone;
    new_zone->next = first_alloc(0, NULL);
    first_alloc(0, NULL)->prev = new_zone;
    if (new_zone->total >= ALIGN(size) + METADATA_SIZE + ALIGN(1))
        split(new_zone, (void *)(new_zone->data + ALIGN(size)));
    return (new_zone->data);
}

static metadata_t *get_available_zone(size_t size)
{
    int round = 0;
    metadata_t *tmp = first_alloc(0, NULL);
    metadata_t *best = NULL;

    while (tmp && (tmp != first_alloc(0, NULL) || round == 0)) {
        if (tmp->free == 1 && tmp->total == ALIGN(size))
            return (tmp);
        if (tmp->free == 1 && tmp->total >= ALIGN(size) && !best)
            best = tmp;
        if (!best && tmp->free == 1 &&
            tmp->total >= ALIGN(size) + METADATA_SIZE + ALIGN(1))
            best = tmp;
        if (best && tmp->free == 1 &&
            tmp->total >= ALIGN(size) + METADATA_SIZE + ALIGN(1) &&
            tmp->total < best->total)
            best = tmp;
        tmp = tmp->next;
        round = 1;
    }
    return (best);
}

static void *alloc_on_zone(metadata_t *zone, size_t size)
{
    zone->free = 0;
    zone->size = size;
    if (zone->total >= ALIGN(size) + METADATA_SIZE + ALIGN(1))
        split(zone, (void *)(zone->data + ALIGN(size)));
    return (zone->data);
}

static void *new_allocation(size_t size)
{
    first_alloc(1, sbrk(0));
    size_t to_alloc = PAGE_SIZE;

    while (to_alloc < ALIGN(size) + METADATA_SIZE)
        to_alloc += PAGE_SIZE;
    if (sbrk(to_alloc) == (void *)-1)
        return (NULL);
    first_alloc(0, NULL)->free = 0;
    first_alloc(0, NULL)->total = to_alloc - METADATA_SIZE;
    first_alloc(0, NULL)->size = size;
    first_alloc(0, NULL)->ptr = first_alloc(0, NULL)->data;
    first_alloc(0, NULL)->prev = first_alloc(0, NULL);
    first_alloc(0, NULL)->next = first_alloc(0, NULL);
    if (first_alloc(0, NULL)->total >= ALIGN(size) + METADATA_SIZE + ALIGN(1))
        split(first_alloc(0, NULL),
            (void *)(first_alloc(0, NULL)->data + ALIGN(size)));
    return (first_alloc(0, NULL)->data);
}

void *malloc(size_t size)
{
    metadata_t *ptr;

    if (!size)
        return (NULL);
    if (!first_alloc(0, NULL))
        return (new_allocation(size));
    ptr = get_available_zone(size);
    if (ptr)
        return (alloc_on_zone(ptr, size));
    else
        return (init_alloc(size));
}