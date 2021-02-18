/*
** EPITECH PROJECT, 2017
** my_is_prime.c
** File description:
** prime
*/

int my_is_prime(int nb)
{
	if (nb <= 1)
		return (0);
	for (int i = 2 ; i < nb / 2 + 1 ; i++) {
		if (nb % i == 0)
			return (0);
	}
	return (1);
}
