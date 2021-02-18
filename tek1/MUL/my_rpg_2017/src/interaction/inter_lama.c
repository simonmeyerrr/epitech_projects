/*
** EPITECH PROJECT, 2017
** my_rpg
** File description:
** inter_lama.c
*/

#include "all.h"

void win_lama(global_t *global, game_t *game)
{
	char **tab = malloc(sizeof(char*) * 2);

	tab[0] = my_strdup("\nToi:\nTrop cool un Dildo, ca doit faire super"
	"mal!");
	tab[1] = NULL;
	add_new_item(game, ITEM_DILDO, SI_IN_INV);
	game->progression = 8;
	game->text = create_text_box(tab, nothing);
}

void fight_lama(global_t *global, game_t *game)
{
	create_fight(global, EN_LAMA, TAB4(65, 65, 45, 40), win_lama);
}

void inter_lama(global_t *global, game_t *game)
{
	char **tab = malloc(sizeof(char*) * (3));

	tab[0] = my_strdup("\nLamasticot:\nJahar va tous vous detruire et je ne"
	"\nte laisserai pas l\'en empecher!");
	tab[1] = my_strdup("\nToi:\nC\'est ce qu\'on va voir.");
	tab[2] = NULL;
	game->text = create_text_box(tab, fight_lama);
}
