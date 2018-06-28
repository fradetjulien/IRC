/*
** EPITECH PROJECT, 2018
** PSU_myirc_2017
** File description:
** nickname.c
*/

#include "../../../../Includes/client.h"
#include "../../../../Includes/library.h"

bool		is_nickname(char *nickname)
{
	int	i = 0;

	if (strlen(nickname) > LEN_NICKNAME)
		return (false);
	while (nickname && nickname[i] != '\0') {
		if (is_num(nickname[i]) != 1 &&
		    is_caract(nickname[i]) != 1 &&
		    is_special(nickname[i]) != 1)
			return (false);
		i++;
	}
	return (true);
}

int		nickname(t_client *Newclient)
{
	int	error = 0;
	int	nb_args = counter_args(Newclient->command);

	if (nb_args != 2 ||
	is_nickname(Newclient->command[1]) == false) {
		write(2, "Invalid Nickname\n", 18);
		return (1);
	}
	error = send_instruction(Newclient, Newclient->socket->fd);
	if (error == -1)
		return (-1);
	return (0);
}
