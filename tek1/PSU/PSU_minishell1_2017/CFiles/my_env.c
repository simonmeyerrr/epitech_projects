/*
** EPITECH PROJECT, 2017
** minishell1
** File description:
** my_env.c
*/

#include "all.h"

static char* create_line_env(var_env_t *var)
{
	char *str = malloc(sizeof(char) * (my_strlen(var->name) +
	my_strlen(var->value) + 2));
	int i = 0;

	verif_malloc(str);
	for (int j = 0 ; var->name && var->name[j] != '\0' ; j++) {
		str[i] = var->name[j];
		i++;
	}
	str[i] = '=';
	i++;
	for (int j = 0 ; var->value && var->value[j] != '\0' ; j++) {
		str[i] = var->value[j];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char **my_env_to_tab(my_env_t *env)
{
	int height = 0;
	int i = 0;
	char **tab;

	for (var_env_t *tmp = env->first ; tmp ; tmp = tmp->next)
		height++;
	if (height == 0)
		return (NULL);
	tab = malloc(sizeof(char*) * (height + 1));
	verif_malloc(tab);
	for (var_env_t *tmp = env->first ; tmp ; tmp = tmp->next) {
		tab[i] = create_line_env(tmp);
		i++;
	}
	tab[i] = NULL;
	return (tab);
}

void add_new_env_var(my_env_t *env, char *name, char *value)
{
	var_env_t *var = malloc(sizeof(*var));

	verif_malloc(var);
	var->name = name;
	var->value = value;
	var->next = NULL;
	var->prev = env->last;
	if (env->last)
		env->last->next = var;
	else
		env->first = var;
	env->last = var;
}

static void add_env(my_env_t *env, char *str)
{
	int len[2] = {0, 0};
	char *name;
	char *value;

	for (len[0] ; str[len[0]] != '=' && str[len[0]] != '\0' ; len[0] += 1);
	if (str[len[0]] == '\0')
		return;
	for (int i = len[0] + 1 ; str[i] != '\0' ; i++)
		len[1] += 1;
	name = malloc(sizeof(char) * (len[0] + 1));
	value = malloc(sizeof(char) * (len[1] + 1));
	verif_malloc(name);
	verif_malloc(value);
	for (int i = 0 ; str[i] != '=' ; i++)
		name[i] = str[i];
	name[len[0]] = '\0';
	for (int i = 0 ; str[i + len[0] + 1] != '\0' ; i++)
		value[i] = str[i + len[0] + 1];
	value[len[1]] = '\0';
	add_new_env_var(env, name, value);
}

my_env_t *init_env(char **env)
{
	my_env_t *my_env = malloc(sizeof(*my_env));

	verif_malloc(my_env);
	my_env->end = malloc(sizeof(int) * 2);
	verif_malloc(my_env->end);
	my_env->end[0] = 0;
	my_env->end[1] = 0;
	my_env->first = NULL;
	my_env->last = NULL;
	if (!env)
		return (my_env);
	for (int i = 0 ; env[i] != NULL ; i++)
		add_env(my_env, env[i]);
	return (my_env);
}
