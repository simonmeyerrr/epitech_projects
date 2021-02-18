/*
** EPITECH PROJECT, 2017
** my_rpg
** File description:
** inter_knuckles.c
*/

#include "all.h"

void inter_knuckle_block(global_t *global, game_t *game)
{
	char **tab = malloc(sizeof(char*) * 2);

	tab[0] = my_strdup("\nGroupe de knuckles:\nUr not da real King!"
	"*Rrrrrh pit* Spit on the fake king!");
	tab[1] = NULL;
	game->text = create_text_box(tab, nothing);
}

void win_knuckle(global_t *global, game_t *game)
{
	char **tab = malloc(sizeof(char*) * 2);

	tab[0] = my_strdup("\nJ\'ai la couronne des knuckles!\n"
	"Je suis le nouveau roi!");
	tab[1] = NULL;
	add_new_item(game, ITEM_COURONNE, SI_IN_INV);
	game->progression = 6;
	game->text = create_text_box(tab, nothing);
}

void fight_knuckle(global_t *global, game_t *game)
{
	create_fight(global, EN_KNUCKLE, TAB4(55, 55, 35, 30), win_knuckle);
}

void inter_king_knuckle(global_t *global, game_t *game)
{
	char **tab = malloc(sizeof(char*) * (3));

	tab[0] = my_strdup("\nKnuckle King:\nU Noob, I\'m da king!");
	tab[1] = my_strdup("\nToi:\nPlus pour longtemps!");
	tab[2] = NULL;
	game->text = create_text_box(tab, fight_knuckle);
}
