/*
** EPITECH PROJECT, 2018
** PSU_myirc_2017
** File description:
** connection_server.c
*/

#include "../../../Includes/client.h"
#include "../../../Includes/library.h"

int		connection_server(t_client *Newclient)
{
	if (Newclient->socket->fd == -1 && Newclient->connected == false) {
		if (init_socket(Newclient, "TCP") == -1)
			return (-1);
		if (connect_socket(Newclient) == -1)
			return (-1);
		Newclient->connected = true;
	}
	else {
		my_putstr("Already connected, please disconnect first\n");
	}
	return (0);
}
