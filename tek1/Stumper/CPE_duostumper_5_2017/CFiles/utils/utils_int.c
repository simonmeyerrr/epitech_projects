/*
** EPITECH PROJECT, 2017
** hangman
** File description:
** utils_int.c
*/

#include <stdlib.h>

int my_get_nbr(char *str)
{
	int nb = 0;
	int sign = 1;
	int i = 0;

	for (i = i ; str && (str[i] == '-' || str[i] == '+') ; i++)
		sign = (str[i] == '-') ? (-sign) : (sign);
	for (i = i ; str && str[i] >= '0' && str[i] <= '9' ; i++)
		nb = nb * 10 + str[i] - '0';
	return (sign * nb);
}

int is_nb_valid(char *str)
{
	int i = 0;

	for (i = i ; str && (str[i] == '-' || str[i] == '+') ; i++);
	for (i = i ; str && str[i] >= '0' && str[i] <= '9' ; i++);
	if (!str || str[i] != '\0')
		return (0);
	return (1);
}
