/*
** EPITECH PROJECT, 2017
** tests.c
** File description:
** unit tests
*/

#include <criterion/criterion.h>

Test(sum_stdarg, numbers1)
{
	int result = sum_stdarg(0, 3, 5, 10, -7);

	cr_assert_eq(result, 8);
}

Test(sum_stdarg, numbers2)
{
	int result = sum_stdarg(0, 6, 5, 10, -7, -30, 5, 10);

	cr_assert_eq(result, -7);
}

Test(sum_stdarg, str1)
{
	int result = sum_stdarg(1, 3, "oui", "bite", "a\na");

	cr_assert_eq(result, 10);
}

Test(sum_stdarg, str2)
{
	int result = sum_stdarg(1, 5, "", "", "", "oui", "");

	cr_assert_eq(result, 3);
}
