/*
** EPITECH PROJECT, 2017
** minishell1
** File description:
** my_cd.c
*/

#include "all.h"

static char *my_cd_home(char *s1, char *s2)
{
	int i = 0;
	char *new;

	if (!s1)
		return (s2);
	new = malloc(sizeof(char) * (my_strlen(s1) + my_strlen(s2)));
	verif_malloc(new);
	while (s1 && s1[i] != '\0') {
		new[i] = s1[i];
		i++;
	}
	for (int j = 1 ; s2 && s2[j] != '\0' ; j++) {
		new[i] = s2[j];
		i++;
	}
	new[i] = '\0';
	return (new);
}

static void change_pwd_env(my_env_t *env)
{
	var_env_t *tmp = env->first;

	while (tmp != NULL && my_strcmp(tmp->name, "PWD") != 0)
		tmp = tmp->next;
	if (!tmp) {
		add_new_env_var(env, my_strdup("PWD"), getcwd(NULL, 0));
	} else {
		my_free(tmp->value);
		tmp->value = getcwd(NULL, 0);
	}
}

static void do_cd(char *path, my_env_t *env)
{
	char *old_pwd = getcwd(NULL, 0);
	int error = chdir(path);
	var_env_t *tmp = env->first;

	if (error == -1) {
		perror(path);
		my_free(path);
		my_free(old_pwd);
		return;
	}
	my_free(path);
	while (tmp != NULL && my_strcmp(tmp->name, "OLDPWD") != 0)
		tmp = tmp->next;
	if (!tmp) {
		add_new_env_var(env, my_strdup("OLDPWD"), old_pwd);
	} else {
		my_free(tmp->value);
		tmp->value = old_pwd;
	}
	change_pwd_env(env);
}

static void my_cd2(char **tab, my_env_t *env)
{
	var_env_t *tmp;
	char *pwd;

	if (tab[1] && tab[1][0] == '~') {
		for (tmp = env->first ; tmp != NULL &&
		my_strcmp(tmp->name, "HOME") != 0 ; tmp = tmp->next);
		do_cd((tmp) ? (my_cd_home(tmp->value, tab[1])) : (NULL), env);
		return;
	}
	if (tab[1] && my_strcmp(tab[1], "-") == 0) {
		for (tmp = env->first ; tmp != NULL &&
		my_strcmp(tmp->name, "OLDPWD") != 0 ; tmp = tmp->next);
		do_cd((tmp) ? (my_strdup(tmp->value)) : (NULL), env);
		if (tmp)
			my_free(my_putstr_fd(getcwd(NULL, 0), 1, 1));
		return;
	}
	do_cd(my_strdup(tab[1]), env);
}

void my_cd(char **tab, my_env_t *env)
{
	var_env_t *tmp;

	if (tab[1] && tab[2]) {
		my_putstr_fd("cd: Too many arguments.", 2, 1);
		return;
	}
	if (tab[1] == NULL) {
		for (tmp = env->first ; tmp != NULL &&
		my_strcmp(tmp->name, "HOME") != 0 ; tmp = tmp->next);
		do_cd((tmp) ? (my_strdup(tmp->value)) : (NULL), env);
		return;
	}
	my_cd2(tab, env);
}
