/*
** EPITECH PROJECT, 2017
** tree.c
** File description:
** tree
*/

void trunk(int size, int base)
{
	int x = size;

	if (size % 2 == 0)
		x = size + 1;
	for (int j = 1 ; j <= size ; j++) {
		for (int i = 1 ; i < base - (x / 2) ; i++)
			my_putchar(' ');
		for (int i = 1 ; i <= x ; i++)
			my_putchar('|');
		my_putchar('\n');
	}
}

void display_foliage(int large, int base)
{
	for (int j = 1 ; j <= base - large ; j++)
		my_putchar(' ');
	for (int j = 1 ; j <= large ; j++)
		my_putchar('*');
	for (int j = 1 ; j <= large - 1 ; j++)
		my_putchar('*');
	my_putchar('\n');
}

void foliage(int size, int hauteur, int base)
{
	int large = 0;
	int etage = 1;
	int high = 1;
	int test = 0;

	for (int i = 1 ; i <= hauteur ; i++) {
		large = large + 1;
		if (etage <= size && (etage - 1) % 2 != 0 && test == 1)
			large = large - ((etage - 1)/ 2) - 2;
		if (etage <= size && (etage - 1)% 2 == 0 && test == 1)
			large = large - ((etage - 1) / 2) - 1;
		test = 0;
		display_foliage(large, base);
		if (i == high + 3) {
			high = high + 4 + etage;
			etage++;
			test = 1;
		}
	}
}

void tree(int size)
{
	int hauteur = 0;
	int base = 0;

	if (size <= 0 || size > 2147483647)
		return ;
	for (int etage = 1 ; etage <= size ; etage++) {
		hauteur = hauteur + etage + 3;
		base = base + etage + 3;
		if (etage < size && etage % 2 != 0)
			base = base - ((etage / 2) + 2);
		if (etage < size && etage % 2 == 0)
			base = base - ((etage / 2) + 1);
	}
	foliage(size, hauteur, base);
	trunk(size, base);
}
