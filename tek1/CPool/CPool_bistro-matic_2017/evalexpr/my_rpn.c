/*
** EPITECH PROJECT, 2017
** my_rpm
** File description:
** rpm fonc evalexpr
*/

#include "all.h"

int nbr_to_rpn(rpn_t **rpn, char *str, int i)
{
	char *nbr = malloc(sizeof(char) * (nblen(str, i) + 3));
	int j = 1;
	rpn_t *new_rpn;

	nbr[0] = '+';
	while (str[i] >= '0' && str[i] <= '9') {
		nbr[j] = str[i];
		j++;
		i++;
	}
	nbr[j] = '\0';
	new_rpn = malloc(sizeof(*new_rpn));
	new_rpn->nb = nbr;
	new_rpn->ope = 0;
	new_rpn->next = *rpn;
	*rpn = new_rpn;
	return (i - 1);
}

void add_ope(rpn_t **rpn, ope_t **ope, char c)
{
	ope_t *new_ope;
	rpn_t *new_rpn;

	if (*ope != NULL) {
		if (priolevel((*ope)->ope) >= priolevel(c) && c != '(') {
			new_rpn = malloc(sizeof(*new_rpn));
			new_rpn->nb = "0";
			new_rpn->ope = (*ope)->ope;
			new_rpn->next = *rpn;
			*rpn = new_rpn;
			(*ope)->ope = c;
			return;
		}
	}
	new_ope = malloc(sizeof(*new_ope));
	new_ope->ope = c;
	new_ope->next = *ope;
	*ope = new_ope;
}

int apply_neg(rpn_t **rpn, ope_t **ope, char sign)
{
	rpn_t *new_rpn;

	if (sign == '-') {
		new_rpn = malloc(sizeof(*new_rpn));
		new_rpn->nb = "-1";
		new_rpn->ope = 0;
		new_rpn->next = *rpn;
		*rpn = new_rpn;
		add_ope(rpn, ope, '*');
	}
	return (1);
}

void my_rpn(char *str, rpn_t **rpn)
{
	ope_t *ope = NULL;
	int i = 0;

	if (str[i] == '-' || str[i] == '+')
		i = apply_neg(rpn, &ope, str[i]);
	while (i < my_strlen(str)) {
		if ((str[i] == '-' || str[i] == '+') && (str[i - 1] < '0' ||
		str[i - 1] > '9') && str[i - 1] != ')')
			apply_neg(rpn, &ope, str[i]);
		else if (my_charisope(str[i]) == 1)
			add_ope(rpn, &ope, str[i]);
		if (str[i] == ')')
			ope_to_rpn(rpn, &ope);
		if (str[i] >= '0' && str[i] <= '9')
			i = nbr_to_rpn(rpn, str, i);
		i++;
	}
	ope_to_rpn(rpn, &ope);
}
