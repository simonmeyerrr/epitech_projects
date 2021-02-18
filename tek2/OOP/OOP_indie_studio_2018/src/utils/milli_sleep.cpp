/*
** EPITECH PROJECT, 2018
** OOP_indie_studio_2018
** File description:
** milli_sleep.c
*/

#ifdef WIN32

    #include <windows.h>

#else /* not WIN32 */

    #include <unistd.h>

#endif /* WIN32 */

void my_milli_sleep(int milliseconds)
{
    #ifdef WIN32
    Sleep(milliseconds);
    #else /* not WIN32 */
    usleep(milliseconds * 1000);
    #endif /* WIN32 */
}