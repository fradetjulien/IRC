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
	int	err = read(client->fd - 1, buff, 512);

	if (err == -1) {
		printf("Read failed\n");
		return (-1);
	}
	else
		buff[err - 2] = 0;
	client->actif = 1;
	return (0);
}
