/*
** EPITECH PROJECT, 2018
** cpp_d01_2018
** File description:
** main.c
*/

#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>
#include "bitmap.h"
#include "menger.h"

static int create_bitmap_from_buffer(char const *file, size_t size,
unsigned int *buffer)
{
    int fd = open(file, O_CREAT | O_TRUNC | O_WRONLY, 0644);

    if (fd < 0)
        return (84);
    write_bmp_header(fd, size);
    write_bmp_info_header(fd, size);
    write(fd, buffer, size * size * sizeof(*buffer));
    close(fd);
    return (0);
}

static void init_image(size_t size, unsigned int *buffer, unsigned int **img)
{
    memset(buffer, 0, size * size * sizeof (* buffer));
    for (size_t i = 0; i < size; ++i)
        img[i] = buffer + i * size;
}

static int menger_face(char const *file, int size, int level)
{
    unsigned int *buffer = malloc(size * size * sizeof(*buffer));
    unsigned int **img = malloc(size * sizeof(*img));

    if (!buffer || !img)
        return (84);
    init_image(size, buffer, img);
    menger(size, level, img);
    return (create_bitmap_from_buffer(file, size, buffer));
}

int main(int ac, char const **av)
{
    int size;
    int level;

    if (ac != 4) {
        write(2, "menger_face file_name size level\n", 33);
        return (84);
    } else if (!is_nb_valid(av[2]) || !is_nb_valid(av[3])) {
        write(2, "invalid numbers.\n", 17);
        return (84);
    }
    size = my_get_nbr(av[2]);
    level = my_get_nbr(av[3]);
    if (size < my_pow(level, 3) || size <= 0) {
        write(2, "size too small.\n", 17);
        return (84);
    }
    return (menger_face(av[1], size, level));
}