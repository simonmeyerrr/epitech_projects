/*
** EPITECH PROJECT, 2017
** infin_add
** File description:
** commun fonctions
*/

#include "all.h"

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

int longer_str(char *s1, char *s2)
{
	if (my_strlen(s1) > my_strlen(s2))
		return (my_strlen(s1));
	return (my_strlen(s2));
}
