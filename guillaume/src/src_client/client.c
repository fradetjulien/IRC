/*
** EPITECH PROJECT, 2018
** my_irc
** File description:
** client.c
*/

#include "client.h"

int			main(int ac, char **av)
{
	t_client	*client = NULL;
	int		error = 0;

	if (ac != 1) {
		help_client(av[0]);
		return (-1);
	}
	display_cmd();
	client = init_client(client);
	if (client == NULL)
		return (-1);
	error = loop_client(client);
	if (error == -1) {
		printf("Error detected\n");
		return (-1);
	}
	return (0);
}
