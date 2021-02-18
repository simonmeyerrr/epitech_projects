/*
** EPITECH PROJECT, 2017
** minishell1
** File description:
** free.c
*/

#include "all.h"

void my_free(void *ptr)
{
	if (ptr)
		free(ptr);
}

void my_free_tab(char **tab)
{
	if (!tab)
		return;
	for (int i = 0 ; tab[i] ; i++)
		my_free(tab[i]);
	my_free(tab);
}

void verif_malloc(void *ptr)
{
	if (!ptr) {
		my_putstr_fd("error while using malloc.", 2, 1);
		exit(EXIT_ERROR);
	}
}

void remove_var_env(var_env_t *var, my_env_t *env)
{
	if (!var)
		return;
	if (env->last == var)
		env->last = (var->prev) ? (var->prev) : (NULL);
	if (env->first == var)
		env->first = (var->next) ? (var->next) : (NULL);
	if (var->next)
		var->next->prev = (var->prev) ? (var->prev) : (NULL);
	if (var->prev)
		var->prev->next = (var->next) ? (var->next) : (NULL);
	my_free(var->name);
	my_free(var->value);
	my_free(var);
}

int free_my_env(my_env_t *env)
{
	int end = env->end[1];

	while (env->first)
		remove_var_env(env->first, env);
	my_free(env->end);
	my_free(env);
	return (end);
}
