/*
** EPITECH PROJECT, 2018
** my_irc
** File description:
** handle_packet.c
*/

#include "server.h"

int		put_cfd(t_serv *serv)
{
	int	i = -1;
	int	f = 0;

	while (++i < MAX && f == 0)
	{
		if (serv->cfdl[i] == 0)
		{
			serv->cfdl[i] = serv->cfd;
			return (i);
			f = 1;
		}
		else
			i++;
	}
}

int	handle_packet(t_serv *serv)
{
	if ((serv->cfd = accept(serv->ssd, (struct sockaddr *)&serv->s_in,
				(socklen_t*)&serv->s_in_size)) == -1)
		return (0);
	printf("New client connected on fd : %d\n", put_cfd(serv));
	if ((serv->user = add_user(serv, serv->user)) == NULL)
		return (0);
	printf("there is %d user connected.\n", count_user(serv->user));
	return (1);
}
