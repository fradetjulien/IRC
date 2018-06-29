/*
** EPITECH PROJECT, 2018
** PSU_myirc_2017
** File description:
** bind_socket.c
*/

#include "../../../Includes/server.h"

int		bind_socket(t_server *myserver)
{
	myserver->socket->s.sin_family = AF_INET;
	myserver->socket->s.sin_addr.s_addr = INADDR_ANY;
	myserver->socket->s.sin_port = htons(myserver->port);
	if (bind(myserver->socket->fd,
	(const struct sockaddr *)&myserver->socket->s,
	sizeof(myserver->socket->s)) == -1) {
		if (errno == EADDRINUSE) {
			myserver->port++;
			bind_socket(myserver);
		}
		else {
			close_socket(myserver);
			write(2, "Bind failed\n", 14);
			return (-1);
		}
	}
	return (0);
}
