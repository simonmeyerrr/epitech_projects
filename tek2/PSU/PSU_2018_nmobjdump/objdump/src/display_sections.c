/*
** EPITECH PROJECT, 2018
** PSU_2018_nmobjdump
** File description:
** display_section.c
*/

#include <ctype.h>
#include <string.h>
#include <stdio.h>
#include "my_objdump.h"

static int is_section_type_valid(my_elf_t *elf, int i)
{
    char *name;

    if (elf->shdr[i].sh_type == SHT_NOBITS)
        return (0);
    if (elf->shdr[i].sh_type == SHT_SYMTAB)
        return (0);
    if (!(elf->shstrtab[elf->shdr[i].sh_name]))
        return (0);
    name = &(elf->shstrtab)[elf->shdr[i].sh_name];
    if (!strcmp(".strtab", name))
        return (0);
    if (!strcmp(".rela.text", name))
        return (0);
    if (!strcmp(".rela.eh_frame", name))
        return (0);
    return (1);
}

static char print_byte(char b)
{
    printf("%02x", (unsigned char)b);
    return (isprint(b) ? b : '.');
}

static int print_line(size_t offset, char *section, Elf64_Shdr *shdr)
{
    int i = 0;
    char buf[17];

    memset(buf, ' ', 16);
    buf[16] = '\0';
    printf(" %04x ", (unsigned)(shdr->sh_addr + offset));
    for (int j = 0; i < 16 && offset + i < shdr->sh_size; j = 0) {
        for (j = j; j < 4 && offset + i + j < shdr->sh_size; j++)
            buf[i + j] = print_byte(section[offset + i + j]);
        for (j = j; j < 4; j++)
            printf("  ");
        i += j;
        printf(" ");
    }
    for (i = i; i < 16; i += 4)
        printf("         ");
    printf(" %s\n", buf);
    return (i);
}

static void display_section(Elf64_Shdr *shdr, char *section, char *name)
{
    size_t offset = 0;

    if (shdr->sh_size <= 0)
        return;
    printf("Contents of section %s:\n", name);
    while (offset < shdr->sh_size)
        offset += print_line(offset, section, shdr);
}

void display_sections(my_elf_t *elf)
{
    char *name;
    void *section;

    for (size_t i = 0; i < elf->ehdr->e_shnum; i++) {
        section = elf->ptr + elf->shdr[i].sh_offset;
        if (section == elf->shstrtab)
            return;
        else if (is_section_type_valid(elf, i)) {
            name = &(elf->shstrtab)[elf->shdr[i].sh_name];
            display_section(&(elf->shdr)[i], section, name);
        }
    }
}