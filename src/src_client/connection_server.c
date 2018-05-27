/*
** EPITECH PROJECT, 2018
** my_irc
** File description:
** connection_server.c
*/

#include "client.h"
#include "common.h"

int		check_arguments(char *IP, char *port, t_client *client)
{
	int	p = 0;

	if ((IP != NULL && is_numbis(IP) == 0) &&
	(port != NULL && is_num(port) == 0)) {
		client->IP = strdup(IP);
		if (client->IP == NULL) {
			return (-1);
		}
		p = atoi(port);
		return (p);
	}
	else {
		display_cmd();
		return (-1);
	}
}

int		connection_server(t_client *client, char **cmd)
{
	int	port = 0;

	if ((port = check_arguments(cmd[1], cmd[2], client)) == -1) {
		return (-1);
	}
	if (client->IP == NULL) {
		return (-1);
	}
	if (connect_socket(client, port, inet_addr(client->IP)) == -1) {
		printf("Impossible to connect to the server\n");
		return (-1);
	}
	return (0);
}
