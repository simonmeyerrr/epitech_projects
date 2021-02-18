/*
** EPITECH PROJECT, 2017
** my_cook
** File description:
** string.c
*/

#include "all.h"

char *int_to_str(int nb)
{
	int len = 1;
	int nb2 = nb / 10;
	char *str;

	while (nb2 > 0) {
		nb2 = nb2 / 10;
		len++;
	}
	str = malloc(sizeof(char) * (len + 1));
	str[len] = '\0';
	str[0] = '0';
	for (int i = len - 1 ; nb > 0 ; i--) {
		str[i] = nb % 10 + '0';
		nb = nb / 10;
	}
	return (str);
}

char *time_to_str(double time)
{
	int full = time;
	char *str = my_strdup("0:00");

	while (full >= 60) {
		full -= 60;
		str[0] = str[0] + 1;
	}
	str[2] = full / 10 + '0';
	str[3] = full % 10 + '0';
	return (str);
}
