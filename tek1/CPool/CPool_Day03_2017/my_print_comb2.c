/*
** EPITECH PROJECT, 2017
** my_print_comb2.c
** File description:
** 
*/

int display(char digitA, char digitB, char digitC, char digitD)
{
	my_putchar(digitA);
	my_putchar(digitB);
	my_putchar(' ');
	my_putchar(digitC);
	my_putchar(digitD);
	if (digitA == '9' && digitB == '8' && digitC == '9' && digitD == '9') {
		my_putchar('\n');
		return (0);
	} else {
		my_putchar(',');
		my_putchar(' ');
	}
}

int div_two(char digitA, char digitB, char digitC, char digitD)
{
	int digitE;
	int digitF;

	digitE = digitA * 10 + digitB;
	digitF = digitC * 10 + digitD;
	if (digitE < digitF) {
		display(digitA, digitB, digitC, digitD);
	}
}

int div_one(char digitA, char digitB, char digitC, char digitD)
{
	for (digitC = '0' ; digitC <= '9' ; digitC++) {
		for (digitD = '0' ; digitD <= '9' ; digitD++) {
			div_two(digitA, digitB, digitC, digitD);
		}
	}
}

int my_print_comb2(void)
{
	char digitA;
	char digitB;
	char digitC;
	char digitD;

	for (digitA = '0' ; digitA <= '9' ; digitA++) {
		for (digitB = '0' ; digitB <= '9' ; digitB++) {
			div_one(digitA, digitB, digitC, digitD);
		}
	}
}
