/*
** EPITECH PROJECT, 2018
** PSU_myirc_2017
** File description:
** client.c
*/

#include "../../../Includes/client.h"

int			main(int ac, char **av)
{
	t_client	Newclient;

	if (ac != 1 || strcmp(av[0], "./client") != 0) {
		help_client("./client");
		return (-1);
	}
	if (init_client(&Newclient) == -1)
		return (-1);
	launch_client(&Newclient);
	return (0);
}
