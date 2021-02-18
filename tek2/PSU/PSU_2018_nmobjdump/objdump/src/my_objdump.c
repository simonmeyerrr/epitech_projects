/*
** EPITECH PROJECT, 2018
** PSU_2018_nmobjdump
** File description:
** my_objdump.c
*/

#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <fcntl.h>
#include <stdio.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include "my_objdump.h"

static int open_file(const char *file, void **buf)
{
    int fd = open(file, O_RDONLY);
    struct stat s;

    if (fd == -1 || fstat(fd, &s) == -1 || s.st_size == -1) {
        dprintf(2, "my_objdump: '%s': %s\n", file, strerror(errno));
        close(fd);
        return (-1);
    }
    *buf = mmap(NULL, s.st_size, PROT_READ, MAP_PRIVATE, fd, 0);
    close(fd);
    if (*buf == (void *)-1) {
        dprintf(2, "my_objdump: '%s': %s\n", file, strerror(errno));
        return (-1);
    }
    return (0);
}

static void display_flags(unsigned long flags)
{
    (void)flags;
}

static void display_header(my_elf_t *elf, const char *file)
{
    printf("\n");
    printf("%s:     file format elf64-x86-64\n", file);
    printf("architecture: i386:x86-64, flags 0x%08x:\n", elf->ehdr->e_flags);
    display_flags(elf->ehdr->e_flags);
    printf("start address 0x%016lx\n", elf->ehdr->e_entry);
    printf("\n");
}

int my_objdump(const char *file)
{
    void *buf;
    my_elf_t elf;

    if (open_file(file, &buf) == -1)
        return (-1);
    if (prepare_elf(file, &elf, buf) == -1)
        return (-1);
    display_header(&elf, file);
    display_sections(&elf);
    return (0);
}