/*
** EPITECH PROJECT, 2017
** strcmp
** File description:
** lib
*/

#include "../include/all.h"

int my_strcmp(char const *s1, char const *s2)
{
	int i = 0;

	while (s1[i] == s2[i] && s2[i] != '\0' && s1[i] != '\0')
		i++;
	if (s1[i] == '\0' && s2[i] == '\0')
		return (0);
	else
		return (s1[i] - s2[i]);
}
