/*
** EPITECH PROJECT, 2017
** my_print_digits.c
** File description:
** 
*/

int my_print_digits(void)
{
	int digits = '0';

	while (digits < 58) {
		my_putchar(digits);
		digits = digits + 1;
	}
	my_putchar('\n');
	return (0);
}
