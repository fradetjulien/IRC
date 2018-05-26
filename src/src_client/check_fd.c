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
	if (FD_ISSET(client->fd, &client->read)) {
		printf("READ ACTIF\n");
		read_from_server(client);
	}
	else if (FD_ISSET(client->fd, &client->write)) {
		printf("WRITE ACTIF\n");
		parsing(client, line);
		if (client->actif == 0)
			read_from_server(client);
	}
	else
		printf("Neither read or write\n");
	return (0);
}
