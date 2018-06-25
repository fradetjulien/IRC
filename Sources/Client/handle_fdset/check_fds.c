/*
** EPITECH PROJECT, 2018
** PSU_myirc_2017
** File description:
** check_fds.c
*/

#include "../../../Includes/client.h"

int		check_fds(t_client *Newclient, int fd_max)
{
	for (int i = 0; i <= fd_max; i++) {
		if (FD_ISSET(i, &Newclient->read)) {
			read_instruction(i, Newclient);
		}
	}
	return (0);
}
