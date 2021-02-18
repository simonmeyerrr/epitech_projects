/*
** EPITECH PROJECT, 2017
** Lib
** File description:
** contient les fonctions réecrites
*/

#include <unistd.h>
#include "my.h"

void my_putchar(char c)
{
	write(1, &c, 1);
}

int my_put_nbr(int nb)
{
	int m;

	if (nb < 0) {
		my_putchar('-');
		nb = nb * (-1);
	}
	if (nb >= 0) {
		if (nb >= 10) {
			m = (nb % 10);
			nb = ((nb - m) / 10);
			my_put_nbr(nb);
			my_putchar(48 + m);
		} else {
			my_putchar(48 + nb % 10);
		}
	}
	return (0);
}

void displayrush(int rush, int x, int y)
{
	write(1, "[rush1-", 7);
	my_put_nbr(rush);
	write(1, "] ", 2);
	my_put_nbr(x);
	my_putchar(' ');
	my_put_nbr(y);
}
