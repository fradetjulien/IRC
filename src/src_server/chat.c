/*
** EPITECH PROJECT, 2018
** 
** File description:
** 
*/

#include "server.h"

int	send_welcome(int fd)
{
	dprintf(fd, "%s%s%s%s", "001 RPL_WELCOME :Welcome to this IRC\r\n",
	"002 RPL_YOURHOST :Your host is guigui_irc, running version 1\r\n",
	"003 RPL_CREATED :This server was created May  27 2018\r\n",
	"004 RPL_MYINFO :127.0.0.1\r\n");
}

int	send_to_channel(t_serv *serv, t_user *user, char *msg, char *bb)
{
	char **tab = str_to_wordtab(msg, ':');
	t_channel *chan;
	int i = -1;

	bb++;
	if (tab == NULL)
		return (0);
	if ((chan = get_channel_by_name(serv->channel, tab[0])) == NULL) {
		dprintf(user->fd, m442);
		return (0);
	}
	while (chan->members[++i]) {
		if (chan->members[i]->fd != user->fd)
			dprintf(chan->members[i]->fd, "PRIVMSG %s :%s\r\n",
			chan->name, bb);
	}
	return (1);
}

int 	send_to(int fd, char *msg)
{
	printf("to %d:%s\n", fd, msg);
	send(fd, msg, strlen(msg), 0);
}

int		send_to_users(t_user *user, char *m)
{
	if (user == NULL)
		return (1);
	while (user) {
		printf("port: %d : %s\n", user->fd, m);
		send(user->fd, m, strlen(m), 0);
		user = user->next;
	}
	return (1);
}
