/*
** EPITECH PROJECT, 2018
** my_irc
** File description:
** parsing.c
*/

#include "client.h"

int		parsing(t_client *client, char *line)
{
	char	**cmd = NULL;

	if (init_socket(client, "TCP") == -1) {
		printf("Cannot initialize the connection\n");
		return (-1);
	}
	if ((cmd = get_cmd(client, line, cmd)) == NULL) {
		loop_client(client);
	}
	if (cmd[0][0] == '/')
		parse_cmd(cmd, client);
	else if (client->fd != -1)
		send_message(client);
	else
		printf("This command doesn't exist\n");
	return (0);
}