/*
** EPITECH PROJECT, 2018
** PSU_2018_malloc
** File description:
** show_alloc_mem.c
*/

#include "../include/malloc.h"

static void my_putstr(char *str)
{
    int len = 0;

    while (str && str[len])
        len++;
    write(1, str, len);
}

static void show_pointer(void *ptr)
{
    char *base = "0123456789ABCDEF";
    unsigned long nbr = (unsigned long)ptr;
    unsigned long i = 1;
    unsigned long digit;

    my_putstr("0x");
    while (nbr / i >= 16)
        i = i * 16;
    while (i > 0) {
        digit = nbr / i % 16;
        write(1, &base[digit], 1);
        i = i / 16;
    }
}

static void show_bytes(size_t nbr)
{
    char *base = "0123456789";
    unsigned long i = 1;
    unsigned long digit;

    while (nbr / i >= 10)
        i = i * 10;
    while (i > 0) {
        digit = nbr / i % 10;
        write(1, &base[digit], 1);
        i = i / 10;
    }
    my_putstr(" bytes\n");
}

static void show_alloc(metadata_t *data)
{
    if (data->free)
        return;
    show_pointer(data->data);
    my_putstr(" - ");
    show_pointer(data->data + data->size);
    my_putstr(" : ");
    show_bytes(data->size);
}

void show_alloc_mem(void)
{
    metadata_t *tmp = first_alloc(0, NULL);

    my_putstr("break : ");
    show_pointer(sbrk(0));
    my_putstr("\n");
    if (tmp) {
        show_alloc(tmp);
        tmp = tmp->next;
    }
    while (tmp && tmp != first_alloc(0, NULL)) {
        show_alloc(tmp);
        tmp = tmp->next;
    }
}