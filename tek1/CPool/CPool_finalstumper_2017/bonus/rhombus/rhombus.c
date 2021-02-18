/*
** EPITECH PROJECT, 2017
** Triangle
** File description:
** Bonus rush3
*/

#include <unistd.h>
#include "my.h"

int my_getnbr(char *str)
{
	int i = 0;
	int res = 0;
	int isneg = 0;
	for (i; str[i] != '\0'; i++) {
		if ((str[i] >= 'a' && str[i] <= 'z') ||
			(str[i] >= 'A' && str[i] <= 'Z'))
			return 0;
		while (str[i] >= '0' && str[i] <= '9') {
			res = (res * 10) + (str[i] - '0');
			if (str[i - 1] == '-')
				isneg = 1;
			if (res == 214748364)
				return 0;
			i++;
		}
		if (res != 0) {
			if (isneg == 1)
				res = res * (-1);
			return res;
		}
	}
}

void rhombusinv(char *str, int space, int space2)
{
	for (int i = 0; i < my_getnbr(str) - 1; i++) {
		for (int i = 0; i < space; i++)
			my_putchar(' ');
		my_putchar('\\');
		for (int i = 0; i < space2; i++)
			my_putchar(' ');
		my_putchar('/');
		my_putchar('\n');
		space++;
		space2 = space2 - 2;
	}
	for (int i = 0; i < space; i++)
		my_putchar(' ');
	my_putchar('x');

}

void rhombus(char *str)
{
	int space = my_getnbr(str) - 1;
	int space2 = -1;
	for (int i = 0; i < my_getnbr(str); i++) {
		for (int i = 0; i < space; i++)
			my_putchar(' ');
		if (i != 0)
			my_putchar('/');
		else
			my_putchar('x');
		for (int i = 0; i < space2; i++)
			my_putchar(' ');
		if (i != 0)
			my_putchar('\\');
		my_putchar('\n');
		space--;
		space2 = space2 + 2;
	}
	space++;
	space2 = space2 - 2;
	rhombusinv(str, space, space2);
}

int main(int ac, char **av) {
	if (ac == 2 && av[1][0] != '-' && (my_getnbr(av[1]) != 1)) {
		rhombus(av[1]);
		my_putchar('\n');
	} else {
		write(2, "Invalid size !\n", 15);
		return(84);
	}
	return 0;
}
