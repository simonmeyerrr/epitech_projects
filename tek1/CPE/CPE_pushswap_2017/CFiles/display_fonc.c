/*
** EPITECH PROJECT, 2017
** my_pushswap
** File description:
** disp_fonc
*/

#include "../include/my.h"

int disp_ope(int space, char* str)
{
	if (space == 1)
		write(1, " ", 1);
	else
		space = 1;
	my_putstr(str);
	return (space);
}

static int my_strlen(char *str)
{
	int len = 0;

	while (str[len] != '\0')
		len++;
	return (len);
}

void my_putstr(char *str)
{
	write(1, str, my_strlen(str));
}

int my_putnbr(int nb)
{
	char mod;

	if (nb == -2147483648) {
		my_putstr("-2147483648");
		return (0);
	}
	if (nb < 0) {
		write(1, "-", 1);
		nb = -nb;
	}
	mod = nb % 10 + '0';
	if (nb > 9) {
		my_putnbr(nb / 10);
	}
	write(1, &mod, 1);
	return (0);
}

void my_disp_list(my_list_t* begin)
{
	my_list_t* tmp = begin;

	while (tmp != NULL) {
		my_putnbr(tmp->nb);
		write(1, " ", 1);
		tmp = tmp->next;
	}
	write(1, "\n", 1);
}
