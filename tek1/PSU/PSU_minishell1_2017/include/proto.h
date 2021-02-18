/*
** EPITECH PROJECT, 2017
** minishell1
** File description:
** proto.h
*/

/* free */
void my_free(void *ptr);
void my_free_tab(char **tab);
void verif_malloc(void *ptr);
void remove_var_env(var_env_t *var, my_env_t *env);
int free_my_env(my_env_t *env);

/* my_env */
my_env_t *init_env(char **env);
static void add_env(my_env_t *env, char *str);
void add_new_env_var(my_env_t *env, char *name, char *value);
char **my_env_to_tab(my_env_t *env);

/* str_function */
int my_strlen(char *str);
int my_strcmp(char *s1, char *s2);
char *my_strdup(char *str);
char *my_putstr_fd(char *str, int fd, int back);
char *get_next_line(int fd);
char **my_str_to_word_array(char *str, char c);

/* execution */
void search_exec(char **tab, my_env_t *env);
void my_cd(char **tab, my_env_t *env);
void my_setenv(char **tab, my_env_t *env);
void my_unsetenv(char **tab, my_env_t *env);
void my_disp_env(char **tab, my_env_t *env);
