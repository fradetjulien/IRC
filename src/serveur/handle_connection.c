/*
** EPITECH PROJECT, 2018
** my_irc
** File description:
** handle_connection.c
*/

#include "serveur.h"

int		handle_connection(t_serveur *serveur)
{
	int	i = -1;
	int	sock = 0;

	while (++i < MAX - 1)
		serveur->cfdl[i] = 0;
	if ((serveur->protocol = getprotobyname("TCP")) == NULL)
		return (-1);
	if ((serveur->fd = socket(AF_INET, SOCK_STREAM,
				  serveur->protocol->p_proto)) == -1)
		return (-1);
	if (setsockopt(serveur->fd, SOL_SOCKET, SO_REUSEADDR, (char *)&sock,
		       sizeof(sock)) == -1)
		return (-1);
	if (bind(serveur->fd, (const struct sockaddr*)&serveur->s_in,
		 sizeof(serveur->s_in)) == -1)
		return (-1);
	if (listen(serveur->fd, 42) == -1)
		return (-1);
	serveur->s_in_size = sizeof(serveur->s_in);
	return (0);
}
