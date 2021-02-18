/*
** EPITECH PROJECT, 2017
** my_rpg
** File description:
** get_string.c
*/

#include "all.h"

int my_get_second_number(char *str)
{
	int nb = 0;
	int i = 0;

	for (i ; str && str[i] >= '0' && str[i] <= '9' ; i++);
	for (i ; str && (str[i] < '0' || str[i] > '9') ; i++);
	for (i ; str && str[i] >= '0' && str[i] <= '9' ; i++)
		nb = nb * 10 + str[i] - '0';
	return (nb);
}

int my_get_nbr(char *str)
{
	int nb = 0;

	for (int i = 0 ; str && str[i] >= '0' && str[i] <= '9' ; i++)
		nb = nb * 10 + str[i] - '0';
	return (nb);
}

char *my_append(char *origin, char *add, int free)
{
	int j = 0;
	char *dest = malloc(sizeof(char) * my_strlen(origin) +
	my_strlen(add) + 1);

	if (!dest)
		return (NULL);
	for (int i = 0 ; origin && origin[i] != '\0'; i++) {
		dest[j] = origin[i];
		j++;
	}
	for (int i = 0 ; add && add[i] != '\0' ; i++) {
		dest[j] = add[i];
		j++;
	}
	dest[j] = '\0';
	if (free == 1 || free == 3)
		my_free(origin);
	if (free == 2 || free == 3)
		my_free(add);
	return (dest);
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

char *hiden_pass(char *str)
{
	int len = my_strlen(str);
	char *new = malloc(sizeof(char) * (len + 1));

	if (!new)
		return (NULL);
	for (int i = 0 ; i < len ; i++)
		new[i] = '*';
	new[len] = '\0';
	return (new);
}
