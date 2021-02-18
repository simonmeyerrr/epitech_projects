/*
** EPITECH PROJECT, 2018
** PSU_2018_malloc
** File description:
** malloc.h
*/

#ifndef PSU_2018_MALLOC_MALLOC_H_
# define PSU_2018_MALLOC_MALLOC_H_

#include <stdio.h>
# include <unistd.h>

typedef struct metadata_s {
    int free;
    size_t size;
    size_t total;
    void *ptr;
    struct metadata_s *prev;
    struct metadata_s *next;
    char data[1];
} metadata_t;

# define ALIGN(size)    ((((size - 1) >> 2) << 2) + 4)
# define METADATA_SIZE  (48)
# define PAGE_SIZE      getpagesize()

void *malloc(size_t size);
void *realloc(void *ptr, size_t size);
void free(void *ptr);
void show_alloc_mem(void);
metadata_t *get_metadata(void *ptr);
void split(metadata_t *old, metadata_t *new_alloc);
metadata_t *first_alloc(int type, void *set);

#endif /* PSU_2018_MALLOC_MALLOC_H_ */
