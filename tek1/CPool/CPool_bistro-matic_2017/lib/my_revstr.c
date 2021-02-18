/*
** EPITECH PROJECT, 2017
** revstr
** File description:
** oui
*/

#include "../include/all.h"

char *my_revstr(char *str)
{
	char tmp;
	int i = 0;
	int j = my_strlen(str) - 1;

	while (j > i) {
		tmp = str[i];
		str[i] = str[j];
		str[j] = tmp;
		i++;
		j--;
	}
	return (str);
}
