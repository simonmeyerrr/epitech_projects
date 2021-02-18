/*
** EPITECH PROJECT, 2017
** What is this language ?
** File description:
** find the language of a text
*/

int char_letter(char c)
{
	if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))
		return (1);
	else
		return (0);
}

int char_low(char c)
{
	if (c >= 'a' && c<= 'z')
		return (1);
	else
		return (0);
}

int char_up(char c)
{
	if (c >= 'A' && c <= 'Z')
		return (1);
	else
		return (0);
}

int dispnbr(int nb)
{
	int modulo;
	char c;

	if (nb >= 10) {
		modulo = nb % 10;
		nb = (nb - modulo) / 10;
		dispnbr(nb);
		c = modulo + 48;
		write(1, &c, 1);
	} else {
		c = nb + 48;
		write(1, &c, 1);
		return (0);
	}
	return (0);
}

int nbrletters(char *str)
{
	int letters = 0;

	for (int i = 0 ; str[i] != '\0' ; i++) {
		if ((str[i] >= 'A' && str[i] <= 'Z') ||
		    (str[i] >= 'a' && str[i] <= 'z'))
			letters++;
	}
	return (letters);
}
