/*
** EPITECH PROJECT, 2017
** putstr
** File description:
** oui
*/

#include "../include/all.h"

void my_putstr(char *str)
{
	int i = 0;

	while (str[i] != '\0') {
		my_putchar(str[i]);
		i++;
	}
}
