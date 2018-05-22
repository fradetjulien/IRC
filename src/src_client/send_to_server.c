/*
** EPITECH PROJECT, 2018
** my_irc
** File description:
** send_to_server.c
*/

#include "client.h"
#include "common.h"

int		send_to_server(t_client *client, t_buffer *buffer)
{
	write_into_buffer(buffer, client->cmd);
	return (0);
}
