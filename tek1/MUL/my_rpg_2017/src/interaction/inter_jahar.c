/*
** EPITECH PROJECT, 2017
** my_rpg
** File description:
** inter_jahar.c
*/

#include "all.h"

void win_jahar(global_t *global, game_t *game)
{
	char **tab = malloc(sizeof(char*) * 3);

	tab[0] = my_strdup("Lorion:\nBravo, tu as sauve l\'humanite, je vais "
	"reenprisonner\nmon peuple dans un univers parallele pour qu\'il ne\nvo"
	"us cause plus aucun probleme.");
	tab[1] = my_strdup("\nToi:\nBon bah, j\'ai plus qu'a retourner stream\n"
	"et passer Master.");
	tab[2] = NULL;
	game->progression = 9;
	game->text = create_text_box(tab, nothing);
}

void fight_jahar(global_t *global, game_t *game)
{
	create_fight(global, EN_JAHAR, TAB4(70, 70, 50, 50), win_jahar);
}

void inter_jahar(global_t *global, game_t *game)
{
	char **tab = malloc(sizeof(char*) * (4));

	tab[0] = my_strdup("\nJahar:\nJe vais detruire ton satane peuple d\'inc"
	"apable!");
	tab[1] = my_strdup("\nToi:\nIl faudra me passer dessus!");
	tab[2] = my_strdup("\nLorion:\nFait attention, il est tres puissant!\n"
	"Je ne peux plus me battre.");
	tab[3] = NULL;
	game->text = create_text_box(tab, fight_jahar);
}
