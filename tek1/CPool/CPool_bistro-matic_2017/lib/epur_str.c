/*
** EPITECH PROJECT, 2017
** epur
** File description:
** lib
*/

#include "../include/all.h"

char *epur_str(char *str)
{
	char *epur;
	int i = 0;
	int j = 0;

	epur = malloc(sizeof(char) * (my_strlen(str) + 1));
	while (str[i] == ' ' || str[i] == '\t')
		i++;
	while (str[i] != '\0') {
		if (str[i] != ' ' || (str[i] == ' ' && str[i + 1] != ' ')) {
			epur[j] = str[i];
			j++;
		}
		i++;
	}
	epur[j] = '\0';
	return (epur);
}
