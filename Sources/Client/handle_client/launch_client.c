/*
** EPITECH PROJECT, 2018
** PSU_myirc_2017
** File description:
** launch_client.c
*/

#include "../../../Includes/client.h"

int			launch_client(t_client *Newclient)
{
	struct timeval	time;
	int		launcher = 1;
	int		fd_max = Newclient->socket->fd + 1;

	wait_connection(Newclient);
	while (launcher) {
		init_fds(Newclient->socket->fd, &Newclient->read,
		&Newclient->write, &time);
		if (select(fd_max, &Newclient->read,
		&Newclient->write, NULL, &time) == -1) {
			dprintf(2, "Select error\n");
			return (-1);
		}
		if (check_fds(Newclient, fd_max) == -1)
			return (-1);
	}
	return (0);
}
