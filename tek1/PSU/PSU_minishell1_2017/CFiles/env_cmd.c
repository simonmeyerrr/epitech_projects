/*
** EPITECH PROJECT, 2017
** minishell1
** File description:
** env_cmd.c
*/

#include "all.h"

void my_setenv(char **tab, my_env_t *env)
{
	var_env_t *tmp = env->first;
	char *value;
	char *name;

	if (tab[1] == NULL || (tab[2] && tab[3])) {
		(!tab[1]) ? (my_disp_env(tab, env)) :
		(my_putstr_fd("setenv: Too many arguments.", 2, 1));
		return;
	}
	value = my_strdup(tab[2]);
	name = my_strdup(tab[1]);
	while (tmp != NULL && my_strcmp(tmp->name, tab[1]) != 0)
		tmp = tmp->next;
	if (!tmp) {
		add_new_env_var(env, name, value);
	} else {
		free(tmp->value);
		tmp->value = value;
	}
}

void my_unsetenv(char **tab, my_env_t *env)
{
	var_env_t *tmp;

	for (int i = 1 ; tab[i] != NULL ; i++) {
		tmp = env->first;
		while (tmp != NULL && my_strcmp(tmp->name, tab[i]) != 0)
			tmp = tmp->next;
		if (tmp != NULL)
			remove_var_env(tmp, env);
	}
}

void my_disp_env(char **tab, my_env_t *env)
{
	for (var_env_t *tmp = env->first ; tmp != NULL ; tmp = tmp->next) {
		my_putstr_fd(tmp->name, 1, 0);
		my_putstr_fd("=", 1, 0);
		my_putstr_fd(tmp->value, 1, 1);
	}
}
