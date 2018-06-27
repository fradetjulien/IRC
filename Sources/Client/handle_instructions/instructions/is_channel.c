/*
** EPITECH PROJECT, 2018
** PSU_myirc_2017
** File description:
** join_channel.c
*/

#include "../../../../Includes/client.h"
#include "../../../../Includes/library.h"

bool		is_achannel(char *channel)
{
	int	i = 0;

	if (strlen(channel) > LEN_CHANNEL)
		return (false);
	while (channel && channel[i] != '\0') {
		if (is_caract(channel[i]) != 1 &&
		is_num(channel[i]) != 1 && channel[i] != '&'
		&& channel[i] != '#' && channel[i] != ',')
			return (false);
		i++;
	}
	return (true);
}

int		is_channel(t_client *Newclient)
{
	int	error = 0;

	if (is_achannel(Newclient->command[1]) == false) {
		write(2, "Invalid Channel\n", 18);
		return (-1);
	}
	error = send_instruction(Newclient, Newclient->socket->fd);
	if (error == -1)
		return (-1);
	return (0);
}
