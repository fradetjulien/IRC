/*
** EPITECH PROJECT, 2018
** PSU_myirc_2017
** File description:
** check_fds.c
*/

#include "../../../Includes/client.h"

int		check_fds(t_client *Newclient)
{
	int	error = 0;

	if (FD_ISSET(0, &Newclient->read) == true) {
		read_instruction(0, Newclient);
		error = parse_instruction(Newclient);
	}
	if (FD_ISSET(Newclient->socket->fd, &Newclient->read) == true &&
	error == 0) {
		read_instruction(Newclient->socket->fd, Newclient);
		error = send_instruction(Newclient, 0);
	}
	return (error);
}
