/*
** EPITECH PROJECT, 2017
** my_rpg
** File description:
** inter_logan_paul.c
*/

#include "all.h"

void win_logan(global_t *global, game_t *game)
{
	char **tab = malloc(sizeof(char*) * 2);

	tab[0] = my_strdup("\nUne bonne chose de faite!\nJe vais lui prendre so"
	"n sac a dos, il est plutot cool.");
	tab[1] = NULL;
	add_new_item(game, ITEM_SACADO, SI_IN_INV);
	game->progression = 4;
	game->text = create_text_box(tab, nothing);
}

void fight_logan(global_t *global, game_t *game)
{
	create_fight(global, EN_LOGAN, TAB4(45, 45, 25, 25), win_logan);
}

void inter_logan(global_t *global, game_t *game)
{
	char **tab = malloc(sizeof(char*) * (3));

	tab[0] = my_strdup("\nLogan Paul:\nHi! I\'m Logan Paul the best vloger "
	"in the world!");
	tab[1] = my_strdup("\nToi:\nNon, t\'es juste un batard qui merite de mo"
	"urir.");
	tab[2] = NULL;
	game->text = create_text_box(tab, fight_logan);
}
