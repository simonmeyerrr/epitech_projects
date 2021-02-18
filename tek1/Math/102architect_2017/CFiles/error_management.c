/*
** EPITECH PROJECT, 2017
** 102architect
** File description:
** error management
*/

#include "all.h"

int float_valid(char *str)
{
	int i = 0;
	int dot = 0;

	if (str[0] == '-')
		i = 1;
	while (str[i] != '\0') {
		if (str[i] < '0' || str[i] > '9') {
			if (str[i] == '.' && dot == 0)
				dot = 1;
			else
				return (1);
		}
		i++;
	}
	return (0);
}

int error_management(int ac, char **av)
{

/* Si le nombre d'arguments est invalide */

	if (ac < 4)
		return (1);

/* Si les coordonnées du point sont invalide. Lettres, 2 virgules, ... */

	if (float_valid(av[1]) != 0 || float_valid(av[2]) != 0)
		return (1);

/* On regarde si tous les arguments sont valides, bon nombre d'argulents pour certains flags,  */

	for (int i = 3 ; i < ac ; i++) {
		if (strcmp(av[i], "-h") == 0 || strcmp(av[i], "-t") == 0) {
			if (i + 2 >= ac)
				return (1);
			i = i + 1;
			if (float_valid(av[i]) != 0 || float_valid(av[i + 1]) != 0)
				return (1);
			i = i + 1;
		}
		else if (strcmp(av[i], "-r") == 0) {
			if (i + 1 >= ac)
				return (1);
			i = i + 1;
			if (float_valid(av[i]) != 0)
				return (1);
			if (atof(av[i]) >= 360)
				return (1);
		}
		else if (strcmp(av[i], "-s") == 0) {
			if (i + 1 >= ac)
				return (1);
			i = i + 1;
			if (float_valid(av[i]) != 0)
				return (1);
			if (atof(av[i]) >= 360)
				return (1);
		}
		else
			return (1);
	}
	return (0);
}
