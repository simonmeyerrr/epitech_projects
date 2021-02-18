/*
** EPITECH PROJECT, 2017
** my_print_params.c
** File description:
** display parameters
*/

int main(int argc, char **argv)
{
	for (int i = 0 ; i < argc ; i++) {
		my_putstr(argv[i]);
		my_putchar('\n');
	}
	return (0);
}
