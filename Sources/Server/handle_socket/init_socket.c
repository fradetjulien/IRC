/*
** EPITECH PROJECT, 2018
** PSU_myirc_2017
** File description:
** init_socket.c
*/

#include "../../../Includes/server.h"

int		init_socket(t_server *myserver, const char *protocol)
{
	myserver->protocol = getprotobyname(protocol);
	if (myserver->protocol == NULL) {
		write(2, "Wrong protocol\n", 16);
		return (-1);
	}
	myserver->socket->fd = socket(AF_INET, SOCK_STREAM,
	myserver->protocol->p_proto);
	if (myserver->socket->fd == SOCKET_ERROR) {
		write(2, "Can not create a socket\n", 25);
		return (-1);
	}
	return (0);
}
