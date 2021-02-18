/*
** EPITECH PROJECT, 2017
** my_printf.c
** File description:
** reproduce printf command
*/

#include <stdarg.h>
#include <unistd.h>
#include <stdio.h>

int printf_pourcent(va_list);
int printf_string(va_list);
int printf_character(va_list);
int printf_int(va_list);
int printf_octal(va_list);
int printf_little_hexa(va_list);
int printf_big_hexa(va_list);
int printf_binary(va_list);
int printf_pointer(va_list);
int printf_unsigned_int(va_list);
int printf_string_octal(va_list);

int print_special(char *str, int i, int *chars, va_list list)
{
	char flags[12] = {'%', 's', 'c', 'd', 'i', 'o', 'x', 'X', 'b', 'p',
	'u', 'S'};
	int (*tab[12])(va_list) = {printf_pourcent, printf_string,
	printf_character, printf_int, printf_int, printf_octal,
	printf_little_hexa, printf_big_hexa, printf_binary, printf_pointer,
	printf_unsigned_int, printf_string_octal};

	for (int j = 0 ; j < 12 ; j++) {
		if (str[i] == flags[j]) {
			*chars = *chars + tab[j](list);
			return (i);
		}
	}
	return (i);
}

int my_printf(char *str, ...)
{
	char c;
	va_list list;
	int chars = 0;

	va_start(list, str);
	for (int i = 0 ; str[i] != '\0' ; i++) {
		if (str[i] == '%' && str[i + 1] != '\0') {
			i = print_special(str, i + 1, &chars, list);
		} else if (str[i] != '%'){
			c = str[i];
			write(1, &c, 1);
			chars++;
		}
	}
	va_end(list);
	return (chars);
}
