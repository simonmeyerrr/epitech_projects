/*
** EPITECH PROJECT, 2017
** concat_params.c
** File description:
** concatenates arguments
*/

#include <stdlib.h>

char *concat_params(int argc, char **argv)
{
	int length = 0;
	char *str;
	int pos = 0;

	for (int i = 0 ; i < argc ; i++)
		length = length + my_strlen(argv[i]);
	str = malloc(sizeof(char) * (length + argc));
	for (int i = 0 ; i < argc ; i++) {
		for (int j = 0 ; argv[i][j] != '\0' ; j++) {
			str[pos] = argv[i][j];
			pos++;
		}
		str[pos] = '\n';
		pos++;
	}
	str[pos - 1] = '\0';
	return (str);
}
