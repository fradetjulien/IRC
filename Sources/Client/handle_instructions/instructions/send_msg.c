/*
** EPITECH PROJECT, 2018
** PSU_myirc_2017
** File description:
** send_msg.c
*/

#include "../../../../Includes/client.h"

int		send_msg(t_client *Newclient)
{
	int	error = 0;

	if (is_nickname(Newclient->command[1]) == true &&
	is_achannel(Newclient->command[2]) == true &&
	Newclient->command[3] == NULL) {
		error = send_instruction(Newclient, Newclient->socket->fd);
		if (error == -1)
			return (-1);
	}
	else if (is_nickname(Newclient->command[1]) == true &&
	is_achannel(Newclient->command[2]) == true &&
	Newclient->command[3] != NULL) {
		error = 2;
	}
	else {
		write(2, "Invalid Nickname or Channel\n", 30);
		return (-1);
	}
	return (0);
}
