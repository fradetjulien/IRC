/*
** EPITECH PROJECT, 2018
** PSU_myirc_2017
** File description:
** server.c
*/

#include "../../../Includes/server.h"

int			main(int ac, char **av)
{
	t_server	server;

	if (ac != 2 || strcmp(av[0], "./server") ||
	is_port(av[1]) == -1) {
		help_server("./server");
		return (84);
	}
	if (init_server(&server, av[1]) == -1)
		return (84);
	return (0);
}
