/*
** EPITECH PROJECT, 2017
** my_ls
** File description:
** proto.h
*/

void disp_info(struct stat buf, flags_t* flag);
void my_putstr(char* str);
int my_strlen(char* str);
int my_putnbr(unsigned int nb);
int my_nbr_len(unsigned int nbr);
void ls_d(flags_t* flag, int ac, char **av);
char* create_path(char* s1, char* s2);
void disp_d(char* path, flags_t* flag);
void prepare_normal(char* path, flags_t* flag);
void search_len_d2(flags_t* flag, char* path);
void ls_normal(flags_t* flag, int ac, char** av);
void search_len_normal(char* path, flags_t* flag);
void disp_normal(char* path, flags_t* flag);
