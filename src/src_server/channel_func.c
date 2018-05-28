/*
** EPITECH PROJECT, 2018
** my_irc
** File description:
** channel.c
*/

#include "server.h"

t_channel			*del_channel(int id, t_channel *elem)
{
	int 	len;
	t_channel	*u = elem;

	printf("Channel deleted by id : %d\n", id);
	len = count_channel(elem);
	if (len == 1) {
		free(elem);
		return (NULL);
	}
	if (elem->id == id)
		return (elem->next);
	while (elem->next != NULL) {
		if (elem->next->id == id){
			elem->next = elem->next->next;
			return (u);
		}
		elem = elem->next;
	}
	return (u);
}

int 	user_is_on_channel(t_channel *chan, t_user *user)
{
	int i = -1;

	while (chan->members[++i]) {
		if (chan->members[i]->fd == user->fd)
			return (1);
	}
	return (0);
}

t_channel	*join_channel(t_serv *serv, t_user *user, char *name)
{
	t_channel	*tmp = serv->channel;
	t_channel	*chan;
	int	i = -1;

	if ((chan = get_channel_by_name(serv->channel, name)) == NULL) {
		printf("%s, %d\n", user->nick, user->fd);
		dprintf(user->fd, "JOIN %s\r\n", name);
		return (add_channel(serv, user, name));
	}
	if (user_is_on_channel(chan, user)) {
		dprintf(user->fd, "443 %s %s :is already on channel\r\n",
		user->nick, chan->name);
		return (tmp);
	}
	while (chan->members[++i] != NULL && i < MAX - 1);
	chan->members[i] = user;
	chan->members[i + 1] = NULL;
	printf("%s, %d\n", user->nick, user->fd);
	dprintf(user->fd, "JOIN %s\r\n", name);
	return (tmp);
}

t_channel	*leave_channel(t_serv *serv, t_user *user, char *name)
{
	t_channel	*tmp = serv->channel;
	t_channel	*chan;
	int	i = -1;
	int	f = 0;

	if ((chan = get_channel_by_name(serv->channel, name)) == NULL) {
		send_to(user->fd, m442);
		return (tmp);
	}
	while (chan->members[++i] && f != -1) {
		if (chan->members[i] == user)
			f = 1;
		if (f)
			chan->members[i] = chan->members[i + 1];
		if (chan->members[i] == NULL)
			f = -1;
	}
	dprintf(user->fd, "PART %s\r\n", name);
	if (i == 1)
		return (del_channel(chan->id, tmp));
	return (tmp);
}

t_channel	*add_channel(t_serv *serveur, t_user *elem, char *name)
{
	t_channel	*new;
	t_channel	*tmp;

	tmp = serveur->channel;
	if ((new = create_channel(serveur, name, elem)) == NULL)
		return (NULL);
	if (serveur->channel == NULL)
		return (new);
	while (tmp->next != NULL)
		tmp = tmp->next;
	tmp->next = new;
	return (serveur->channel);
}
