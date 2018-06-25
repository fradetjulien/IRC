/*
** EPITECH PROJECT, 2018
** PSU_myirc_2017
** File description:
** connection_server.c
*/

#include "../../../Includes/client.h"

int		connection_server(t_client *Newclient)
{
	if (init_socket(Newclient, "TCP") == -1)
		return (-1);
	if (connect_socket(Newclient) == -1)
		return (-1);
	return (0);
}
