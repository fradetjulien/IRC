/*
** EPITECH PROJECT, 2018
** my_irc
** File description:
** run_processus.c
*/

#include "serveur.h"

void		reset_connection(t_serveur *serveur)
{
	int	i = -1;

	FD_ZERO(&serveur->rset);
	FD_SET(serveur->fd, &serveur->rset);
	serveur->sd_size = serveur->fd;
	while (++i < MAX) {
		serveur->sd = serveur->cfdl[i];
		if (serveur->sd > 0)
			FD_SET(serveur->sd, &serveur->rset);
		if (serveur->sd > serveur->sd_size)
			serveur->sd_size = serveur->sd;
	}
}

int		run_processus(t_serveur *serveur)
{
	while (serveur->statut == 1) {
		reset_connection(serveur);
		if (select(serveur->sd_size + 1, &serveur->rset, NULL, NULL, NULL) == -1)
			return (-1);
		if (FD_ISSET(serveur->fd, &serveur->rset)) {
			if (handle_packet(serveur) == -1)
				return (-1);
		}
		if (client_processus(serveur) == -1) {
			return (-1);
		}
	}
	return (0);
}
