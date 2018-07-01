/*
** EPITECH PROJECT, 2018
** PSU_myirc_2017
** File description:
** send_instruction.c
*/

#include "../../../Includes/server.h"

int		send_instruction(t_server *myserver, int fd)
{
	int	len = strlen(myserver->received);

	if (myserver->received == NULL)
		return (-1);
	if (FD_ISSET(fd, &myserver->write) == true) {
		if (write(fd, myserver->received, len) == -1)
			return (-1);
	}
	return (0);
}
