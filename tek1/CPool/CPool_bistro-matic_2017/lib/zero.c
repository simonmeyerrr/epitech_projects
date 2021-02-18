/*
** EPITECH PROJECT, 2017
** zero.c
** File description:
** add 0 to the number
*/

#include "../include/all.h"

char *put_zero2(char *newstr, char *oldstr, int little, int big)
{
	int i = 1;

	newstr[0] = oldstr[0];
	while (i <= (big - little)) {
		newstr[i] = '0';
		i++;
	}
	for (int j = 1 ; oldstr[j] != '\0' ; j++) {
		newstr[i] = oldstr[j];
		i = i + 1;
	}
	newstr[i] = '\0';
	return (newstr);
}

void put_zero(char **str1, char **str2)
{
	int len1 = my_strlen(*str1);
	int len2 = my_strlen(*str2);
	char *newstr;

	if (len1 == len2)
		return;
	if (len1 > len2) {
		newstr = malloc(sizeof(char) * (len1 + 1));
		newstr = put_zero2(newstr, *str2, len2, len1);
		*str2 = newstr;
	} else {
		newstr = malloc(sizeof(char) * (len2 + 1));
		newstr = put_zero2(newstr, *str1, len1, len2);
		*str1 = newstr;
	}
}
