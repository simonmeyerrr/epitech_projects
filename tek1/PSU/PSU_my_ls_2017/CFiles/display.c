/*
** EPITECH PROJECT, 2017
** my_ls
** File description:
** display.c
*/

#include "all.h"

char* create_path(char* s1, char* s2)
{
	char* str = malloc(sizeof(char*) * (my_strlen(s1) + my_strlen(s2) + 2));
	int i = 0;

	while (s1[i] != '\0') {
		str[i] = s1[i];
		i++;
	}
	if (str[i - 1] != '/') {
		str[i] = '/';
		i++;
	}
	for (int j = 0 ; s2[j] != '\0' ; j++) {
		str[i] = s2[j];
		i++;
	}
	str[i] = '\0';
	return (str);
}

int my_nbr_len(unsigned int nbr)
{
	int len = 0;

	for (nbr ; nbr > 0 ; nbr = nbr / 10)
		len++;
	return (len);
}

int my_putnbr(unsigned int nb)
{
	unsigned int mod = nb % 10 + '0';

	if (nb > 9)
		my_putnbr(nb / 10);
	write(1, &mod, 1);
	return (0);
}

int my_strlen(char* str)
{
	int len = 0;

	for (int i = 0 ; str[i] != '\0' ; i++) {
		len++;
	}
	return (len);
}

void my_putstr(char* str)
{
	write(1, str, my_strlen(str));
}
