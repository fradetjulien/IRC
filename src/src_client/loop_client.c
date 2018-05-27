/*
** EPITECH PROJECT, 2018
** my_irc
** File description:
** loop_client.c
*/

#include "client.h"
#include "common.h"

char		**get_cmd(t_client *client, char *line, char **cmd)
{
	if (line && line[0] && line[0] == '\0' || line == NULL)
		return (NULL);
	else
		line = my_epur_str(line);
	if (line == NULL)
		return (NULL);
	else {
		client->cmd = strdup(line);
		if (client->cmd == NULL) {
			return (NULL);
		}
	}
	cmd = str_to_wordtab(line, ' ');
	if (cmd == NULL) {
		return (NULL);
	}
	return (cmd);
}

void			init_fds(t_client *client)
{
	if (&client->write != NULL)
		FD_ZERO(&client->write);
	if (&client->write != NULL)
		FD_ZERO(&client->read);
	FD_SET(0, &client->read);
	FD_SET(1, &client->write);
	FD_SET(client->fd, &client->read);
	FD_SET(client->fd, &client->write);
}

void			set_fd_client(t_client *client)
{
	display_prompt();
	if (client->fd == -1) {
		client->fd = 1;
	}
	init_fds(client);
}

int			loop_client(t_client *client)
{
	char		*line = NULL;
	size_t		len = 0;

	while (1) {
		set_fd_client(client);
		line = get_next_line(0);
		if ((select(client->fd + 1, &client->read,
		&client->write, NULL, NULL)) == -1) {
			printf("Select error\n");
			return (-1);
		}
		if (check_fd(client, line) == -1)
			return (-1);
	}
	return (0);
}
