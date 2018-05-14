/*
** EPITECH PROJECT, 2018
** my_irc
** File description:
** handle_packet.c
*/

#include "serveur.h"

int		put_cfd(t_serveur *serveur)
{
	int     i = -1;
	int     f = 0;

	while (++i < MAX && f == 0)
	{
		if (serveur->cfdl[i] == 0)
		{
			serveur->cfdl[i] = serveur->cfd;
			return (i);
			f = 1;
		}
		else
			i++;
	}
	return (0);
}

int		handle_packet(t_serveur *serveur)
{
	serveur->cfd = accept(serveur->fd, (struct sockaddr *)&serveur->s_in,
			      (socklen_t *)&serveur->s_in_size);
	if (serveur->cfd == -1)
		return (-1);
	printf("New client connected on fd : %d\n", put_cfd(serveur));
	return (0);
}
