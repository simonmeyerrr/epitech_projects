/*
** EPITECH PROJECT, 2017
** my_sokoban
** File description:
** main.c
*/

#include "all.h"

static int manage_choice(int touch, int* choice, int* level)
{
	char* tab[8] = {"map/level1", "map/level2", "map/level3", "map/level4",
	"map/level5", "map/level6", "map/level7", "map/level8"};

	if (touch == 113)
		return (1);
	if (touch == 66)
		(*choice < *level) ? (*choice = *choice + 1) : (*choice = 1);
	if (touch == 65)
		(*choice > 1) ? (*choice = *choice - 1) : (*choice = *level);
	if (touch == 112) {
		if (sokoban(tab[*choice - 1]) == 0) {
			(*level < 8 && *choice == *level) ?
			(*level = *level + 1) : (0);
			(*choice < 8) ? (*choice = *choice + 1) : (0);
		}
	}
	return (0);
}

static void print_menu(int choice, int level)
{
	attron(A_NORMAL);
	for (int i = 1 ; i < 9 ; i++) {
		if (i == choice) {
			attron(A_STANDOUT);
			printw("level %d\n", i);
			attroff(A_STANDOUT);
		}
		if (i != choice && i <= level) {
			printw("level %d\n", i);
		}
		if (i != choice && i > level) {
			attron(A_DIM);
			printw("level %d\n", i);
			attroff(A_DIM);
		}
	}
	attron(A_NORMAL);
}

void menu(void)
{
	int choice = 1;
	int level = 1;
	int exit = 0;

	while(exit == 0) {
		clear();
		if (LINES < 8 || COLS < 8)
			mvprintw(LINES / 2, COLS / 2 - 7, "Please resize");
		else {
			print_menu(choice, level);
			attron(A_NORMAL);
		}
		refresh();
		if (manage_choice(getch(), &choice, &level) == 1) {
			exit = 1;
		}
	}
}

int main(int ac, char **av)
{
	int ret;

	if (ac != 1)
		return (84);
	initscr();
	start_color();
	use_default_colors();
	curs_set(0);
	menu();
	endwin();
	return (ret);
}
