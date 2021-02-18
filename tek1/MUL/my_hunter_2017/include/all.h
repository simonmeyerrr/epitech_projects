/*
** EPITECH PROJECT, 2017
** my_hunter
** File description:
** all includes
*/

/* CSFML lib */
#include <SFML/Audio.h>
#include <SFML/Graphics.h>
#include <time.h>
/* malloc and write lib */
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
/* read and open lib */
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
/* includes for my_hunter */
#include "struct.h"
#include "proto.h"
#include "../settings/settings.h"

#define	USAGE	"My hunter created by Simon Meyer with CSFML.\n\nUSAGE\n\t./my_\
hunter\n\nINTERCATION\n\tLEFT_CLICK\tselect button or shot on birds.\n\tSPACE\t\
put the game on pause.\n\tESCAPE\texit the game or the window.\n\nTHE GAME\nS\
hot birds to earn points. +10 for blue bird, +30 for yellow, +50 bonus for doub\
le shot.\nYou earn one life when you kill a yellow bird and you lose one when a\
 blue bird escape from the map.\nStage level up each 10 seconds and difficulty \
becomes harder.\n\n"

#define USAGE_LEN 452
