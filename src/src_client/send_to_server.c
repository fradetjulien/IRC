/*
** EPITECH PROJECT, 2018
** my_irc
** File description:
** send_to_server.c
*/

#include "client.h"
#include "common.h"

int		send_to_server(t_client *client, char **cmd, t_buffer *buffer)
{
	int	error = 0;
	char	*buff = strdup(client->cmd);

	if (buff == NULL) {
		return (-1);
	}
	printf("FIRST PASS, Buff : %s\nFD : %d\n", buff, client->fd);
	/*if (FD_ISSET(client->fd, &client->write)) {
	  printf("PASSED\n");*/
	error = write(client->fd, buff, strlen(buff) );
		if (error == -1) {
			printf("WRITE ERROR\n");
			return (-1);
		}
	return (0);
}
