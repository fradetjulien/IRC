/*
** EPITECH PROJECT, 2018
** my_irc
** File description:
** read_from_server.c
*/

#include "client.h"

int		read_from_server(t_client *client)
{
	char	buff[512];
	int	o;

	if (FD_ISSET(client->fd, &client->read)) {
		o = read(client->fd, buff, 512);
		buff[o] = 0;
		printf("Buff : %s\n", buff);
	}
	return (0);
}
