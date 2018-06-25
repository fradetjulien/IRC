/*
** EPITECH PROJECT, 2018
** PSU_myirc_2017
** File description:
** init_socket.c
*/

#include "../../../Includes/client.h"

int		init_socket(t_client *Newclient, const char *protocol)
{
	Newclient->protocol = getprotobyname(protocol);
	if (Newclient->protocol == NULL) {
		dprintf(2, "Wrong protocol\n");
		return (-1);
	}
	Newclient->socket->fd = socket(AF_INET, SOCK_STREAM,
	Newclient->protocol->p_proto);
	if (Newclient->socket->fd == -1) {
		dprintf(2, "Can not create a socket\n");
		return (-1);
	}
	return (0);
}
