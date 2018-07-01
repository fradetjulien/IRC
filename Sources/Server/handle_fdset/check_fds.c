/*
** EPITECH PROJECT, 2018
** PSU_myirc_2017
** File description:
** check_fds.c
*/

#include "../../../Includes/server.h"
#include "../../../Includes/library.h"

int		check_fds(t_server *myserver)
{
	int	error = 0;

	if (FD_ISSET(0, &myserver->read) == true)
		return (0);
	if (FD_ISSET(myserver->socket->fd, &myserver->read) == true) {
		error = socket_client(myserver);
		if (error == -1)
			return (-1);
		error = read_instruction(myserver->socket->fd, myserver);
		if (error != 0)
			return (1);
		parse_instruction(myserver);
	}
	return (0);
}
