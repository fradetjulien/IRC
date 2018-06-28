/*
** EPITECH PROJECT, 2018
** PSU_myirc_2017
** File description:
** channel_message.c
*/

#include "../../../../Includes/client.h"

int		channel_message(t_client *Newclient)
{
	if (close_socket(Newclient) == -1)
		return (-1);
	return (0);
}
