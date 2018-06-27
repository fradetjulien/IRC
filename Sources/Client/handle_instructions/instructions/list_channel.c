/*
** EPITECH PROJECT, 2018
** PSU_myirc_2017
** File description:
** list_channel.c
*/

#include "../../../../Includes/client.h"
#include "../../../../Includes/library.h"

bool		ischannel(char *channel)
{
	int	i = 0;

	if (strlen(channel) > LEN_CHANNEL)
		return (false);
	while (channel && channel[i] != '\0') {
		if (is_caract(channel[i]) != 1 &&
		is_num(channel[i]) != 1 &&
		channel[i] != '#' && channel[i] != ',')
			return (false);
		i++;
	}
	return (true);
}

int		list_channel(t_client *Newclient)
{
	int	error = 0;

	if (Newclient->command[1] != NULL) {
		if (ischannel(Newclient->command[1]) == false) {
			write(2, "Invalid Channel\n", 18);
			return (-1);
		}
	}
	error = send_instruction(Newclient, Newclient->socket->fd);
	if (error == -1)
		return (-1);
	return (0);
}
