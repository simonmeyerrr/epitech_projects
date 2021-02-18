/*
** EPITECH PROJECT, 2017
** nblen.c
** File description:
** return len of the number
*/

#include "../include/all.h"

int nblen(char *str, int i)
{
	int len = 0;

	while (str[i] >= '0' && str[i] <= '9') {
		i++;
		len++;
	}
	return (len);
}
