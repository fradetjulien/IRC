/*
** EPITECH PROJECT, 2018
** my_irc
** File description:
** send_to_server.c
*/

#include "client.h"
#include "common.h"

int		send_to_server(t_client *client, char **cmd)
{
	int	error = 0;
	char	*buff = strdup(client->cmd);

	if (buff == NULL) {
		return (-1);
	}
	if (client->fd != -1)
		error = write(client->fd - 1, buff, strlen(buff));
	if (error == -1) {
		printf("WRITE ERROR\n");
		return (-1);
	}
	client->actif = 0;
	return (0);
}
