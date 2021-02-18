/*
** EPITECH PROJECT, 2017
** my_rpg
** File description:
** inter_object.c
*/

#include "all.h"

void inter_panneau(global_t *global, game_t *game)
{
	char **tab = malloc(sizeof(char*) * 2);

	tab[0] = NULL;
	switch (global->game->pos[1]) {
		case 109:
		case 110:
			tab[0] = my_strdup("\n<- Suicide forest / Mont Fuji");
			break;
		case 86:
		case 87:
			tab[0] = my_strdup("\n<- Telepherique du Mont Fuji\n"
			"-> Grotte du roi knuckle");
			break;
	}
	if (!tab[0])
		tab[0] = my_strdup("");
	tab[1] = NULL;
	game->text = create_text_box(tab, nothing);
}

void inter_stick(global_t *global, game_t *game)
{
	char **tab = malloc(sizeof(char*) * 3);

	tab[0] = my_strdup("Woaw ce baton magique m'a totalement transforme!"
	"\nJe vais le mettre dans mon inventaire.");
	tab[1] = my_strdup("J\'ai comme l'impression que je viens de declencher"
	"\nquelque chose de terrible en haut du mont Fuji.\nJe devrais m\'y ren"
	"dre pour reparer ma betise!");
	tab[2] = NULL;
	game->progression = 2;
	add_new_item(game, ITEM_BATON, SI_IN_INV);
	game->text = create_text_box(tab, nothing);
}

void inter_coffre3(global_t *global, game_t *game)
{
	char **tab = malloc(sizeof(char*) * 2);

	tab[0] = my_strdup("\nTu as trouve: une Biere!");
	tab[1] = NULL;
	game->progression = 7;
	add_new_item(game, ITEM_BIERE, SI_IN_INV);
	sfMusic_play(global->music->sound[SOUND_COFFRE]);
	game->text = create_text_box(tab, nothing);
}

void inter_coffre2(global_t *global, game_t *game)
{
	char **tab = malloc(sizeof(char*) * 2);

	tab[0] = my_strdup("\nTu as trouve: des Tongues!");
	tab[1] = NULL;
	game->progression = 5;
	add_new_item(game, ITEM_TONGUE, SI_IN_INV);
	sfMusic_play(global->music->sound[SOUND_COFFRE]);
	game->text = create_text_box(tab, nothing);
}

void inter_coffre1(global_t *global, game_t *game)
{
	char **tab = malloc(sizeof(char*) * 2);

	tab[0] = my_strdup("\nTu as trouve: des Crocs!");
	tab[1] = NULL;
	game->progression = 3;
	add_new_item(game, ITEM_CROCS, SI_IN_INV);
	sfMusic_play(global->music->sound[SOUND_COFFRE]);
	game->text = create_text_box(tab, nothing);
}
