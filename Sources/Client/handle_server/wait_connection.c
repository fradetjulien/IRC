/*
** EPITECH PROJECT, 2018
** PSU_myirc_2017
** File description:
** wait_connection.c
*/

#include "../../../Includes/client.h"
#include "../../../Includes/library.h"

void		display_connection(void)
{
	my_putstr("Here is the command that you must execute"
	"to be connected to a server :\n"
	"\t/server $host[:$port]\n");
}

int		wait_connection(t_client *Newclient)
{
	int	error = 0;

	while (Newclient->socket->fd == -1 && Newclient->connected == false) {
		prompt();
		error = read_instruction(0, Newclient);
		if (error == -1) {
			write(2, "Can't read on this fd\n", 23);
			return (-1);
		}
		else if (error == 0) {
			error = is_writearguments(Newclient);
			if (error == 0)
				error = connection_server(Newclient);
			else
				display_connection();
		}
	}
	return (error);
}
