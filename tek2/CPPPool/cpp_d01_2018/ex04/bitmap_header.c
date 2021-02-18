/*
** EPITECH PROJECT, 2018
** cpp_d01_2018
** File description:
** bitmap_header.c
*/

#include <stddef.h>
#include <unistd.h>
#include "bitmap.h"

static void make_bmp_header(bmp_header_t *header , size_t size)
{
    uint16_t magic = 0x424D;
    void *ptr = &magic;
    char *tab = ptr;
    char tmp = tab[0];

    tab[0] = tab[1];
    tab[1] = tmp;
    header->magic = magic;
    header->size = size * size * 4 + 54;
    header->_app1 = 0;
    header->_app2 = 0;
    header->offset = 54;
}

void write_bmp_header(int fd, size_t size)
{
    bmp_header_t header;
    make_bmp_header(&header, size);
    write(fd, &header, sizeof(header));
}

static void make_bmp_info_header(bmp_info_header_t *header , size_t size)
{
    header->size = 40;
    header->width = size;
    header->height = size;
    header->planes = 1;
    header->bpp = 32;
    header->compression = 0;
    header->raw_data_size = size * size * 4;
    header->h_resolution = 0;
    header->v_resolution = 0;
    header->palette_size = 0;
    header->important_colors = 0;
}

void write_bmp_info_header(int fd, size_t size)
{
    bmp_info_header_t info;
    make_bmp_info_header(&info, size);
    write(fd, &info, sizeof(info));
}