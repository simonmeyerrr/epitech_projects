/*
** EPITECH PROJECT, 2017
** getnb
** File description:
** r
*/

#include "../include/all.h"

int my_getnbr(char *str)
{
	int sign = 1;
	int nb = 0;
	int i = 0;

	while (str[i] == '-' || str[i] == '+')
		i = i + 1;
	if (str[i - 1] == '-')
		sign = -1;
	while ((str[i] >= '0' && str[i] <= '9') && str[i] != '\0') {
		nb = nb * 10;
		nb = nb + str[i] - 48;
		i = i + 1;
	}
	if (sign == -1)
		return (nb * -1);
	else
		return (nb);
}
