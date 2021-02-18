/*
** EPITECH PROJECT, 2017
** my_find_prime_sup.c
** File description:
** find prime
*/

int my_find_prime_sup(int nb)
{
	while (my_is_prime(nb) != 1) {
		nb++;
	}
	return (nb);
}
