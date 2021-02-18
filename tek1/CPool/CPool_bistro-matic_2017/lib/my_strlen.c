/*
** EPITECH PROJECT, 2017
** strlen
** File description:
** oui
*/

#include "../include/all.h"

int my_strlen(char *str)
{
	int i = 0;

	while (str[i] != '\0')
		i++;
	return (i);
}
