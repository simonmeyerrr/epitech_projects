/*
** EPITECH PROJECT, 2017
** div
** File description:
** div
*/

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include "all.h"

int check_value(char *a, char *b)
{
	int i = 0;
	int ret = 0;

	while (a[i] != '\0' || b[i] != '\0') {
		if (a[i] != '\0' && b[i] == '\0')
			ret = 1;
		if (a[i] > b[i])
			ret = 1;
		i++;
	}
	return (ret);
}

int calc_div(char *a, char *b)
{
	int alen = my_strlen(a);
	int blen = my_strlen(b);
	char *divid = a;
	int quot = 0;


	if (check_value(a, b) == 2) {
		quot = 0;
	} else if (alen > blen) {
		while (check_value(a, b) == 1) {
			divid = calc_sub(divid, b);
			quot += 1;
		}
	}
	return (quot);
}
