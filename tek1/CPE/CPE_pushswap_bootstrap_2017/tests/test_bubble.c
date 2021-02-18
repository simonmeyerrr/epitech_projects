/*
** EPITECH PROJECT, 2017
** tests.c
** File description:
** unit tests
*/

#include <criterion/criterion.h>

Test(bubble_sort_array, pre_sorted)
{
	int array[6] = {1, 2, 3, 4, 5, 6};
        int expect[6] = {1, 2, 3, 4, 5, 6};
        int size = 6;

	bubble_sort_array(array, size);
	cr_assert_arr_eq(array, expect, (sizeof(int) * size));
}

Test(bubble_sort_array, one_swap)
{
	int array[6] = {1, 2, 4, 3, 5, 6};
        int expect[6] = {1, 2, 3, 4, 5, 6};
        int size = 6;

	bubble_sort_array(array, size);
	cr_assert_arr_eq(array, expect, (sizeof(int) * size));
}

Test(bubble_sort_array, all_reverse)
{
	int array[6] = {6, 5, 4, 3, 2, 1};
        int expect[6] = {1, 2, 3, 4, 5, 6};
        int size = 6;

	bubble_sort_array(array, size);
	cr_assert_arr_eq(array, expect, (sizeof(int) * size));
}

Test(bubble_sort_array, two_nb_egals)
{
	int array[6] = {1, 4, 3, 5, 6, 4};
        int expect[6] = {1, 3, 4, 4, 5, 6};
        int size = 6;

	bubble_sort_array(array, size);
	cr_assert_arr_eq(array, expect, (sizeof(int) * size));
}
