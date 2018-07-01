 /*
** EPITECH PROJECT, 2018
** PSU_myirc_2017
** File description:
** init_client.c
*/

#include "../../../Includes/server.h"

int		init_client(t_client *new_client)
{
	new_client->socket = malloc(sizeof(t_socket));
	if (new_client->socket == NULL)
		return (-1);
	new_client->nickname = NULL;
	new_client->connected = false;
	new_client->chatting = false;
	return (0);
}
