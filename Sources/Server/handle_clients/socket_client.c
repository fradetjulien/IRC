/*
** EPITECH PROJECT, 2018
** PSU_myirc_2017
** File description:
** socket_client.c
*/

#include "../../../Includes/server.h"

int				socket_client(t_server *server)
{
	t_client		new_client;

	init_client(&new_client);
	new_client.socket->fd = accept(server->socket->fd,
	(struct sockaddr *)&new_client.socket->s,
	&new_client.socket->len);
	if (new_client.socket->fd == -1) {
		return (1);
	}
	FD_SET(new_client.socket->fd, &server->read);
	if (new_client.socket->fd > server->socket->fd)
		server->socket->fd = new_client.socket->fd;
	server->client[server->pos] = new_client;
	server->pos++;
	server->nb_client++;
	server->socket->fd_max = server->socket->fd + 1;
	printf("Client number %d connected\n", new_client.socket->fd);
	server->received = strdup("Welcome\n");
	if (send_instruction(server, server->socket->fd) == -1)
		return (-1);
	return (0);
}
