/*
** EPITECH PROJECT, 2018
** 
** File description:
** 
*/

#include "server.h"

int		nick_exist(t_serv *serv, char *name)
{
	t_user	*tmp = serv->user;

	if (tmp == NULL)
		return (0);
	while (tmp) {
		if (strcmp(tmp->nick, name) == 0)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

int	 	is_good_nick(char *name)
{
	int	i = -1;

	if (strlen(name) > 9)
		return (0);
	while (++i) {
		if (!((name[i] <= 'Z' && name[i] >= 'A') ||
			(name[i] <= 'z' && name[i] >= 'a') ||
			(name[i] <= '9' && name[i] >= '0')))
			return (0);
	}
	return (1);
}

int	handle_nick(t_serv *serv, t_user *user, char **tab)
{
	if (tab[1] == NULL) {
		dprintf(user->fd, m431);
		return (0);
	}
	if (is_good_nick(tab[1]) == 0) {
		dprintf(user->fd, m432);
		return (0);
	}
	if (nick_exist(serv, tab[1])) {
		dprintf(user->fd, m433);
		return (0);
	}
	if (strcmp(user->nick, "no_name") == 0)
		dprintf(user->fd, ":127.0.0.1 :%s\r\n", tab[1]);
	user->nick = strdup(tab[1]);
	return (1);
}
