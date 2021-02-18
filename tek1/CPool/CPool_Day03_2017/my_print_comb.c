/*
** EPITECH PROJECT, 2017
** my_print_comb.c
** File description:
**
*/

int part_two(char digitA, char digitB, char digitC)
{
	my_putchar(digitA);
	my_putchar(digitB);
	my_putchar(digitC);
	if (digitA == '7' && digitB == '8' && digitC == '9') {
		my_putchar('\n');
		return (0);
	}
	my_putchar(',');
	my_putchar(' ');
}

int part_one(char digitA, char digitB, char digitC)
{
	while (digitC <= '9') {
		if (digitA < digitB && digitB < digitC) {
			part_two(digitA, digitB, digitC);
		}
		digitC++;
	}
}

int my_print_comb(void)
{
	char digitA;
	char digitB = '1';
	char digitC = '2';

	for (digitA = '0' ; digitA < '8' ; digitA++) {
		while (digitB <= '9') {
			part_one(digitA, digitB, digitC);
			digitC = '0';
			digitB = digitB + 1;
		}
		digitB = '0';
	}
	return (0);
}
