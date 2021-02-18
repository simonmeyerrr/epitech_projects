/*
** EPITECH PROJECT, 2017
** infin_add
** File description:
** main
*/

#include "all.h"

char *infin_sub(char *s1, char *s2)
{
	char *str;
	char *result;
	int j = 1;
	char sign = s1[0];

	str = add_pos(s1, s2);
	result = malloc(sizeof(char) * (my_strlen(str) + 2));
	result[0] = '+';
	if (sign == '-')
		result[0] = '-';
	for (int i = my_strlen(str) - 1 ; i >= 0 ; i--) {
		result[j] = str[i];
		j++;
	}
	result[j] = '\0';
	return (result);
}

char *subinf(char *s1, char *s2)
{
	char *result;

	if ((s1[0] == '+' && s2[0] == '-') || (s1[0] == '-' && s2[0] == '+'))
		result = infin_sub(s1, s2);
	else
		result = redirection(s1, s2);
	return (result);
}
