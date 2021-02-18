/*
** EPITECH PROJECT, 2017
** printf_s.c
** File description:
** print a string
*/

#include <stdarg.h>
#include <unistd.h>

int printf_string(va_list list)
{
	char *str = va_arg(list, char *);
	char c;
	int len = 0;

	for (int i = 0 ; str[i] != '\0' ; i++) {
		c = str[i];
		write(1, &c, 1);
		len++;
	}
	return (len);
}
