/*
** EPITECH PROJECT, 2017
** my_compute_factorial_it.c
** File description:
** factorial
*/

int my_compute_factorial_it(int nb)
{
	int factoriel = 1;
	int i;

	if (nb < 0)
		return (0);
	if (nb > 12)
		return (0);
	for ( i = 1 ; i <= nb ; i++) {
		factoriel = factoriel * i;
	}
	return (factoriel);
}
