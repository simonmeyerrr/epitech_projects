/*
** EPITECH PROJECT, 2017
** sort_numbers.c
** File description:
** sort_numbers
*/

#include "pimp_my_algo.h"

void swap_elem(int *array, int index1, int index2)
{
        int swap = array[index1];

        array[index1] = array[index2];
        array[index2] = swap;
}

void bubble_sort_array(int *array, int size)
{
        for (int i = 0 ; i < size - 1 ; i++) {
                if (array[i] > array[i + 1]) {
                        swap_elem(array, i, i + 1);
                        i = -1;
                }
        }
}

void my_amazing_sorter(int *array, int size)
{
        if (array[0] > array[1])
                write(1, "swap\n", 5);
        else if (array[size - 1] > array[0])
                write(1, "rotate_right\n", 13);
        else
                write(1, "rotate_left\n", 12);
}

int sort_numbers(int *la, int *lb, size_t nb)
{
}
