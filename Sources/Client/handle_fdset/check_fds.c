/*
** EPITECH PROJECT, 2018
** PSU_myirc_2017
** File description:
** check_fds.c
*/

#include "../../../Includes/client.h"

int		is_welcome(char *str)
{
	if (strcmp(str, "Welcome\n") == 0)
		my_putstr(str);
	return (0);
}


int		check_fds(t_client *Newclient)
{
	int	error = 0;

	if (FD_ISSET(0, &Newclient->read) == true) {
		error = read_instruction(0, Newclient);
		if (error == -1)
			return (-1);
		else if (error == 0)
			parse_instruction(Newclient);
	}
	if (FD_ISSET(Newclient->socket->fd, &Newclient->read) == true) {
		error = read_instruction(Newclient->socket->fd, Newclient);
		is_welcome(Newclient->answer);
		if (error != 0)
			return (-1);
		//error = send_instruction(Newclient, 0);
		}
	return (error);
}
