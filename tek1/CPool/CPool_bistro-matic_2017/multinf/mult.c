/*
** EPITECH PROJECT, 2017
** multinf
** File description:
** Put description here
*/

#include "all.h"

int is_longest(char *s1, char *s2)
{
	int alen = my_strlen(s1);
	int blen = my_strlen(s2);

	if (alen >= blen)
		return (alen);
	else if (alen < blen)
		return (blen);
	return (0);
}

char do_mult(char a, char b, t_mult *mult, char current)
{
	int res = 0;

	if (current == 0)
		current = '0';
	res = ((current - '0') + ((a - '0') * (b - '0')) + mult->ret);
	mult->ret = res / 10;
	res %= 10;
	return (res + '0');
}

char *multinf(char *a, char *b)
{
	t_mult mul;
	char *res = malloc(sizeof(char) * (my_strlen(a) + my_strlen(b) + 2));
	int pos = 1;

	mul.ret = 0;
	for (mul.j = my_strlen(b) - 1 ; mul.j > 0 ; mul.j--) {
		mul.k = 0;
		for (mul.i = my_strlen(a) - 1 ; mul.i > 0 ; mul.i--) {
			res[mul.k + pos - 1] =
				do_mult(a[mul.i], b[mul.j], &mul,
					res[mul.k + pos - 1]);
			mul.k++;
		}
		if (mul.ret > 0) {
			res[mul.k + pos - 1] = mul.ret + '0';
			mul.ret = 0;
			mul.k++;
		}
		pos++;
	}
	if ((a[0] == '-' && b[0] != '-') || (a[0] != '-' && b[0] == '-'))
		res[mul.k + pos - 2] = '-';
	else
		res[mul.k + pos - 2] = '+';
	res[mul.k + pos - 1] = '\0';
	return (my_revstr(res));
}
