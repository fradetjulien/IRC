/*
** EPITECH PROJECT, 2018
** PSU_myirc_2017
** File description:
** init_client.c
*/

#include "../../../Includes/client.h"

int		init_client(t_client *Newclient)
{
	Newclient->socket = malloc(sizeof(t_socket));
	if (Newclient->socket == NULL)
		return (-1);
	Newclient->connected = false;
	Newclient->socket->fd = -1;
	Newclient->protocol = NULL;
	Newclient->port = NULL;
	Newclient->host = NULL;
	Newclient->command = NULL;
	Newclient->answer = NULL;
	return (0);
}
