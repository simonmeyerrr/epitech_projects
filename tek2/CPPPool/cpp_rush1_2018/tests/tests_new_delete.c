/*
** EPITECH PROJECT, 2018
** cpp_rush1_2018
** File description:
** tests_new.c
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <signal.h>
#include "player.h"
#include "new.h"

void redirect_all_stdout(void);

Test(new, new_null, .init=redirect_all_stdout, .signal = SIGABRT)
{
    new(NULL);
}

Test(new, delete_null, .init=redirect_all_stdout, .signal = SIGABRT)
{
    delete(NULL);
}

Test(new, new_delete_normal, .init=redirect_all_stdout)
{
    Object *player = new(Player);

    cr_assert_not_null(player);
    delete(player);
    cr_assert_stdout_eq_str("Player()\n~Player()\n");
}