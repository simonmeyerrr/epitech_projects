/*
** EPITECH PROJECT, 2018
** PSU_2018_nmobjdump
** File description:
** prepare_elf.c
*/

#include <string.h>
#include <stdio.h>
#include "my_nm.h"

static int is_header_valid(unsigned char *header)
{
    if (header[0] == 0x7F && header[1] == 0x45 && header[2] == 0x4C &&
        header[3] == 0x46)
        return (1);
    return (0);
}

static char *get_shstrtab(Elf64_Shdr *shtab, Elf64_Half strndx, char *ptr)
{
    if (strndx == SHN_UNDEF)
        return (NULL);
    return (ptr + shtab[strndx].sh_offset);
}

static char *get_strtab(my_elf_t *elf)
{
    char *shstrtab;

    shstrtab = elf->shstrtab;
    for (size_t i = 0; i < elf->ehdr->e_shnum; i++) {
        if (!strcmp(&shstrtab[elf->shdr[i].sh_name], ".strtab"))
            return (elf->ptr + elf->shdr[i].sh_offset);
    }
    return (NULL);
}

int prepare_elf(const char *file, my_elf_t *elf, void *buf)
{
    elf->ehdr = buf;
    elf->ptr = buf;
    if (!is_header_valid(elf->ehdr->e_ident)) {
        dprintf(2, "my_nm: '%s': File format not recognized\n", file);
        return (-1);
    } else if (elf->ehdr->e_ident[EI_CLASS] == ELFCLASS32) {
        dprintf(2, "my_nm: '%s': Format 32 not handled\n", file);
        return (-1);
    }
    elf->shdr = (Elf64_Shdr * )(elf->ptr + elf->ehdr->e_shoff);
    elf->shstrtab = get_shstrtab(elf->shdr, elf->ehdr->e_shstrndx, elf->ptr);
    if (!elf->shstrtab) {
        dprintf(2, "my_nm: '%s': Error\n", file);
        return (-1);
    }
    elf->strtab = get_strtab(elf);
    if (!elf->strtab) {
        dprintf(2, "my_nm: '%s': Error\n", file);
        return (-1);
    }
    return (0);
}