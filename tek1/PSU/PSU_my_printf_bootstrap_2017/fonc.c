/*
** EPITECH PROJECT, 2017
** fonc.c
** File description:
** other fonc for bootstrap
*/

void my_putchar(char c)
{
        write(1, &c, 1);
}

int my_put_nbr(int nb)
{
	if (nb >= 10)
		my_put_nbr(nb / 10);
	else if (nb < 0) {
		my_putchar('-');
		nb = -nb;
		my_put_nbr(nb / 10);
	}
	my_putchar(nb % 10 + '0');
	return (0);
}

int my_strlen(char *str)
{
	int i = 0;

	while (str[i] != '\0')
		i++;
	return (i);
}

int my_putstr(char *str)
{
	int i = 0;

	while (str[i] != '\0') {
		my_putchar(str[i]);
		i++;
	}
}
