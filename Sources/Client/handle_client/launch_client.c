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

	if (wait_connection(Newclient) == -1)
		return (-1);
	while (launcher) {
		init_fds(Newclient->socket->fd, &Newclient->read,
		&Newclient->write, &time);
		if (select(fd_max, &Newclient->read,
		&Newclient->write, NULL, &time) == -1) {
			write(2, "Select error\n", 14);
			return (-1);
		}
		if (check_fds(Newclient) == -1)
			return (-1);
	}
	if (close_socket(Newclient) == -1)
		return (-1);
	return (0);
}
