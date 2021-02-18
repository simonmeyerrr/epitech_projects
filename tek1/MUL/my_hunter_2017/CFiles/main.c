/*
** EPITECH PROJECT, 2017
** my_hunter
** File description:
** main
*/

#include "all.h"

void my_hunter(int* error)
{
	myObjects_t* obj = malloc(sizeof(*obj));

	my_init(obj, error);
	if (*error == 1)
		return;
	while (sfRenderWindow_isOpen(obj->window)) {
		while(sfRenderWindow_isOpen(obj->window) && obj->var->menu == 1)
			start_menu(obj);
		while(sfRenderWindow_isOpen(obj->window) && obj->var->menu == 2)
			game_screen(obj, obj->window, obj->sprite);
		while(sfRenderWindow_isOpen(obj->window) && obj->var->menu == 3)
			end_menu(obj);
	}
	my_destroy(obj);
}

int main(int ac, char **av)
{
	int error = 0;

	if (ac == 1)
		my_hunter(&error);
	else if (ac == 2 && my_strcmp("-h", av[1]) == 0)
		write(1, USAGE, USAGE_LEN);
	else
		return (84);
	if (error == 1)
		return (84);
	return (0);
}
