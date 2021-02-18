/*
** EPITECH PROJECT, 2018
** cpp_d02m_2018
** File description:
** mem_ptr.h
*/

#ifndef CPP_D02M_2018_MEM_PTR_H
    #define CPP_D02M_2018_MEM_PTR_H

typedef struct str_op_s {
    const char *str1;
    const char *str2;
    char *res;
} str_op_t;

int my_strlen(char const *str);
void add_str(const char *str1, const char *str2, char **res);
void add_str_struct(str_op_t *str_op);

#endif //CPP_D02M_2018_MEM_PTR_H
