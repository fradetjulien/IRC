/*
** EPITECH PROJECT, 2018
** PSU_myirc_2017
** File description:
** quit.c
*/

#include "../../../../Includes/client.h"

int		quit(t_client *Newclient)
{
	if (close_socket(Newclient) == -1) {
		return (-1);
	}
	delete_client(Newclient);
	exit(0);
	return (0);
}
