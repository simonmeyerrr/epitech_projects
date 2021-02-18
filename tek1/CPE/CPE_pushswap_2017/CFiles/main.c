/*
** EPITECH PROJECT, 2017
** my_pushswap
** File description:
** main
*/

#include "../include/my.h"

void my_clean_all(my_ptrs_t* ptrs)
{
	my_list_t* tmp = ptrs->end_a->prev;

	while (tmp != NULL) {
		free(ptrs->end_a);
		ptrs->end_a = tmp;
		tmp = ptrs->end_a->prev;
	}
	free(ptrs->begin_a);
	free(ptrs);
}

static void add_new_list(my_ptrs_t* ptrs, int nb)
{
	my_list_t* tmp = malloc(sizeof(*tmp));

	tmp->nb = nb;
	tmp->next = NULL;
	tmp->prev = ptrs->end_a;
	ptrs->end_a->next = tmp;
	ptrs->end_a = tmp;
}

static void my_init_list(int *tab, int ac)
{
	my_ptrs_t* ptrs = malloc(sizeof(*ptrs));

	ptrs->begin_a = malloc(sizeof(*(ptrs->begin_a)));
	ptrs->begin_a->nb = tab[0];
	ptrs->begin_a->next = NULL;
	ptrs->begin_a->prev = NULL;
	ptrs->end_a = ptrs->begin_a;
	ptrs->begin_b = NULL;
	ptrs->end_b = NULL;
	for (int i = 1 ; i < ac - 1; i++)
		add_new_list(ptrs, tab[i]);
	my_pushswap(ptrs, ac - 1);
	my_clean_all(ptrs);
}

static int my_get_nbr(char *str, int *error)
{
	int i = 0;
	int sign = 1;
	int nb = 0;

	if (str[0] == '-') {
		sign = -1;
		i = 1;
	}
	while (str[i] != '\0') {
		if (str[i] < '0' || str[i] > '9') {
			*error = 1;
			return (0);
		}
		nb = (nb * 10) + str[i] - '0';
		i++;
	}
	return (nb * sign);
}

int main(int ac, char **av)
{
	int *tab = malloc(sizeof(int*) * (ac - 1));
	int error = 0;

	if (ac > 3000) {
		write(1, "\n", 1);
		return (0);
	}
	if (ac > 2) {
		for (int i = 1 ; i < ac ; i++)
			tab[i - 1] = my_get_nbr(av[i], &error);
		if (error == 1)
			return (84);
		my_init_list(tab, ac);
	}
	free(tab);
	write(1, "\n", 1);
	return (0);
}
