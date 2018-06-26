/*
** EPITECH PROJECT, 2018
** PSU_myirc_2017
** File description:
** delete_client.c
*/

#include "../../../Includes/client.h"

int		delete_client(t_client *Exclient)
{
	free(Exclient->socket);
	free(Exclient->host);
	free(Exclient->port);
	free(Exclient->command);
	free(Exclient->answer);
	return (0);
}
