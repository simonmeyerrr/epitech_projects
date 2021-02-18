/*
** EPITECH PROJECT, 2017
** my_exec
** File description:
** main.c
*/

#include "all.h"

void my_putstr(char *str)
{
	int len = 0;

	while (str[len] != '\0')
		len++;
	write(1, str, len);
}

void my_put_nbr(int nb)
{
	int mod;

	if (nb < 0) {
		my_putstr("-");
		nb = -nb;
	}
	mod = nb % 10 + 48;
	if (nb > 9)
		my_put_nbr((nb - nb % 10)/ 10);
	write(1, &mod, 1);
}

void print_info(char **arg, pid_t child_pid)
{
	int arg_nb = 0;

	for (int i = 1 ; arg[i] != NULL ; i++)
		arg_nb++;
	my_putstr("Program name: ");
	my_putstr(arg[0]);
	my_putstr("\nNb args: ");
	my_put_nbr(arg_nb);
	my_putstr("\nPID: ");
	my_put_nbr(getpid());
	my_putstr("\nChild PID: ");
	my_put_nbr(child_pid);
	my_putstr("\n");
}

void print_status(int status)
{
	my_putstr("Program terminated.\nStatus: ");
	if (status == 0)
		my_putstr("OK\n");
	else
		my_putstr("Segmentation fault\n");
}

int main(int ac, char **av)
{
	char **arg;
	int status;
	pid_t child_pid = fork();
	pid_t pid = 0;

	if (ac != 2)
		return(EXIT_ERROR);
	arg = my_str_to_word_array(av[1]);
	if(!child_pid) {
		execve(arg[0], arg, 0);
	} else if (child_pid > 0) {
		print_info(arg, child_pid);
		pid = waitpid(child_pid, &status, 0);
		print_status(status);
	} else
		write(2, "error\n", 5);
	return (EXIT_SUCCESS);
}
