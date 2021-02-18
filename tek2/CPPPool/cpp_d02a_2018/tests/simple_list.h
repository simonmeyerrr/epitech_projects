/*
** EPITECH PROJECT, 2018
** cpp_d02a_2018
** File description:
** simple_list.h
*/

#ifndef CPP_D02A_2018_SIMPLE_LIST_H
#define CPP_D02A_2018_SIMPLE_LIST_H

typedef enum bool_e {
    FALSE,
    TRUE
} bool_t;

typedef struct node {
    double value;
    struct node *next;
} node_t;

typedef node_t *list_t;

unsigned int list_get_size(list_t list);
bool_t list_is_empty(list_t list);
void list_dump(list_t list);

bool_t list_add_elem_at_front(list_t *front_ptr, double elem);
bool_t list_add_elem_at_back(list_t *front_ptr, double elem);
bool_t list_add_elem_at_position(list_t *front_ptr, double elem,
unsigned int position);

bool_t list_del_elem_at_front(list_t *front_ptr);
bool_t list_del_elem_at_back(list_t *front_ptr);
bool_t list_del_elem_at_position(list_t *front_ptr, unsigned int position);

double list_get_elem_at_front(list_t list);
double list_get_elem_at_back(list_t list);
double list_get_elem_at_position(list_t list, unsigned int position);

node_t *list_get_first_node_with_value(list_t list, double value);

#endif //CPP_D02A_2018_SIMPLE_LIST_H
