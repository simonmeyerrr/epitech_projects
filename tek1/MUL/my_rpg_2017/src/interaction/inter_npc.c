/*
** EPITECH PROJECT, 2017
** my_rpg
** File description:
** inter_npc.c
*/

#include "all.h"

void inter_nurse(global_t *global, game_t *game)
{
	char **tab = malloc(sizeof(char*) * (2));

	tab[0] = my_strdup("\nInfirmiere:\nEt voila, j'ai soigne tous tes"
	" bobos");
	tab[1] = NULL;
	if (game->stat_player[STAT_PV] < game->stat_player[STAT_PV_MAX])
		game->stat_player[STAT_PV] = game->stat_player[STAT_PV_MAX];
	game->text = create_text_box(tab, nothing);
}

void inter_npc3(global_t *global, game_t *game)
{
	char **tab = malloc(sizeof(char*) * (2));

	tab[0] = my_strdup("\nMec chelou:\nWoaw t\'es trop mignon dans ce cost"
	"ume!");
	if (game->progression > 8) {
		my_free(tab[0]);
		tab[0] = my_strdup("Mec chelou:\nC'est genial de nous avoir sau"
		"ve,\nje ferai ce que tu veux pour te remercier.");
	}
	tab[1] = NULL;
	game->text = create_text_box(tab, nothing);
}

void inter_npc2(global_t *global, game_t *game)
{
	char **tab = malloc(sizeof(char*) * (2));

	tab[0] = my_strdup("Braqueur:\nYeeeh permet de faire des"
	" degats bruts mais ne\nmarche pas a tous les coups!");
	if (game->progression > 8) {
		my_free(tab[0]);
		tab[0] = my_strdup("\nBraqueur:\nTu t\'en es plutot bien sor"
		"ti!");
	}
	tab[1] = NULL;
	game->text = create_text_box(tab, nothing);
}

void inter_npc1(global_t *global, game_t *game)
{
	char **tab = malloc(sizeof(char*) * (2));

	tab[0] = my_strdup("Habitant:\nJe viens de voir aux infos que des lamas"
	"ticots\nsont apparus partout sur terre pour nous exterminer!\nOn va to"
	"us mourrir si personne ne fait rien!");
	if (game->progression > 8) {
		my_free(tab[0]);
		tab[0] = my_strdup("Habitant:\nMerci d\'avoir sauve l\'humanit"
		"e!");
	}
	tab[1] = NULL;
	game->text = create_text_box(tab, nothing);
}
