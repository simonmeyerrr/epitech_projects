/*
** EPITECH PROJECT, 2018
** cpp_d02m_2018
** File description:
** func_ptr.h
*/

#ifndef CPP_D02M_2018_FUNC_PTR_H
    #define CPP_D02M_2018_FUNC_PTR_H

typedef enum action_e {
    PRINT_NORMAL,
    PRINT_REVERSE,
    PRINT_UPPER,
    PRINT_42
} action_t;

void print_normal(const char *str);
void print_reverse(const char *str);
void print_upper(const char *str);
void print_42(const char *str);
void do_action(action_t action, const char *str);

#endif //CPP_D02M_2018_FUNC_PTR_H
