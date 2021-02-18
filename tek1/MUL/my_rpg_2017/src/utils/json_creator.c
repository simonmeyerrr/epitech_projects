/*
** EPITECH PROJECT, 2017
** my_rpg
** File description:
** json_creator.c
*/

#include "all.h"

static void add_key(char *json, char *key, int *j)
{
	json[*j] = '\"';
	*j = *j + 1;
	for (int k = 0 ; key && key[k] ; k++) {
		json[*j] = key[k];
		*j = *j + 1;
	}
	json[*j] = '\"';
	json[*j + 1] = ':';
	json[*j + 2] = ' ';
	*j = *j + 3;
}

static void add_value(char *json, char *value, int *j)
{
	json[*j] = '\"';
	*j = *j + 1;
	for (int k = 0 ; value && value[k] ; k++) {
		json[*j] = value[k];
		*j = *j + 1;
	}
	json[*j] = '\"';
	*j = *j + 1;
}

static void create_json(char **tab, char *json)
{
	int j = 1;

	json[0] = '{';
	for (int i = 0 ; tab && tab[i] ; i += 2) {
		add_key(json, tab[i], &j);
		add_value(json, tab[i + 1], &j);
		if (tab[i + 1] && tab[i + 2]) {
			json[j] = ',';
			json[j + 1] = ' ';
			j += 2;
		}
	}
	json[j] = '}';
	json[j + 1] = '\0';
}

char *json_creator(char **tab)
{
	int len = 0;
	char *json = NULL;

	for (int i = 0 ; tab && tab[i] ; i++) {
		len += my_strlen(tab[i]) + 8;
	}
	json = malloc(sizeof(char) * (len + 1));
	if (!json)
		return (NULL);
	create_json(tab, json);
	return (json);
}
