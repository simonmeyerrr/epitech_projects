/*
** EPITECH PROJECT, 2017
** my_compute_power_it.c
** File description:
** power
*/

int my_compute_power_it(int nb, int p)
{
	int power = 1;

	if (p < 0)
		return (0);
	if (p == 0)
		return (1);
	for (int i = 1 ; i <= p ; i++) {
		power = power * nb;
	}
	if (power > 2147483647 || power < -2147483648)
		return (0);
	return (power);
}
