/*
** EPITECH PROJECT, 2017
** struct
** File description:
** struct evalexpr
*/

#ifndef STRUCT_H_
#define STRUCT_H_

typedef struct struct_rpn
{
	char *nb;
	char ope;
	struct struct_rpn *next;
} rpn_t;

typedef struct struct_ope
{
	char ope;
	struct struct_ope *next;
} ope_t;

typedef struct s_mult {
	int i;
	int j;
	int k;
	int ret;
} t_mult;

#endif /* STRUCT_H_ */
