/*
** EPITECH PROJECT, 2017
** printf_c.c
** File description:
** print a char
*/

#include <stdarg.h>
#include <unistd.h>

int printf_character(va_list list)
{
	char c = va_arg(list, int);

	write(1, &c, 1);
	return (1);
}
