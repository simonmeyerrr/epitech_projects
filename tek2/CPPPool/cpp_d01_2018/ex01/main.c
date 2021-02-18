/*
** EPITECH PROJECT, 2018
** cpp_d01_2018
** File description:
** main.c
*/

#include <unistd.h>
#include "menger.h"

int main(int ac, char const **av)
{
    int nb1;
    int nb2;

    if (ac != 3) {
        write(2, "2 arguments expected.\n", 22);
        return (84);
    } else if (!is_nb_valid(av[1]) || !is_nb_valid(av[2])) {
        write(2, "invalid arguments.\n", 19);
        return (84);
    }
    nb1 = my_get_nbr(av[1]);
    nb2 = my_get_nbr(av[2]);
    if (nb1 < my_pow(nb2, 3) || nb1 <= 0 || nb2 < 0) {
        write(2, "size too small.\n", 17);
        return (84);
    }
    menger(nb1, nb2);
    return (0);
}