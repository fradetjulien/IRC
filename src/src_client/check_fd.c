/*
** EPITECH PROJECT, 2018
** my_irc
** File description:
** check_fd.c
*/

#include "client.h"
#include "common.h"

int		check_fd(t_client *client, char *line)
{
	char	**cmd = NULL;

	if (FD_ISSET(client->fd, &client->read)) {
		read_from_server(client);
	}
	if (FD_ISSET(client->fd, &client->write)) {
		parsing(client, line, cmd);
		if (client->actif == 0)
			read_from_server(client);
	}
	return (0);
}
