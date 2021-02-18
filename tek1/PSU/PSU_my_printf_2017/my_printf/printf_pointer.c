/*
** EPITECH PROJECT, 2017
** printf_p.c
** File description:
** print the pointer adress in hexadecimal base
*/

#include <stdarg.h>
#include <unistd.h>

int printf_pointer(va_list list)
{
	int chars = 2;
	char *base = "0123456789abcdef";
	char c;
	unsigned long nbr = va_arg(list, unsigned long);
	unsigned long i = 1;
	unsigned long digit;

	write(1, "0x", 2);
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
