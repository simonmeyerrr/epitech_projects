/*
** EPITECH PROJECT, 2017
** my_strcapitalize.c
** File description:
** up first letter of words
*/

char *my_strcapitalize(char *str)
{
	int lengthstr = my_strlen(str);

	if (str[0] > 96 && str[0] < 123)
		str[0] = str[0] - 32;
	for (int i = 1 ; i <= lengthstr ; i++) {
		if (str[i] > 96 && str[i] < 123 && str[i - 1] == ' ')
			str[i] = str[i] - 32;
		if (str[i] > 64 && str[i] < 91 && str[i - 1] != ' ')
			str[i] = str[i] + 32;
	}
	return (str);
}
