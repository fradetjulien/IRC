/*
** EPITECH PROJECT, 2018
** my_irc
** File description:
** quit_server.c
*/

#include "client.h"
#include "common.h"

int		quit_server(t_client *client, char **cmd, t_buffer *buffer)
{
	if ((close(client->fd)) == -1) {
		printf("FAILED\n");
		return (-1);
	}
	free(client->IP);
	free(client->cmd);
	free(client->protocol);
	free(client);
	return (0);
}
