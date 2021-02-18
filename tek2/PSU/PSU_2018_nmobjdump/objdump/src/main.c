/*
** EPITECH PROJECT, 2018
** PSU_2018_nmobjdump
** File description:
** main.c
*/

#include "my_objdump.h"

int main(int ac, const char **av)
{
    int error = 0;

    if (ac < 2) {
        error = (my_objdump("a.out") == 0 ? 0 : 84);
    } else {
        for (int i = 1; i < ac; i++) {
            error = (my_objdump(av[i]) == 0 ? 0 : 84);
        }
    }
    return (error);
}