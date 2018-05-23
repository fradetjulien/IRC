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

char			**get_cmd(t_client *client, char *line, char **cmd)
{
	if (line[0] == '\0' || line == NULL)
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
	if (&client->read != NULL)
		FD_ZERO(&client->read);
	if (client->fd != -1) {
		FD_SET(client->fd, &client->write);
		FD_SET(client->fd, &client->read);
	}
}

int			loop_client(t_client *client)
{
	char		*line = NULL;
	char		**cmd = NULL;
	size_t		len = 0;
	t_buffer	*circular_buffer = create_buffer(circular_buffer);

	while (1) {
		display_prompt();
		line = get_next_line(0);
		set_fd_client(client);
		init_fds(client);
		if ((cmd = get_cmd(client, line, cmd)) == NULL) {
			loop_client(client);
		}
		if (cmd[0][0] == '/')
			parse_cmd(cmd, client, circular_buffer);
		else if (client->fd != -1)
			send_message(client, circular_buffer);
		else
			printf("This command doesn't exist\n");
	}
	return (0);
}
