/*
** EPITECH PROJECT, 2017
** hangman
** File description:
** utils_display.c
*/

#include <unistd.h>
#include "proto.h"

void my_putstr(char *str)
{
	write(1, str, my_strlen(str));
}

void my_put_err(char *str)
{
	write(2, str, my_strlen(str));
}

void my_put_nb(int nb)
{
	char mod;

	if (nb < 0) {
		write(1, "-", 1);
		nb = -nb;
	}
	mod = nb % 10 + '0';
	if (nb > 9)
		my_put_nb(nb / 10);
	write(1, &mod, 1);
}
