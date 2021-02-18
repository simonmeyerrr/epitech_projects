/*
** EPITECH PROJECT, 2017
** tetris
** File description:
** string.c
*/

#include "../include/all.h"

int my_strlen(char *str)
{
	int len = 0;

	while (str && str[len])
		len++;
	return (len);
}

void my_put_nbr(int nb)
{
	char mod;

	if (nb < 0) {
		write(1, "-", 1);
		nb = -nb;
	}
	if (nb > 9)
		my_put_nbr(nb / 10);
	mod = nb % 10 + '0';
	write(1, &mod, 1);
}

void my_putstr_fd(char *str, int fd)
{
	write(fd, str, my_strlen(str));
}

char *my_strdup(char *str)
{
	int len = my_strlen(str);
	char *new = malloc(sizeof(char) * (len + 1));

	verif_malloc(new);
	for (int i = 0 ; i < len ; i++)
		new[i] = str[i];
	new[len] = '\0';
	return (new);
}

int my_strcmp(char *s1, char *s2)
{
	int i = 0;

	if (!s1 && !s2)
		return (0);
	if (!s1 || !s2)
		return (1);
	while (s1[i] && s2[i] && s1[i] == s2[i])
		i++;
	return (s1[i] - s2[i]);
}
