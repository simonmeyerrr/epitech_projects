/*
** EPITECH PROJECT, 2018
** PSU_2018_nmobjdump
** File description:
** my_nm.h
*/
#ifndef PSU_2018_NMOBJDUMP_MY_NM_H
# define PSU_2018_NMOBJDUMP_MY_NM_H

# include <elf.h>

typedef struct my_elf_s {
    Elf64_Ehdr *ehdr;
    Elf64_Shdr *shdr;
    char *ptr;
    char *shstrtab;
    char *strtab;
} my_elf_t;

int my_nm(const char *file);
int prepare_elf(const char *file, my_elf_t *elf, void *buf);

#endif /* PSU_2018_NMOBJDUMP_MY_NM_H */
