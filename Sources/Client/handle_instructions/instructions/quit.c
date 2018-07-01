/*
** EPITECH PROJECT, 2018
** PSU_myirc_2017
** File description:
** quit.c
*/

#include "../../../../Includes/client.h"

int		quit_server(t_client *Newclient)
{
	int	error = 0;

	if (Newclient->connected == true) {
		error = send_instruction(Newclient, Newclient->socket->fd);
		if (error == -1)
			write(0, "Sending failed\n", 14);
		if (close_socket(Newclient) == -1)
			return (-1);
	}
	else {
		write(0, "Can't disconnect if you are not connected\n", 43);
	}
	return (0);
}

int		quit(t_client *Newclient)
{
	if (close_socket(Newclient) == -1) {
		return (-1);
	}
	delete_client(Newclient);
	exit(0);
	return (0);
}
