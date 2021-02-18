/*
** EPITECH PROJECT, 2017
** printf_b.c
** File description:
** print an unisgned int in binary base
*/

#include <stdarg.h>
#include <unistd.h>

int printf_binary(va_list list)
{
	int chars = 0;
	char *base = "01";
	char c;
	unsigned int nbr = va_arg(list, unsigned int);
	unsigned int i = 1;
	unsigned int digit;

	while (nbr / i >= 2)
		i = i * 2;
	while (i > 0) {
		digit = nbr / i % 2;
		c = base[digit];
		write(1, &c, 1);
		i = i / 2;
		chars++;
	}
	return (chars);
}
