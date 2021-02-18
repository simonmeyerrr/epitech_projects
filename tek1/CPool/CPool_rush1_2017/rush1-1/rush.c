/*
** EPITECH PROJECT, 2017
** rush1-1
** File description:
** rush 1 assignement 1
*/

int only_one(int x, int y)
{
	if (x == 1 && y == 1) {
		 my_putchar('o');
	}
	if (x == 1 && y > 1) {
		my_putchar('o');
		my_putchar('\n');
		for (int i = 2 ; i < y ; i++) {
			my_putchar('|');
			my_putchar('\n');
		}
		my_putchar('o');
	}
	if (x > 1 && y == 1) {
		my_putchar('o');
		for (int i = 2 ; i < x ; i++) {
			my_putchar('-');
		}
		my_putchar('o');
	}
	my_putchar('\n');
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
	my_putchar('o');
	for (int i = 2 ; i < x ; i++) {
       		my_putchar('-');
	}
	my_putchar('o');
	my_putchar('\n');
	for (int j = 2 ; j < y ; j++) {
		my_putchar('|');
		for (int i = 2 ; i < x ; i++) {
			my_putchar(' ');
		}
		my_putchar('|');
		my_putchar('\n');
	}
	my_putchar ('o');
	for (int i = 2 ; i < x ; i++) {
		my_putchar('-');
	}
	my_putchar('o');
	my_putchar('\n');
	return (0);
}

void rush(int x, int y)
{
	if (x <= 0 || y <= 0 || x > 2147483647 || y > 2147483647) {
		invalid_size("Invalid size");
	} else {
		if (x == 1 || y == 1) {
			only_one(x, y);
		}
		if (x > 1 && y > 1) {
			normal_display(x, y);
		}
	}
}
