/*
** EPITECH PROJECT, 2017
** my_compute_factorial_rec.c
** File description:
** factorial
*/

int my_compute_factorial_rec(int nb)
{
	if (nb == 0 || nb == 1)
		return (1);
	if (nb < 0)
		return (0);
	if (nb > 12)
		return (0);
	nb = nb * my_compute_factorial_rec(nb - 1);
	return (nb);
}
