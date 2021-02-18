/*
** EPITECH PROJECT, 2017
** my_hunter
** File description:
** nb_to_str
*/

#include "all.h"

char *five_to_str(int nb)
{
	char *str = my_strdup("00000");
	int len = 4;

	while (nb > 0 && len > 0) {
		str[len] = (nb % 10) + '0';
		nb = nb / 10;
		len--;
	}
	return (str);
}

char *two_to_str(int nb)
{
	char *str = my_strdup("00");

	str[1] = nb % 10 + '0';
	str[0] = nb / 10 % 10 + '0';
	return (str);
}

char *three_to_str(int nb)
{
	char *str = my_strdup("000");

	str[2] = nb % 10 + '0';
	str[1] = nb / 10 % 10 + '0';
	str[0] = nb / 100 % 10 + '0';
	return (str);
}

char *pc_to_str(float nb)
{
	char *str = my_strdup("000%");
	int int_nb = nb;
	float arr = nb / 10;
	int arr_int = nb;

	if (arr_int % 10 >= 5)
		int_nb++;
	str[2] = int_nb % 10 + '0';
	str[1] = int_nb / 10 % 10 + '0';
	str[0] = int_nb / 100 % 10 + '0';
	if (str[0] == '0')
		str[0] = ' ';
}
