/*
** EPITECH PROJECT, 2017
** tests.c
** File description:
** unit tests
*/

#include <criterion/criterion.h>

Test(swap_elem, index1_greater_than_index2)
{
	int array[6] = {1, 2, 3, 4, 5, 6};
	int index1 = 1;
	int index2 = 4;

	swap_elem(array, index1, index2);
	cr_assert_eq(array[index1], 5);
	cr_assert_eq(array[index2], 2);
}

Test(swap_elem, index2_greater_than_index1)
{
	int array[6] = {1, 2, 3, 4, 5, 6};
	int index1 = 5;
	int index2 = 0;

	swap_elem(array, index1, index2);
	cr_assert_eq(array[index1], 1);
	cr_assert_eq(array[index2], 6);
}

Test(swap_elem, index1_equal_to_index2)
{
	int array[6] = {1, 2, 3, 4, 5, 6};
	int index1 = 3;
	int index2 = 3;

	swap_elem(array, index1, index2);
	cr_assert_eq(array[index1], 4);
	cr_assert_eq(array[index2], 4);
}
