/*
** EPITECH PROJECT, 2017
** infinadd
** File description:
** add pos
*/

#include <stdio.h>
#include <stdlib.h>
#include "include/proto.h"

int place_last(char *str, int last)
{
	while ((str[last] == '0' || str[last] == '\0') && last > 0)
		last--;
	return (last + 1);
}

void prep_add(char **s1, char **s2)
{
	char *swap;

	if (*s1[0] == '-')
		*s1[0] = '0';
	if (*s2[0] == '-')
		*s2[0] = '0';
	if (my_strlen(*s1) < my_strlen(*s2)) {
		swap = *s1;
		*s1 = *s2;
		*s2 = swap;
	}
}

char *add_pos2(char *s1, char *str, int *var)
{
	while (var[0] >= 0) {
		if (s1[var[0]] + var[3] - 48 > 9)
			str[var[2]] = s1[var[0]] + var[3] - 10;
		else
			str[var[2]] = s1[var[0]] + var[3];
		if (s1[var[0]] + var[3] - 48 > 9)
			var[3] = 1;
		else
			var[3] = 0;
		var[0] = var[0] - 1;
		var[2] = var[2] + 1;
	}
	if (var[3] == 1) {
		str[var[2]] = '1';
		var[2] = var[2] + 1;
	}
	str[var[2]] = '\0';
	var[2] = place_last(str, var[2]);
	str[var[2]] = '\0';
	return (str);
}

char *add_pos(char *s1, char *s2)
{
	int var[] = {0, 0, 0, 0};
	char *str = malloc(sizeof(char) * (longer_str(s1, s2) + 2));

	prep_add(&s1, &s2);
	var[0] = my_strlen(s1) - 1;
	var[1] = my_strlen(s2) - 1;
	while (var[1] >= 0) {
		if (s1[var[0]] + s2[var[1]] + var[3] - 96 > 9)
			str[var[2]] = s1[var[0]] + s2[var[1]] + var[3] - 58;
		else
			str[var[2]] = s1[var[0]] + s2[var[1]] + var[3] - 48;
		if (s1[var[0]] + s2[var[1]] + var[3] - 96 > 9)
			var[3] = 1;
		else
			var[3] = 0;
		var[0] = var[0] - 1;
		var[1] = var[1] - 1;
		var[2] = var[2] + 1;
	}
	str = add_pos2(s1, str, var);
	return (str);
}
