/*
** EPITECH PROJECT, 2017
** printf_S.c
** File description:
** print a string and octal non printable chars
*/

#include <stdarg.h>
#include <unistd.h>

static int printf_string_octal2(unsigned int c)
{
	char *base = "01234567";
	unsigned int i = 1;
	unsigned int digit;
	char a;

	write(1, "\\", 1);
	if (c < 8)
		write(1, "00", 2);
	else if (c < 64)
		write(1, "0", 1);
	while (c / i >= 8)
		i = i * 8;
	while (i > 0) {
		digit = c / i % 8;
		a = base[digit];
		write(1, &a, 1);
		i = i / 8;
	}
	return (4);
}

int printf_string_octal(va_list list)
{
	char *str = va_arg(list, char *);
	char c;
	int len = 0;

	for (int i = 0 ; str[i] != '\0' ; i++) {
		c = str[i];
		if (c > 31 && c < 127) {
			write(1, &c, 1);
			len++;
		} else {
			len = len + printf_string_octal2(c);
		}
	}
	return (len);
}
