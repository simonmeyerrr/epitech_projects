/*
** EPITECH PROJECT, 2017
** my_pushswap
** File description:
** my.h
*/

#ifndef MY_H_
#define MY_H_

/* includes */
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

/* structures */
typedef struct my_list
{
	int nb;
	struct my_list* next;
	struct my_list* prev;
} my_list_t;

typedef struct my_ptrs
{
	my_list_t* begin_a;
	my_list_t* end_a;
	my_list_t* begin_b;
	my_list_t* end_b;
} my_ptrs_t;

/* functions's prototypes */
void my_disp_list(my_list_t* begin);
int disp_ope(int space, char* str);
void my_putstr(char *str);
void my_pushswap(my_ptrs_t* ptrs, int size);
void swap_a(my_ptrs_t* ptrs);
void swap_b(my_ptrs_t* ptrs);
void swap_c(my_ptrs_t* ptrs);
void move_a_to_b(my_ptrs_t* ptrs);
void move_b_to_a(my_ptrs_t* ptrs);
void rotate_a(my_ptrs_t* ptrs);
void rotate_b(my_ptrs_t* ptrs);
void rotate_c(my_ptrs_t* ptrs);
void rev_rotate_a(my_ptrs_t* ptrs);
void rev_rotate_b(my_ptrs_t* ptrs);
void rev_rotate_c(my_ptrs_t* ptrs);

#endif /* MY_H_ */
