/*
** EPITECH PROJECT, 2018
** my_irc
** File description:
** other_socket.c
*/

#include "client.h"

int		connect_socket(t_client *client)
{
	int	error = 0;

	error = connect(client->fd, (const struct sockaddr *)&client->s,
			sizeof(client->s));
	if (error == -1) {
		close_socket(client);
		return (-1);
	}
	return (0);
}

int			accept_socket(t_client *client, struct sockaddr_in *s_client)
{
	int		client_fd = 0;
	socklen_t	s_size;

	s_size = sizeof(*s_client);
	client_fd = accept(client->fd, (struct sockaddr *)s_client, &s_size);
	if (client_fd == -1) {
		close_socket(client);
		return (-1);
	}
	return (0);
}
