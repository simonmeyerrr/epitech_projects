/*
** EPITECH PROJECT, 2018
** cpp_d01_2018
** File description:
** tests_follow_the_white_rabbit.c
*/

#include <criterion/criterion.h>
#include <stdlib.h>
#include "tests.h"

Test(follow_the_white_rabbit, srandom1, .init = redirect_all_std)
{
    srandom(1);
    cr_assert_gt(follow_the_white_rabbit(), 0);
}

Test(follow_the_white_rabbit, srandom2, .init = redirect_all_std)
{
    srandom(2);
    cr_assert_gt(follow_the_white_rabbit(), 0);
}

Test(follow_the_white_rabbit, srandom3, .init = redirect_all_std)
{
    srandom(3);
    cr_assert_gt(follow_the_white_rabbit(), 0);
}

Test(follow_the_white_rabbit, srandom4, .init = redirect_all_std)
{
    srandom(4);
    cr_assert_gt(follow_the_white_rabbit(), 0);
}

Test(follow_the_white_rabbit, srandom5, .init = redirect_all_std)
{
    srandom(5);
    cr_assert_gt(follow_the_white_rabbit(), 0);
}