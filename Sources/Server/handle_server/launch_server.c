/*
** EPITECH PROJECT, 2018
** PSU_myirc_2017
** File description:
** launch_server.c
*/

#include "../../../Includes/server.h"

int		launch_server(t_server *myserver)
{
	int	fd_max = myserver->socket->fd + 1;

	if (fd_max == -1)
		return (-1);
	while (myserver->alive == true) {
		init_fds(myserver);
		if (select(fd_max, &myserver->read,
		&myserver->write, NULL, myserver->time) == -1) {
			write(2, "Select error\n", 15);
			return (-1);
		}
		if (check_fds(myserver) == -1)
			return (-1);
	}
	return (0);
}
