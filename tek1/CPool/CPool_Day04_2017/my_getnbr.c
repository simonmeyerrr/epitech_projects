/*
** EPITECH PROJECT, 2017
** my_getnbr.c
** File description:
** get number
*/

int sign_str(char const *str, int i)
{
	int sign = 0;

	i--;
	while (str[i] == 43 || str[i] == 45) {
		if (str[i] == 45) {
			sign = sign + 1;
		}
		i--;
	}
	if (sign % 2 == 0) {
		return(0);
	} else {
		return(1);
	}
}

int my_getnbr(char const *str)
{
	int number = 0;
	int i = 0;
	int sign = 0;

	while (str[i] < 48 || str[i] > 58) {
		i++;
	}
	sign = sign_str(str, i);
	while (str[i] > 48 && str[i] < 58) {
		number = (number * 10) + (str[i] - 48);
		i++;
	}
	if (sign == 1) {
		number = number * -1;
	}
	return (number);
}
