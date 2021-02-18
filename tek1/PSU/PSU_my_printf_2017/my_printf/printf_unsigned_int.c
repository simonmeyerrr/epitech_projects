/*
** EPITECH PROJECT, 2017
** printf_u.c
** File description:
** print an unsigned int
*/

#include <stdarg.h>
#include <unistd.h>

static unsigned int disp_unsigned_int(unsigned int nb, int *chars)
{
	char c;

	if (nb > 9)
		disp_unsigned_int(nb / 10, chars);
	c = nb % 10 + '0';
	write(1, &c, 1);
	*chars = *chars + 1;
	return (0);
}

int printf_unsigned_int(va_list list)
{
	int chars = 0;

	disp_unsigned_int(va_arg(list, unsigned int), &chars);
	return (chars);
}
