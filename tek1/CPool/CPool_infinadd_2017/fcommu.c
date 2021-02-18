/*
** EPITECH PROJECT, 2017
** infin_add
** File description:
** commun fonctions
*/

#include <stdlib.h>
#include <unistd.h>
#include "include/proto.h"

int my_strlen(char *str)
{
	int len = 0;
	for (int i = 0 ; str[i] != '\0' ; i++)
		len++;
	return (len);
}

int nb_isvalid(char *str)
{
	if (str[0] < '0' || str[0] > '9') {
		if (str[0] != '-')
			return (0);
		if (str[0] == '-' && (str[1] > '9' || str[1] < '0'))
			return (0);
	}
	for (int i = 1 ; str[i] != '\0' ; i++) {
		if (str[i] < '0' || str[i] > '9')
			return (0);
	}
	return (1);
}

void my_putrevstr(char *str)
{
	int i = my_strlen(str);

	while (i >= 0) {
		write(1, &str[i], 1);
		i--;
	}
	write(1, "\n", 1);
}

int longer_str(char *s1, char *s2)
{
	if (my_strlen(s1) > my_strlen(s2))
		return (my_strlen(s1));
	return (my_strlen(s2));
}
