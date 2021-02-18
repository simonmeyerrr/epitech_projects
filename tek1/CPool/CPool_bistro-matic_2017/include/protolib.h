/*
** EPITECH PROJECT, 2017
** protolib.h
** File description:
** prototypes of lib's functions
*/

#ifndef PROTOLIB_H_
#define PROTOLIB_H_

void my_putchar(char);
void my_putstr(char *);
int my_getnbr(char *);
int my_strlen(char *);
int priolevel(char);
int my_charisope(char);
int nblen(char *, int);
void my_rev_rpn(rpn_t **);
int my_strcmp(char const *, char const *);
void put_zero(char **, char **);
char *put_zero2(char *, char *, int, int);
int my_rpn_size(rpn_t *);
char *my_revstr(char *);
char *epur_str(char *);

#endif /* PROTOLIB_H_ */
