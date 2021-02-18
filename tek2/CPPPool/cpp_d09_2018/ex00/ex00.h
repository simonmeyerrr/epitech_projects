/*
** EPITECH PROJECT, 2018
** cpp_d09_2018
** File description:
** ex00.h
*/

#ifndef CPP_D09_2018_EX00_H_
# define CPP_D09_2018_EX00_H_

typedef struct s_cthulhu {
    int m_power;
    char *m_name;
} cthulhu_t;

cthulhu_t *new_cthulhu();
void print_power(cthulhu_t *);
void attack(cthulhu_t *);
void sleeping(cthulhu_t *);


typedef struct s_koala {
    cthulhu_t m_parent;
    char m_is_a_legend;
} koala_t;

koala_t *new_koala(char *, char);
void eat(koala_t *);

#endif /* CPP_D09_2018_EX00_H_ */
