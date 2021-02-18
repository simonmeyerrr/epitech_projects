/*
** EPITECH PROJECT, 2017
** minus
** File description:
** minus
*/

#include "all.h"

void prepare_add(char **s1, char **s2)
{
	char *swap;

	if (*s1[0] == '-' || *s1[0] == '+')
		*s1[0] = '0';
	if (*s2[0] == '-' || *s2[0] == '+')
		*s2[0] = '0';
	swap = *s1;
	*s1 = *s2;
	*s2 = swap;
}

int compare_str(char *s1, char *s2)
{
	int i = 1;

	while (s1[i] == s2[i] && s2[i] != '\0' && s1[i] != '\0')
		i++;
	if (s1[i] == '\0' && s2[i] == '\0')
		return (0);
	else
		return (s1[i] - s2[i]);
}

char *calc_min(char *s1, char *s2, char sign)
{
	int i = my_strlen(s1) - 1;
	int j = my_strlen(s2) - 1;
	int retenue = 0;
	char *str = malloc(sizeof(char) * my_strlen(s1) + 2);

	while (i > 0 && j > 0) {
		retenue = 0;
		if (s1[i] - s2[j] < 0) {
			s1[i] = s1[i] + 10;
			s2[j - 1] = s2[j - 1] + 1;
			retenue = retenue + 1;
		}
		str[i] = s1[i] - s2[j] + '0';
		i--;
		j--;
	}
	while (i != -1 && j == 0) {
		str[i] = s1[i] - retenue;
		i--;
		retenue = 0;
	}
	str[0] = sign;
	return (str);
}

char *redirection(char *s1, char *s2)
{
	int change = 0;
	char *result;
	char ope = '+';

	put_zero(&s1, &s2);
	if (my_strlen(s1) < my_strlen(s2) || (s1[0] == '-')
	|| (compare_str(s1, s2)) < 0) {
		prepare_add(&s1, &s2);
		change = 1;
	}
	if ((compare_str(s1, s2)) < 0 && (change == 1)) {
		result = calc_min(s2, s1, '-');
	} else {
		if (change == 1)
			ope = '-';
		result = calc_min(s1, s2, ope);
	}
	return (result);
}
