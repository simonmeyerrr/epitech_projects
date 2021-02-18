/*
** EPITECH PROJECT, 2017
** my_compute_power_rec.c
** File description:
** power
*/

int my_compute_power_rec(int nb, int p)
{
	if (p < 0)
		return (0);
	if (p == 0)
		return (1);
	nb = nb * my_compute_power_rec(nb, p - 1);
	if (nb > 2147483647 || nb < -2147483648)
		return (0);
	return (nb);
}
