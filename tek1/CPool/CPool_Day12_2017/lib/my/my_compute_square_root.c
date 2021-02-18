/*
** EPITECH PROJECT, 2017
** my_compute_square_root.c
** File description:
** square root
*/

int my_compute_square_root(int nb)
{
	if (nb <= 0)
		return (0);
	if (nb == 1)
		return (1);
	for (int i = 0 ; i < (nb / 2) + 1 ; i++) {
		if (i * i == nb)
			return (i);
	}
	return (0);
}
