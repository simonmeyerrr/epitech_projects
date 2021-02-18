/*
** EPITECH PROJECT, 2018
** PSU_2018_malloc
** File description:
** thread.c
*/

#include <pthread.h>

static pthread_mutex_t *get_mutex(void)
{
    static pthread_mutex_t thread = PTHREAD_MUTEX_INITIALIZER;
    static pthread_mutex_t *ptr = &thread;

    return (ptr);
}

void my_lock_thread(void)
{
    pthread_mutex_lock(get_mutex());
}

void my_unlock_thread(void)
{
    pthread_mutex_unlock(get_mutex());
}