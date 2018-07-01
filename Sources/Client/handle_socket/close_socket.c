/*
** EPITECH PROJECT, 2018
** PSU_myirc_2017
** File description:
** close_socket.c
*/

#include "../../../Includes/client.h"

int		close_socket(t_client *Newclient)
{
	if (Newclient->connected == true) {
		if (close(Newclient->socket->fd) == -1) {
			write(2, "Can't close the socket\n", 25);
			return (-1);
		}
		Newclient->socket->fd = -1;
		Newclient->connected = false;
		write(0, "Successfully disconnected\n", 27);
	}
	return (0);
}
