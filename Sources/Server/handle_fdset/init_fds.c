/*
** EPITECH PROJECT, 2018
** PSU_myirc_2017
** File description:
** init_fds.c
*/

#include "../../../Includes/server.h"

void		init_fds(t_server *server)
{
	int	i = 0;

	if (&server->read != NULL)
		FD_ZERO(&server->read);
	if (&server->write != NULL)
		FD_ZERO(&server->write);
	FD_SET(0, &server->read);
	FD_SET(0, &server->write);
	FD_SET(server->socket->fd, &server->read);
	for (i = 0; (i < server->nb_client) && (i < MAX_CLIENTS); i++)
		FD_SET(server->client[i].socket->fd, &server->read);
	server->time.tv_sec = 0;
	server->time.tv_usec = 5000;
}
