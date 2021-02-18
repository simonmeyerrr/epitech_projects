/*
** EPITECH PROJECT, 2017
** minishell1
** File description:
** main.c
*/

#include "all.h"

static int my_get_nbr_exit(char *str, int *val)
{
	int nb = 0;
	int i = (str[0] == '-') ? (1) : (0);

	while (str[i] >= '0' && str[i] <= '9') {
		nb = nb * 10 + str[i] - '0';
		i++;
	}
	if (str[i] != '\0') {
		(str[i] == '.') ? (my_putstr_fd("exit: Badly formed number.", 2,
		1)) : (my_putstr_fd("exit: Expression Syntax.", 2, 1));
		*val = 0;
		return (0);
	}
	return ((str[0] == '-') ? (-nb) : (nb));
}

static void my_exit(char **tab, my_env_t *env)
{
	int a;
	int valid = 1;

	if (tab[1] == NULL) {
		env->end[0] = 1;
	} else if (tab[2] != NULL)
		my_putstr_fd("exit: Expression Syntax.", 2, 1);
	else {
		a = my_get_nbr_exit(tab[1], &valid);
		env->end[1] = a;
		env->end[0] = (valid == 1) ? (1) : (0);
	}
	if (env->end[0] == 1)
		my_putstr_fd("exit", 1, 1);
}

static void manage_input(my_env_t *env)
{
	char *cmd[6] = {"cd", "setenv", "unsetenv", "env", "exit", NULL};
	void (*fonc[5])(char**, my_env_t*) = {my_cd, my_setenv, my_unsetenv,
	my_disp_env, my_exit};
	char **tab = my_str_to_word_array(env->prompt, ' ');

	my_free(env->prompt);
	if (!tab)
		return;
	for (int i = 0 ; cmd[i] != NULL ; i++) {
		if (my_strcmp(tab[0], cmd[i]) == 0) {
			fonc[i](tab, env);
			my_free_tab(tab);
			return;
		}
	}
	search_exec(tab, env);
	my_free_tab(tab);
}

int main(int ac, char **av, char **env)
{
	my_env_t *my_env = init_env(env);

	while (my_env->end[0] == 0) {
		write(1, "> ", 2);
		my_env->prompt = get_next_line(0);
		if (!my_env->prompt) {
			my_env->end[0] = 1;
			write(1, "\n", 1);
		}
		manage_input(my_env);
	}
	return (free_my_env(my_env));
}
