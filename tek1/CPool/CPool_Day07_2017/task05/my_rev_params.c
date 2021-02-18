/*
** EPITECH PROJECT, 2017
** my_rev_params.c
** File description:
** display reverses parameters
*/

int main(int argc, char **argv)
{
	for(int i = argc - 1 ; i >= 0 ; i--) {
		my_putstr(argv[i]);
		my_putchar('\n');
	}
	return (0);
}
