/*
** EPITECH PROJECT, 2017
** my_print_revalpha.C
** File description:
** 
*/

int my_print_revalpha(void)
{
	char letter = 122;

	while (letter > 96) {
		my_putchar(letter);
		letter = letter - 1;
	}
	my_putchar('\n');
	return (0);
}
