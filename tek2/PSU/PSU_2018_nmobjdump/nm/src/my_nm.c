/*
** EPITECH PROJECT, 2018
** PSU_2018_nmobjdump
** File description:
** my_nm.c
*/

#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <fcntl.h>
#include <stdio.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include "my_nm.h"

static int open_file(const char *file, void **buf)
{
    int fd = open(file, O_RDONLY);
    struct stat s;

    if (fd == -1 || fstat(fd, &s) == -1 || s.st_size == -1) {
        dprintf(2, "my_nm: '%s': %s\n", file, strerror(errno));
        close(fd);
        return (-1);
    }
    *buf = mmap(NULL, s.st_size, PROT_READ, MAP_PRIVATE, fd, 0);
    close(fd);
    if (*buf == (void *)-1) {
        dprintf(2, "my_nm: '%s': %s\n", file, strerror(errno));
        return (-1);
    }
    return (0);
}

int my_nm(const char *file)
{
    void *buf;
    my_elf_t elf;

    if (open_file(file, &buf) == -1)
        return (-1);
    if (prepare_elf(file, &elf, buf) == -1)
        return (-1);
    return (0);
}