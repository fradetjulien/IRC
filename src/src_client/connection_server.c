/*
** EPITECH PROJECT, 2018
** my_irc
** File description:
** connection_server.c
*/

#include "client.h"
#include "common.h"

int		connection_server(t_client *client, char **cmd, t_buffer *buffer)
{
	int	port = atoi(cmd[2]);

	client->IP = strdup(cmd[1]);
	if (client->IP == NULL)
		return (-1);
	if ((init_socket(client, port, "TCP", inet_addr(client->IP))) == -1) {
		printf("Cannot initialize the connection\n");
		return (-1);
	}
	if ((connect_socket(client)) == -1) {
		printf("Impossible to connect to the server\n");
		return (-1);
	}
	return (0);
}
