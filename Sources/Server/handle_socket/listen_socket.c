/*
** EPITECH PROJECT, 2018
** PSU_myirc_2017
** File description:
** listen_socket.c
*/

#include "../../../Includes/server.h"

int		listen_socket(t_server *myserver)
{
	if (listen(myserver->socket->fd, 42) == -1) {
		close_socket(myserver);
		write(2, "Listen failed\n", 16);
		return (-1);
	}
	return (0);
}
