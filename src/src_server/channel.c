/*
** EPITECH PROJECT, 2018
** my_irc
** File description:
** channel.c
*/

#include "server.h"

int			count_channel(t_channel *i)
{
	int		c = 1;

	if (i == NULL)
		return (0);
	while (i->next != NULL) {
		i = i->next;
		c++;
	}
	return (c);
}

int		channel_user_count(t_channel *chan)
{
	int i = -1;

	while (chan->members[++i]);
	return (i);
}

t_channel	*create_channel(t_serv *serveur, char *name, t_user *creator)
{
	t_channel	*new;

	if ((new = malloc(sizeof(t_channel))) == NULL)
		return (NULL);
	new->id = count_channel(serveur->channel) + 1;
	new->name = name;
	new->creator = strdup(creator->nick);
	new->members[0] = creator;
	new->members[1] = NULL;
	new->next = NULL;
	printf("New channel created: %s, by %s, id: %d\n",
	name, creator->nick, new->id);
	return (new);
}

t_channel			*get_channel_by_id(t_channel *i, int id)
{
	if (i == NULL)
		return (NULL);
	while (i) {
		if (i->id == id)
			return (i);
		i = i->next;
	}
	return (NULL);
}

t_channel			*get_channel_by_name(t_channel *i, char *name)
{
	if (i == NULL)
		return (NULL);
	while (i) {
		if (strcmp(i->name, name) == 0)
			return (i);
		i = i->next;
	}
	return (NULL);
}
