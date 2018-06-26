/*
** EPITECH PROJECT, 2018
** PSU_myirc_2017
** File description:
** connect_server.c
*/

#include "../../../Includes/client.h"

int		connect_socket(t_client *Newclient)
{
	Newclient->socket->s.sin_family = AF_INET;
	Newclient->socket->s.sin_addr.s_addr = inet_addr(Newclient->host);
	Newclient->socket->s.sin_port = htons(atoi(Newclient->port));
	if (connect(Newclient->socket->fd,
	(const struct sockaddr *)&Newclient->socket->s,
	sizeof(Newclient->socket->s))  == SOCKET_ERROR) {
		write(2, "Can not establish connection\n", 30);
		close_socket(Newclient);
		return (-1);
	}
	return (0);
}
