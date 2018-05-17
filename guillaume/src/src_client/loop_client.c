/*
** EPITECH PROJECT, 2018
** my_irc
** File description:
** loop_client.c
*/

#include "client.h"
#include "common.h"

void			set_fd_client(t_client *client)
{
	if (client->fd == -1) {
		client->fd = 1;
	}
	else {
		client->fd = client->fd + 1;
	}
}

char			**get_cmd(char *line, char **cmd)
{
	line = my_epur_str(line);
	if (line == NULL) {
		return (NULL);
	}
	cmd = str_to_wordtab(line, ' ');
	if (cmd == NULL) {
		return (NULL);
	}
	return (cmd);
}

void			init_fds(t_client *client, struct timeval *time)
{
	if (&client->write != NULL)
		FD_ZERO(&client->write);
	if (&client->read != NULL)
		FD_ZERO(&client->read);
	if (client->fd != -1) {
		FD_SET(0, &client->write);
		FD_SET(0, &client->read);
	}
	time->tv_sec = 1;
	time->tv_usec = 0;
}

int			loop_client(t_client *client)
{
	struct timeval	timeout;
	char		*line = NULL;
	char		**cmd;
	size_t		len = 0;

	while (line = get_next_line(0)) {
		init_fds(client, &timeout);
		cmd = get_cmd(line, cmd);
		display_prompt();
		set_fd_client(client);
		if ((select(client->fd, &client->read, &client->write,
			    NULL, NULL)) == -1) {
			return (-1);
		}
		if (cmd[0][0] == '/')
			parse_cmd(cmd, client);
		else
			send_message(cmd, client);
	}
	return (0);
}
