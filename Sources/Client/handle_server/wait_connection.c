/*
** EPITECH PROJECT, 2018
** PSU_myirc_2017
** File description:
** wait_connection.c
*/

#include "../../../Includes/client.h"

int		wait_connection(t_client *Newclient)
{
	int	error = 0;

	while (Newclient->socket->fd == -1) {
		if (read_instruction(0, Newclient) == -1) {
			write(2, "Can't read on this fd\n", 23);
			return (-1);
		}
		error = is_writearguments(Newclient);
		if (error == 0) {
			error = connection_server(Newclient);
		}
	}
	return (error);
}
