/*
** EPITECH PROJECT, 2017
** my_put_nbr.c
** File description:
** 
*/

int too_high(int nb)
{
	my_putchar('2');
	my_putchar('1');
	my_putchar('4');
	my_putchar('7');
	my_putchar('4');
	my_putchar('8');
	my_putchar('3');
	my_putchar('6');
	my_putchar('4');
	if (nb == 2147483647) {
		my_putchar('7');
	} else {
		my_putchar('8');
	}
	return (0);
}

int my_put_nbr(int nb)
{
	int modulo;

	if (nb < 0) {
		nb = nb * -1;
		my_putchar('-');
	}
	if (nb < 2147483647) {
		if (nb >= 10) {
			modulo = nb % 10;
			nb = (nb - modulo) / 10;
			my_put_nbr(nb);
			my_putchar(48 + modulo);
		} else {
			my_putchar(48 + nb);
		}
	} else {
		too_high(nb);
	}
	return (0);
}
