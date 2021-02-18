/*
** EPITECH PROJECT, 2017
** lemin_2017
** File description:
** string2.c
*/

#include "../include/all.h"

int my_strlen(char *str)
{
	int len = 0;

	while (str && str[len])
		len++;
	return (len);
}

int my_get_nbr(char *str)
{
	int nb = 0;

	for (int i = 0 ; str && str[i] ; i++)
		nb = nb * 10 + str[i] - '0';
	return (nb);
}

void my_put_nbr(int nb)
{
	char mod = nb % 10 + '0';

	if (nb > 9)
		my_put_nbr(nb / 10);
	write(1, &mod, 1);
}
