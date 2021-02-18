/*
** EPITECH PROJECT, 2017
** my_runner
** File description:
** main.c
*/

#include "all.h"

sfVector2f get_mouse_pos(sfRenderWindow *win)
{
	sfWindow* window = win;
	sfVector2i pos = sfMouse_getPosition(window);
	sfVector2f pos2 = {pos.x, pos.y};

	return (pos2);
}

static sfRenderWindow *init_window(void)
{
	sfVideoMode mode = {1920, 1000, 32};
	sfRenderWindow *win = sfRenderWindow_create(mode, "My Runner",
	sfClose | sfResize, NULL);

	sfRenderWindow_setMouseCursorVisible(win, sfFalse);
	sfRenderWindow_setFramerateLimit(win, 30);
	return (win);
}

static int play_custom(char* path_map)
{
	int error = 0;
	char **map = open_map(path_map, &error);
	sfRenderWindow *win = (error == 0) ? (init_window()) : (0);
	int settings[4] = {10, 0, 0, 0};

	if (error != 0)
		return (EXIT_ERROR);
	my_runner(win, map, &error, settings);
	if (sfRenderWindow_isOpen(win))
		sfRenderWindow_close(win);
	sfRenderWindow_destroy(win);
	free_map(map);
	return ((error == 0) ? (EXIT_SUCCESS) : (EXIT_ERROR));
}

static int play_normal(void)
{
	int error = 0;
	menu_t *menu = prepare_menu(&error);
	sfRenderWindow *win = (error == 0) ? (init_window()) : (NULL);

	if (error != 0)
		return (EXIT_ERROR);
	while (sfRenderWindow_isOpen(win) && menu->var->menu != 0) {
		while (sfRenderWindow_isOpen(win) && menu->var->menu == 1)
			main_menu(menu, win);
		while (sfRenderWindow_isOpen(win) && menu->var->menu == 2)
			play_menu(menu, win);
		while (sfRenderWindow_isOpen(win) && menu->var->menu == 3)
			settings_menu(menu, win);
	}
	if (sfRenderWindow_isOpen(win))
		sfRenderWindow_close(win);
	sfRenderWindow_destroy(win);
	free_struct_menu(menu);
	return ((error != 0) ? (EXIT_ERROR) : (EXIT_SUCCESS));
}

int main(int ac, char **av)
{
	int mode = 1;

	mode = (ac == 2 && my_strcmp(av[1], "-h") == 0) ? (0) : (mode);
	mode = (ac == 1) ? (2) : (mode);
	mode = (ac != 1 && ac != 2) ? (-1) : (mode);
	switch (mode) {
		case -1:
			my_putstr_fd("Invalid arguments.\n", 2);
			return (EXIT_ERROR);
		case 0:
			my_putstr_fd(USAGE, 1);
			return (EXIT_SUCCESS);
		case 1:
			return (play_custom(av[1]));
		case 2:
			return (play_normal());
	}
}
