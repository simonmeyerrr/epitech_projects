/*
** EPITECH PROJECT, 2017
** minishell1
** File description:
** execution.c
*/

#include "all.h"

static void execution(char *path, char **arg, char **tab_env)
{
	pid_t child_pid;
	int status = 0;
	int a = 0;

	child_pid = fork();
	if(!child_pid) {
		a = execve(path, arg, tab_env);
	} else if (child_pid > 0) {
		waitpid(child_pid, &status, 0);
		if (status == 139)
			my_putstr_fd("Segmentation fault", 2, 1);
	}
	if (a == -1)
		exit(0);
}

static int normal_exec(char **tab, char **tab_env)
{
	if (access(tab[0], X_OK) == 0)
		execution(tab[0], tab, tab_env);
	else {
		my_putstr_fd(tab[0], 2, 0);
		my_putstr_fd(": Command not found.", 2, 1);
	}
	return (1);
}

static char *prepare_exec(char *s1, char *s2)
{
	char *path = NULL;
	int len1 = my_strlen(s1);
	int len2 = my_strlen(s2);
	int i = 0;

	path = malloc(sizeof(char) * (len1 + len2 + 2));
	verif_malloc(path);
	for (int j = 0 ; s2 && s2[j] != '\0' ; j++) {
		path[i] = s2[j];
		i++;
	}
	path[i] = '/';
	i++;
	for (int j = 0 ; s1 && s1[j] != '\0' ; j++) {
		path[i] = s1[j];
		i++;
	}
	path[i] = '\0';
	return (path);
}

static int search_path(char **tab, char **env, my_env_t *my_env)
{
	char **path;
	char *pwd;
	var_env_t *tmp = my_env->first;

	while (tmp && my_strcmp("PATH", tmp->name))
		tmp = tmp->next;
	path = (tmp) ? (my_str_to_word_array(tmp->value, ':')) : (NULL);
	for (int i = 0 ; path && path[i] ; i++) {
		pwd = prepare_exec(tab[0], path[i]);
		if (access(pwd, X_OK) == 0) {
			execution(pwd, tab, env);
			my_free(pwd);
			my_free_tab(path);
			return (1);
		}
		my_free(pwd);
	}
	my_free_tab(path);
	return (0);
}

void search_exec(char **tab, my_env_t *env)
{
	char **tab_env = my_env_to_tab(env);
	int exec = 0;

	for (int i = 0 ; exec == 0 && tab[0][i] != '\0' ; i++) {
		if (tab[0][i] == '/')
			exec = normal_exec(tab, tab_env);
	}
	if (exec == 0)
		exec = search_path(tab, tab_env, env);
	if (exec == 0) {
		my_putstr_fd(tab[0], 2, 0);
		my_putstr_fd(": Command not found.", 2, 1);
	}
	my_free_tab(tab_env);
}
