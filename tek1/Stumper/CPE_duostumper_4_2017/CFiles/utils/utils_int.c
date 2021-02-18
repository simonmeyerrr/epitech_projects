/*
** EPITECH PROJECT, 2017
** mixword
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

char *int_to_str(int nb)
{
	int len = 1;
	char *str;

	for (int nb2 = nb / 10 ; nb2 > 0 ; nb2 = nb2 / 10)
		len++;
	str = malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	str[0] = '0';
	for (int i = len - 1 ; nb > 0 ; i--) {
		str[i] = nb % 10 + '0';
		nb = nb / 10;
	}
	str[len] = '\0';
	return (str);
}
