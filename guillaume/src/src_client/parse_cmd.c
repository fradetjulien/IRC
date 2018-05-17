/*
** EPITECH PROJECT, 2018
** my_irc
** File description:
** parse_cmd.c
*/

#include "client.h"

void		init_fct(int (**ptrf)(t_client *client, char **cmd))
{
	ptrf[0] = &connection_server;
	ptrf[1] = &send_to_server;
	ptrf[2] = &send_to_server;
	ptrf[3] = &send_to_server;
	ptrf[4] = &send_to_server;
	ptrf[5] = &send_to_server;
	ptrf[6] = &send_to_server;
	ptrf[7] = &send_to_server;
	ptrf[8] = &send_to_server;
	ptrf[9] = &quit_server;
	ptrf[10] = NULL;
}

int		parse_cmd(char **cmd, t_client *client)
{
	char	*cmd_client[11];
	int	(*ptrf[11])(t_client *client, char **cmd);
	int	i = -1;

	list_cmd(cmd_client);
	init_fct(ptrf);
	while (cmd_client[++i] != NULL) {
		if (strcmp(cmd_client[i], cmd[0]) != 0) {
			ptrf[i](client, cmd);
		}
	}
	return (0);
}
