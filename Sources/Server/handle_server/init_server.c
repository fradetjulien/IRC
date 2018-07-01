/*
** EPITECH PROJECT, 2018
** PSU_myirc_2017
** File description:
** init_server.c
*/

#include "../../../Includes/server.h"

int		init_server(t_server *myserver, const char *port)
{
	myserver->socket = malloc(sizeof(t_socket));
	myserver->client = malloc(sizeof(t_client) * MAX_CLIENTS);
	if (myserver->socket == NULL || myserver->client == NULL)
		return (-1);
	myserver->port = atoi(port);
	myserver->clients = init_list();
	myserver->channel = init_list();
	if (myserver->clients == NULL || myserver->channel == NULL)
		return (-1);
	if (init_socket(myserver, "TCP") == -1)
		return (-1);
	if (bind_socket(myserver) == -1)
		return (-1);
	if (listen_socket(myserver) == -1)
		return (-1);
	myserver->alive = true;
	myserver->pos = 0;
	myserver->nb_client = 0;
	return (0);
}
