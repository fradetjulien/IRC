/*
** EPITECH PROJECT, 2018
** PSU_myirc_2017
** File description:
** send_instruction.c
*/

#include "../../../Includes/client.h"

int		send_instruction(t_client *Newclient, int fd)
{
	int	len = strlen(Newclient->answer);

	if (Newclient->answer == NULL)
		return (-1);
	if (FD_ISSET(fd, &Newclient->write) == true) {
		if (write(fd, Newclient->answer, len) == -1)
			return (-1);
	}
	return (0);
}
