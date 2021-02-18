/*
** EPITECH PROJECT, 2017
** my_rpg
** File description:
** display.c
*/

#include "all.h"

static void display_enemy_attack(my_sprite_t *sprite, sfRenderWindow *win,
game_t *game)
{
	if (game->fight->fight_anim < 15) {
		my_draw_sprite(win,
		sprite->image[ene_tab[game->fight->enemy].image],
		VEC(1200 - game->fight->fight_anim * 70, 100));
		my_draw_sprite(win, sprite->image[IM_CORO_FIGHT],
		VEC(100, 100));
		return;
	}
	if (game->fight->fight_anim > 30 || game->fight->fight_anim % 4 < 2)
		my_draw_sprite(win, sprite->image[IM_CORO_FIGHT],
		VEC(100, 100));
	if (game->fight->fight_anim < 28)
		my_draw_sprite(win,
		sprite->image[ene_tab[game->fight->enemy].image],
		VEC(400 + ((game->fight->fight_anim - 15) * 70), 100));
	else
		my_draw_sprite(win,
		sprite->image[ene_tab[game->fight->enemy].image],
		VEC(1200, 100));
	draw_part(win, game->fight->part);
}

static void display_coro_attack(my_sprite_t *sprite, sfRenderWindow *win,
game_t *game)
{
	if (game->fight->fight_anim < 15) {
		my_draw_sprite(win,
		sprite->image[ene_tab[game->fight->enemy].image],
		VEC(1200, 100));
		my_draw_sprite(win, sprite->image[IM_CORO_FIGHT],
		VEC(100 + game->fight->fight_anim * 70, 100));
		return;
	}
	if (game->fight->fight_anim > 30 || game->fight->fight_anim % 4 < 2)
		my_draw_sprite(win,
		sprite->image[ene_tab[game->fight->enemy].image],
		VEC(1200, 100));
	if (game->fight->fight_anim < 28)
		my_draw_sprite(win, sprite->image[IM_CORO_FIGHT],
		VEC(980 - ((game->fight->fight_anim - 15) * 70), 100));
	else
		my_draw_sprite(win, sprite->image[IM_CORO_FIGHT],
		VEC(100, 100));
	draw_part(win, game->fight->part);
}

static void display_fight2(my_sprite_t *sprite, sfRenderWindow *win,
game_t *game)
{
	if (game->fight->fight_status == 1) {
		display_enemy_attack(sprite, win, game);
	} else if (game->fight->fight_status == 0) {
		display_coro_attack(sprite, win, game);
	} else {
		my_draw_sprite(win, sprite->image[IM_CORO_FIGHT],
		VEC(100, 100));
		my_draw_sprite(win,
		sprite->image[ene_tab[game->fight->enemy].image],
		VEC(1200, 100));
	}
}

static int display_cursor(my_sprite_t *sprite, sfRenderWindow *win,
global_t *global, my_font_t *font)
{
	sfVector2f pos = get_mouse_pos(global);

	my_draw_sprite(win, sprite->button[BT_FIGHT_1],
	VEC(0 * 700 + 200, 720));
	my_draw_sprite(win, sprite->button[BT_FIGHT_2],
	VEC(1 * 700 + 200, 720));
	my_draw_text(win, TEXT(VEC(240, 750), 35, sfBlack, font->font2),
	"Lasagnakadrabogne", 0);
	my_draw_text(win, TEXT(VEC(940, 750), 35, sfBlack, font->font2),
	"Yeeeeeeeeeeeeeeeh", 0);
	for (int i = 0 ; i < 2 ; i++)
		if (mouse_on_button(VEC(pos.x, pos.y),
		create_tab4(i * 700 + 200, 720, 500, 100)))
			return (1);
	return (0);
}

void display_fight(global_t *global, my_sprite_t *sprite, my_font_t *font,
sfRenderWindow *win)
{
	if (global->game->fight->enemy == 0)
		my_draw_sprite(win, sprite->background[BG_FIGHT], VEC(0, 0));
	else if (global->game->fight->enemy == 1)
		my_draw_sprite(win, sprite->background[BG_FIGHT2], VEC(0, 0));
	else
		my_draw_sprite(win, sprite->background[BG_FIGHT3], VEC(0, 0));
	display_fight2(sprite, win, global->game);
	my_draw_text(win, TEXT(VEC(100, 50), 40, sfWhite,
	font->font2), int_to_str(global->game->stat_player[STAT_PV]), 1);
	my_draw_text(win, TEXT(VEC(1400, 50), 40, sfWhite,
	font->font2), int_to_str(global->game->fight->stat_enemy[STAT_PV]), 1);
	if (global->game->fight->fight_anim != 0)
		my_draw_text(win, TEXT(VEC(100, 750), 60, sfBlack,
		font->font2), global->game->fight->string, 0);
	my_draw_mouse(global, (global->game->fight->fight_status == 0 &&
	global->game->fight->fight_anim == 0 &&
	display_cursor(sprite, win, global, font)));
}
