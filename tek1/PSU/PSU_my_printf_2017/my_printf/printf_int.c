/*
** EPITECH PROJECT, 2017
** printf_d.c
** File description:
** print an int
*/

#include <stdarg.h>
#include <unistd.h>

static int disp_int(int nb, int *chars)
{
	char c;

	if (nb == -2147483648) {
		write(1, "-2147483648", 11);
		*chars = 11;
		return (0);
	}
	if (nb < 0) {
		write(1, "-", 1);
		nb = -nb;
		*chars = 1;
	}
	if (nb > 9)
		disp_int(nb / 10, chars);
	c = nb % 10 + '0';
	write(1, &c, 1);
	*chars = *chars + 1;
	return (0);
}

int printf_int(va_list list)
{
	int chars = 0;

	disp_int(va_arg(list, int), &chars);
	return (chars);
}
