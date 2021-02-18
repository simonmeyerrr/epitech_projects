/*
** EPITECH PROJECT, 2017
** my_rpg
** File description:
** init_asset.c
*/

#include "all.h"

static void get_pre_settings(my_var_t *var)
{
	int fd = open("asset/.settings", O_RDONLY);
	char a;
	float b;

	if (fd < 0)
		return;
	for (int i = 0 ; i < 4 ; i++) {
		read(fd, &a, 1);
		if (i == 0 && a >= 0 && a <= 100)
			var->setting[SET_VOL_GENERAL] = a;
		if (i == 1 && a >= 0 && a <= 100)
			var->setting[SET_VOL_MUSIC] = a;
		if (i == 2 && a >= 0 && a <= 100)
			var->setting[SET_VOL_SOUND] = a;
		if (i == 3 && (a == 0 || a == 1))
			var->setting[SET_VSYNC] = a;
	}
	read(fd, &b, sizeof(float));
	var->fps = (b == 30.0 || b == 60.0) ? (b) : (30.0);
	close(fd);
}

my_var_t *prepare_var(int *error)
{
	my_var_t *var = malloc(sizeof(my_var_t));

	if (verif_malloc(var, error))
		return (NULL);
	for (int i = 0 ; i < 3 ; i++) {
		var->setting[i] = 100;
		var->con_var[i] = 0;
		var->con_field[i] = malloc(sizeof(char) * 19);
		if (verif_malloc(var->con_field[i], error))
			return (NULL);
		memset(var->con_field[i], '\0', 19);
		var->button[i] = 0;
	}
	var->fps = 30.0;
	var->setting[SET_VSYNC] = 0;
	var->animation = 0;
	get_pre_settings(var);
	return (var);
}

my_music_t *prepare_music(int *error)
{
	my_music_t *music = malloc(sizeof(my_music_t));
	char *tab1[NB_MUSIC] = PATH_MUSIC;
	char *tab2[NB_SOUND] = PATH_SOUND;

	if (verif_malloc(music, error) != 0)
		return (NULL);
	for (int i = 0 ; i < NB_MUSIC ; i++) {
		music->music[i] = sfMusic_createFromFile(tab1[i]);
		if (!verif_malloc(music->music[i], error))
			sfMusic_setLoop(music->music[i], sfTrue);
	}
	for (int i = 0 ; i < NB_SOUND ; i++) {
		music->sound[i] = sfMusic_createFromFile(tab2[i]);
		verif_malloc(music->sound[i], error);
	}
	return (music);
}

my_font_t *prepare_font(int *error)
{
	my_font_t *font = malloc(sizeof(my_font_t));

	if (verif_malloc(font, error))
		return (NULL);
	font->font1 = sfFont_createFromFile(FONT1);
	font->font2 = sfFont_createFromFile(FONT2);
	font->font3 = sfFont_createFromFile(FONT3);
	if (!font->font1 || !font->font2 || !font->font3) {
		*error = 1;
		my_putstr_fd("Error while loading fonts.\n", 2);
	}
	return (font);
}
