/*
** EPITECH PROJECT, 2018
** 
** File description:
** 
*/

#include "server.h"

int		check_cmd(t_serv *serv, t_user *user, char **tab)
{
	int tablen = -1;

	while (tab[++tablen]);
	if (strcmp(tab[0], "JOIN") == 0 && tablen == 2)
		serv->channel = join_channel(serv, user, tab[1]);
	else if (strcmp(tab[0], "PART") == 0 && tablen == 2)
		serv->channel = leave_channel(serv, user, tab[1]);
	else if (strcmp(tab[0], "NICK") == 0 && tablen == 2)
		handle_nick(serv, user, tab);
	else if (strcmp(tab[0], "USER") == 0 && tablen == 5)
		send_welcome(user->fd);
	else if (strcmp(tab[0], "PRIVMSG") == 0 && tablen == 3)
		send_to_channel(serv, user, tab[1], tab[2]);
	else if (strcmp(tab[0], "QUIT") == 0) {
		dprintf(user->fd, "QUIT :quit\r\n");
		return (-1);
	}
	else
		dprintf(user->fd, m421, tab[0]);
	return (1);
}

int		manage_client(t_serv *serv, t_user *user, char *msg)
{
	char **tab;

	msg[strlen(msg) - 2] = 0;
	printf("revc %s\n", msg);
	tab = str_to_wordtab(msg, ' ');
	if (tab == NULL)
		return (0);
	return (check_cmd(serv, user, tab));
}
