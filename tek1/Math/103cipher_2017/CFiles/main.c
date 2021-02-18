/*
** EPITECH PROJECT, 2017
** 103cipher
** File description:
** main.c
*/

#include "all.h"

static void error_management(int ac, char** av)
{
	/* Disp usage */
	if (ac == 2 && strcmp(av[1], "-h") == 0) {
		printf("USAGE:\n\t./103cipher message key flag\n\n\tmessage\t");
		printf("\ta message, made of ASCII characters\n\tkey\t\tthe e");
		printf("ncryption key, made of ASCII characters\n\tflag\t\t0 ");
		printf("for the message to be encrypted, 1 to be decrypted\n");
		exit (EXIT_SUCCESS);
	/* Check number of argument */
	} else if (ac != 4) {
		write(2, "Wrong number of argument\n", 25);
		exit (EXIT_ERROR);
	/* Check the flag of decrypting/encrypting */
	} else if (strcmp(av[3], "1") != 0 && strcmp(av[3], "0") != 0) {
		write(2, "Invalid flag\n", 13);
		exit (EXIT_ERROR);
	/* Check the string to be decrypted */
	} else if (strcmp(av[2], "1") == 0) {
		for (int i = 0 ; av[1][i] != '\0' ; i++) {
			if ((av[1][i] < '0' || av[1][i] > '9') && av[1][i] != ' ')
				exit (EXIT_ERROR);
		}
	}
}

int main(int ac, char **av)
{
	error_management(ac, av);
	if (strcmp(av[3], "0") == 0)
		encrypt(av[1], av[2]);
	else
		decrypt(av[1], av[2]);
	return (EXIT_SUCCESS);
}
