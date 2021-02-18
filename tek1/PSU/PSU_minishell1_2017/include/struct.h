/*
** EPITECH PROJECT, 2017
** minishell1
** File description:
** struct.h
*/

typedef struct var_env
{
	char *name;
	char *value;
	struct var_env *prev;
	struct var_env *next;
} var_env_t;

typedef struct my_env
{
	int *end;
	char *prompt;
	var_env_t *first;
	var_env_t *last;
} my_env_t;
