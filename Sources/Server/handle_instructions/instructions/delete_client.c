/*
** EPITECH PROJECT, 2018
** PSU_myirc_2017
** File description:
** delete_client.c
*/

#include "../../../../Includes/server.h"

int		print_yo(t_server *myserver)
{
	printf("%s\n", myserver->received);
	return (0);
}

int		delete_client(t_server *myserver)
{
	int	client = myserver->socket->fd;

	if (close(myserver->client->socket->fd) == -1) {
		write(2, "Can't close the socket\n", 24);
		return (-1);
	}
	printf("Client %d disconnected\n", client);
	myserver->socket->fd--;
	myserver->nb_client--;
	return (0);
}
