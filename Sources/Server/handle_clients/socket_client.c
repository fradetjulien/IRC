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
	(struct sockaddr *)&server->socket->s,
	(unsigned int *)&new_client.socket->len);
	FD_SET(new_client.socket->fd, &server->read);
	server->client[server->pos] = new_client;
	server->pos++;
	server->nb_client++;
	dprintf(new_client.socket->fd, "Welcome\n");
	return (0);
}
