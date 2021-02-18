/*
** EPITECH PROJECT, 2017
** printf_o.c
** File description:
** print an unisgned int in octal base
*/

#include <stdarg.h>
#include <unistd.h>

int printf_octal(va_list list)
{
	int chars = 0;
	char *base = "01234567";
	char c;
	unsigned int nbr = va_arg(list, unsigned int);
	unsigned int i = 1;
	unsigned int digit;

	while (nbr / i >= 8)
		i = i * 8;
	while (i > 0) {
		digit = nbr / i % 8;
		c = base[digit];
		write(1, &c, 1);
		i = i / 8;
		chars++;
	}
	return (chars);
}
