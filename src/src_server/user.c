#include "server.h"

int			count_user(t_user *i)
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

t_user	*create_user(t_serv *serveur)
{
	t_user	*new;

	if ((new = malloc(sizeof(t_user))) == NULL)
		return (NULL);
	new->nick = strdup("no_name");
	new->fd = serveur->cfd;
	new->ip = inet_ntoa(serveur->s_in.sin_addr);
	new->port = ntohs(serveur->s_in.sin_port);
	new->next = NULL;
	printf("Ip: %s, Port: %d\n", new->ip, new->port);
	return (new);
}

t_user			*get_user_by_id(t_user *i, int fd)
{
	if (i == NULL)
		return (NULL);
	while (i)
	{
		if (i->fd == fd)
			return (i);
		i = i->next;
	}
	return (NULL);
}

t_user			*del_user(int port, t_user *elem)
{
	int 	len;
	t_user	*u = elem;

	printf("user deleted on port : %d\n", port);
	len = count_user(elem);
	if (len == 1)
	{
		free(elem);
		return (NULL);
	}
	if (elem->fd == port)
		return (elem->next);
	while (elem->next != NULL)
	{
			if (elem->next->fd == port)
			{
				elem->next = elem->next->next;
				return (u);
			}
			elem = elem->next;
		}
	return (u);
}

t_user			*add_user(t_serv *serveur, t_user *elem)
{
	t_user	*new;
	t_user	*tmp;

	tmp = elem;
	if ((new = create_user(serveur)) == NULL)
		return (NULL);
	if (elem == NULL)
		return (new);
	while (tmp->next != NULL)
		tmp = tmp->next;
	tmp->next = new;
	return (elem);
}
