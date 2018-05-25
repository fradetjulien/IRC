#include "server.h"

int			count_channel(t_channel *i)
{
	int		c = 1;

	if (i == NULL)
		return (0);
	while (i->next != NULL)
	{
		i = i->next;
		c++;
	}
	return (c);
}

int		channel_user_count(t_channel *chan)
{
	int i = -1

	while (chan->members[++i]);
	return (i);
}

t_channel	*create_channel(t_serv *serveur, char *name, t_user *creator)
{
	t_channel	*new;

	if ((new = malloc(sizeof(t_channel))) == NULL)
		return (NULL);
	new->id = count_channel(serveur->channel)
	new->name = name;
	new->creator = strdup(creator->nick);
	new->members[0] = creator;
	new->members[1] = NULL;
	new->next = NULL;
	printf("New channel created: %s, by %s\n", name, creator->nick);
	return (new);
}

t_channel			*get_channel_by_id(t_channel *i, int id)
{
	if (i == NULL)
		return (NULL);
	while (i)
	{
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
	while (i)
	{
		if (i->name == name)
			return (i);
		i = i->next;
	}
	return (NULL);
}

t_channel			*del_channel(int id, t_channel *elem)
{
	int 	len;
	t_channel	*u = elem;

	printf("Channel deleted by id : %d\n", id);
	len = count_channel(elem);
	if (len == 1)
	{
		free(elem);
		return (NULL);
	}
	if (elem->id == id)
		return (elem->next);
	while (elem->next != NULL)
	{
			if (elem->next->id == id)
			{
				elem->next = elem->next->next;
				return (u);
			}
			elem = elem->next;
		}
	return (u);
}

t_channel			*join_channel(t_serv *serv, t_user *user, char *name)
{
	if (get_channel_by_name(serv->channel, name) == NULL)
		return (add_channel(serv, user, name));
	
}

t_channel			*add_channel(t_serv *serveur, t_user *elem, char *name)
{
	t_user	*new;
	t_user	*tmp;

	tmp = elem;
	if ((new = create_channel(serveur, name, elem)) == NULL)
		return (NULL);
	if (elem == NULL)
		return (new);
	while (tmp->next != NULL)
		tmp = tmp->next;
	tmp->next = new;
	return (elem);
}