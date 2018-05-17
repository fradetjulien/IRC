/*
** EPITECH PROJECT, 2018
** my_irc
** File description:
** fct_socket.c
*/

#include "client.h"

int		listen_socket(t_client *client)
{
	int	error = 0;

	error = listen(client->fd, SOMAXCONN);
	if (error == -1) {
		close_socket(client);
		return (-1);
	}
	return (0);
}

int		bind_socket(t_client *client)
{
	int	error = 0;

	error = bind(client->fd, (const struct sockaddr *)&client->s,
		     sizeof(client->s));
	if (error == -1) {
		close_socket(client);
		return (-1);
	}
	return (0);
}

int		close_socket(t_client *client)
{
	if (close(client->fd) == -1) {
		return (-1);
	}
	client->fd = -1;
	return (0);
}

int		init_socket(t_client *client, int port, const char *protocol
			    , in_addr_t addr)
{
	client->port = port;
	client->protocol = getprotobyname("TCP");
	if (client->protocol == NULL)
		return (-1);
	client->fd = socket(AF_INET, SOCK_STREAM, client->protocol->p_proto);
	if (client->fd == -1)
		return (-1);
	client->s.sin_family = AF_INET;
	client->s.sin_port = htons(port);
	client->s.sin_addr.s_addr = addr;
	return (0);
}
