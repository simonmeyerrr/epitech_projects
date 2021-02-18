/*
** EPITECH PROJECT, 2017
** matchstick
** File description:
** string.c
*/

#include "all.h"

int my_strlen(char *str)
{
	int len = 0;

	while (str && str[len] != '\0')
		len++;
	return (len);
}

void my_disp(char *str, int fd)
{
	if (!str || fd < 0)
		return;
	write(fd, str, my_strlen(str));
}

int my_getnbr(char *str)
{
	int nb = 0;
	int i = 0;

	while (str && str[i] >= '0' && str[i] <= '9') {
		nb = nb * 10 + str[i] - '0';
		i++;
	}
	if (str && str[i] != '\0')
		return (-1);
	return (nb);
}

void my_putnbr(int nb)
{
	int mod = nb % 10 + '0';

	if (nb > 9)
		my_putnbr(nb / 10);
	write(1, &mod, 1);
}
