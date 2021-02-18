/*
** EPITECH PROJECT, 2017
** my_rpg
** File description:
** free_global.c
*/

#include "all.h"

void free_part(part_t *buff)
{
	if (!buff)
		return;
	if (buff->text)
		sfTexture_destroy(buff->text);
	my_free(buff->state);
	my_free(buff->life);
	my_free(buff->speed);
	my_free(buff->vertex);
	my_free(buff);
}

static void free_network(my_network_t *net)
{
	if (!net)
		return;
	if (net->http)
		sfHttp_destroy(net->http);
	free(net);
}

static void free_var(my_var_t *var)
{
	if (!var)
		return;
	my_free(var->con_field[CON_USERNAME]);
	my_free(var->con_field[CON_PASSWORD1]);
	my_free(var->con_field[CON_PASSWORD2]);
	my_free(var);
}

static void free_clock(my_clock_t *clock)
{
	if (!clock)
		return;
	if (clock->update)
		sfClock_destroy(clock->update);
	if (clock->frame_rate)
		sfClock_destroy(clock->frame_rate);
	my_free(clock);
}

void free_global(global_t *global)
{
	if (global->win && sfRenderWindow_isOpen(global->win))
		sfRenderWindow_close(global->win);
	if (global->win)
		sfRenderWindow_destroy(global->win);
	free_texture(global->texture);
	free_sprite(global->sprite);
	free_music(global->music);
	free_font(global->font);
	free_clock(global->clock);
	free_game(global);
	free_var(global->var);
	free_network(global->net);
	my_free(global);
}
