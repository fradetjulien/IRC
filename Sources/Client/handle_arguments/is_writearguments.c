/*
** EPITECH PROJECT, 2018
** PSU_myirc_2017
** File description:
** is_writearguments.c
*/

#include "../../../Includes/client.h"

int		is_writearguments(t_client *Newclient)
{
	if (strcmp(Newclient->command[0], "/server") == 0) {
		if ((is_hostname(Newclient->command[1]) == 0) &&
		(is_port(Newclient->command[2]) == 0)) {
			Newclient->host = strdup(Newclient->command[1]);
			Newclient->port = strdup(Newclient->command[2]);
		}
		if (Newclient->host != NULL && Newclient->port != NULL)
			return (0);
	}
	else if (strcmp(Newclient->command[0], "exit") == 0) {
		return (1);
	}
	return (-1);
}
