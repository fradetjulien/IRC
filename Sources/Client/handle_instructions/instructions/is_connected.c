/*
** EPITECH PROJECT, 2018
** PSU_myirc_2017
** File description:
** is_connected.c
*/

#include "../../../../Includes/client.h"

int		is_connected(t_client *Newclient)
{
	int	error = 0;

	if (Newclient->socket->fd != -1 &&
	Newclient->connected == true) {
		error = send_instruction(Newclient, Newclient->socket->fd);
		if (error == -1)
			return (-1);
	}
	return (0);
}
