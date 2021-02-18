/*
** EPITECH PROJECT, 2017
** protofonc.h
** File description:
** prototype of functions
*/

#include "struct.h"

#ifndef PROTOFONC_H_
#define PROTOFONC_H_

/* bistro */
char *originbase(char *, char *, char *);
char *modifbase(char *, char *, char *);
char *modifchar(char *, char *, char *);
char compchange(char, char, char);
/* evalexpr */
char *eval_expr(char *);
void my_rpn(char *, rpn_t **);
int apply_neg(rpn_t **, ope_t **, char);
void add_ope(rpn_t **, ope_t **, char);
int nbr_to_rpn(rpn_t **, char *, int);
void ope_to_rpn(rpn_t **, ope_t **);
void ope_to_rpn2(rpn_t **, ope_t **);
char *my_resolve(rpn_t *);
void calcul(rpn_t **);
char *doop(char *, char *, char);
char *prepresult(char *);
/* addinf */
char *addinf(char *, char *);
char *infin_add(char *, char *);
char *add_pos(char *, char *);
char *add_pos2(char *, char *, int *);
void prep_add(char **, char **);
int place_last(char *, int);
char *redirection(char *, char *);
char *calc_min(char *, char *, char);
int compare_str(char *, char *);
void prepare_add(char **, char **);
int longer_str(char *, char *);
int nb_isvalid(char *);
/* multinf */
char *multinf(char *, char *);
char do_mult(char, char, t_mult *, char);
int is_longest(char *, char *);
/* subinf */
char *subinf(char *, char *);
char *infin_sub(char *, char *);

#endif /* PROTOFONC_H_ */
