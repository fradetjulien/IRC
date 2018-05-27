/*
** EPITECH PROJECT, 2018
** my_irc
** File description:
** quit_server.c
*/

#include "client.h"
#include "common.h"

int		quit_server(t_client *client, char **cmd)
{
	if ((close(client->fd)) == -1) {
		printf("Close failed\n");
		return (-1);
	}
	free(client->IP);
	free(client->cmd);
	free(client);
	return (0);
}
