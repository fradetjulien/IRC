/*
** EPITECH PROJECT, 2018
** PSU_myirc_2017
** File description:
** close_socket.c
*/

#include "../../../Includes/client.h"

int		close_socket(t_client *Newclient)
{
	if (close(Newclient->socket->fd) == -1) {
		return (-1);
	}
	Newclient->socket->fd = -1;
	return (0);
}
