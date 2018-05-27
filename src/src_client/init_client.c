/*
** EPITECH PROJECT, 2018
** my_irc
** File description:
** init_client.c
*/

#include "client.h"

t_client		*init_client(t_client *client)
{
	client = malloc(sizeof(t_client));
	if (client == NULL)
		return (NULL);
	client->protocol = NULL;
	client->port = -1;
	client->fd = -1;
	client->actif = 1;
	client->passif = 0;
	client->IP = NULL;
	return (client);
}
