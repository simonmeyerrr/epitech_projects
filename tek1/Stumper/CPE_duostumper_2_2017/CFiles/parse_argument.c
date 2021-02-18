/*
** EPITECH PROJECT, 2017
** my_ginger
** File description:
** parse_argument.c
*/

#include "../include/all.h"

static int my_get_nbr(char *str)
{
	int nb = 0;
	int sign = 1;
	int i = 0;

	while (str && (str[i] == '-' || str[i] == '+')) {
		if (str[i] == '-')
			sign = -sign;
		i++;
	}
	while (str && str[i]) {
		nb = nb * 10 + str[i] - '0';
		i++;
	}
	return (sign * nb);
}
static void create_map(ginger_t *ginger, char *path)
{
	int fd = open(path, O_RDONLY);
	struct stat file;
	char *buffer;

	if (fd < 0 || stat(path, &file) == -1) {
		write(2, "Can't open the file.\n", 21);
		exit(84);
	}
	buffer = malloc(sizeof(char) * (file.st_size) + 1);
	verif_malloc(buffer);
	if (read(fd, buffer, file.st_size) == -1) {
		write(2, "Error while read the file.\n", 27);
		exit(MY_ERROR);
	}
	buffer[file.st_size] = '\0';
	ginger->map = str_to_tab(buffer, "\n");
	my_free(buffer);
	close(fd);
}

static void get_move_init(ginger_t *ginger, char *arg)
{
	int i = 0;

	for (i ; arg && arg[i] == '+' || arg[i] == '-' ; i++);
	for (i ; arg && arg[i] >= '0' && arg[i] <= '9' ; i++);
	if (!arg || arg[i] != '\0') {
		write(2, "The number is not valid.\n", 25);
		exit(84);
	}
	ginger->move_init = my_get_nbr(arg);
	if (ginger->move_init <= 0) {
		write(2, "The number should be higher than 0.\n", 36);
		exit(84);
	}
	ginger->move_points = ginger->move_init;
}

static void manage_flag(ginger_t *ginger, char *flag, char *arg)
{
	if (strcmp(flag, "-f") == 0 && !ginger->map)
		create_map(ginger, arg);
	else if (strcmp(flag, "-m") == 0 && ginger->move_init < 0)
		get_move_init(ginger, arg);
	else {
		write(2, "Invalid flag or several using of a single flag.\n",
		48);
		exit(MY_ERROR);
	}
}

void parse_argument(ginger_t *ginger, int ac, char **av)
{
	if (ac != 5) {
		write(2, "Invalid number of argument.\n", 28);
		exit(MY_ERROR);
	}
	manage_flag(ginger, av[1], av[2]);
	manage_flag(ginger, av[3], av[4]);
	if (!ginger->map || !ginger->map[0] || my_strlen(ginger->map[0]) == 0) {
		write(2, "The map is empty.\n", 18);
		exit(MY_ERROR);
	}
}
