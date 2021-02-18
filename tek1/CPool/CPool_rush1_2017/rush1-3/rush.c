/*
** EPITECH PROJECT, 2017
** rush1-3
** File description:
** rush 1 assignement 3
*/

int only_b2(int x, int y)
{
	for (int i = 1 ; i <= x ; i++) {
		my_putchar('B');
	}
	my_putchar('\n');
	return (0);
}

int only_b(int x, int y)
{
	if (x == 1) {
		for (int i = 1 ; i <= y ; i++) {
			my_putchar('B');
			my_putchar('\n');
		}
	} else if (y == 1) {
		only_b2(x, y);
	}
	return (0);
}

int invalid_size(char *str)
{
	int i = 0;

	while (str[i] != '\0') {
		my_putchar(str[i]);
		i++;
	}
	my_putchar('\n');
	return (0);
}

int normal_display(int x, int y)
{
	my_putchar('A');
	for (int i = 2 ; i < x ; i++) {
		my_putchar('B');
	}
	my_putchar('A');
	my_putchar('\n');
	for (int j = 2 ; j < y ; j++) {
		my_putchar('B');
		for (int i = 2 ; i < x ; i++) {
			my_putchar(' ');
		}
		my_putchar('B');
		my_putchar('\n');
	}
	my_putchar('C');
	for (int i = 2 ; i < x ; i++) {
		my_putchar('B');
	}
	my_putchar('C');
	my_putchar('\n');
	return (0);
}

void rush(int x, int y)
{
	if (x <= 0 || y <= 0 || x > 2147483647 || y > 2147483647) {
		invalid_size("Invalid size");
	} else {
		if (x == 1 || y == 1) {
			only_b(x, y);
		}
		if (x > 1 && y > 1) {
			normal_display(x, y);
		}
	}
}
