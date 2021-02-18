/*
** EPITECH PROJECT, 2017
** printf_xX.c
** File description:
** print an unisgned int in hexadecimal base
*/

#include <stdarg.h>
#include <unistd.h>

int printf_little_hexa(va_list list)
{
	int chars = 0;
	char *base = "0123456789abcdef";
	char c;
	unsigned int nbr = va_arg(list, unsigned int);
	unsigned int i = 1;
	unsigned int digit;

	while (nbr / i >= 16)
		i = i * 16;
	while (i > 0) {
		digit = nbr / i % 16;
		c = base[digit];
		write(1, &c, 1);
		i = i / 16;
		chars++;
	}
	return (chars);
}

int printf_big_hexa(va_list list)
{
	int chars = 0;
	char *base = "0123456789ABCDEF";
	char c;
	unsigned int nbr = va_arg(list, unsigned int);
	unsigned int i = 1;
	unsigned int digit;

	while (nbr / i >= 16)
		i = i * 16;
	while (i > 0) {
		digit = nbr / i % 16;
		c = base[digit];
		write(1, &c, 1);
		i = i / 16;
		chars++;
	}
	return (chars);
}
