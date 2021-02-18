/*
** EPITECH PROJECT, 2017
** info_file
** File description:
** disp_fonc.c
*/

#include "all.h"

char *my_get_name(char *str)
{
	for (int i = 0 ; str[i] != '\0' ; i++) {
		if (str[i] == '/' && str[i + 1] != '\0') {
			str = str + i + 1;
			i = 0;
		}
	}
	return (str);
}

void my_putstr(char *str)
{
	char c;

	for (int i = 0 ; str[i] != '\0' ; i++) {
		c = str[i];
		write(1, &c, 1);
	}
}

long int my_put_nbr(long int nb)
{
	int mod;

	if (nb < 0) {
		write(1, "-", 1);
		nb = -nb;
	}
	mod = nb % 10 + '0';
	if (nb > 9)
		my_put_nbr(nb / 10);
	write(1, &mod, 1);
	return (0);
}
