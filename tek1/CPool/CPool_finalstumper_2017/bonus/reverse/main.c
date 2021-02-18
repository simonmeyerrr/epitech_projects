/*
** EPITECH PROJECT, 2017
** main.c
** File description:
** reverse an outpout
*/

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "my.h"
#define BUFF_SIZE (4096)

void reverse(char *str)
{
	int tablen = 0;
	char **tab = my_str_to_strtab(str);
	int beg = 0;
	char *swap;

	while (tab[tablen] != NULL)
		tablen++;
	for (int end = tablen -1 ; beg < end ; beg++) {
		swap = tab[beg];
		tab[beg] = tab[end];
		tab[end] = swap;
		end--;
	}
	disptab(tab);
}

int main(void)
{
	char buff[BUFF_SIZE + 1];
	int offset;
	int len;

	offset = 0;
	while ((len = read(0, buff + offset, BUFF_SIZE - offset)) > 0)
		offset = offset + len;
	buff[offset] = '\0';
	if (len < 0)
		return (84);
	reverse(buff);
	return (0);
}
