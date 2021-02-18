/*
** EPITECH PROJECT, 2017
** my_print_alpha.C
** File description:
** 
*/

int my_print_alpha(void)
{
	char letter = 97;

	while (letter < 123) {
		my_putchar(letter);
		letter = letter + 1;
	}
	my_putchar('\n');
	return (0);
}
