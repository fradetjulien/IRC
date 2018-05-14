/*
** EPITECH PROJECT, 2018
** my_irc
** File description:
** init_serveur.c
*/

#include "serveur.h"

int		init_serveur(t_serveur *serveur)
{
	serveur->protocol = getprotobyname("TCP");
	if (serveur->protocol == NULL)
		return (-1);
	serveur->fd = socket(AF_INET, SOCK_STREAM, serveur->protocol->p_proto);
	if (serveur->fd == -1)
		return (-1);
	serveur->serveur_addr.sin_family = AF_INET;
	serveur->serveur_addr.sin_port = htons(serveur->port);
	serveur->serveur_addr.s_addr = inet_addr(av[1]);
	if (bind(serveur->fd, (const struct sockaddr *)&serveur->serveur_addr,
		 sizeof(serveur->serveur_addr)) == -1)
		return (-1);
	if (listen(serveur->fd, 1024) == -1) {
		close(serveur->fd);
		return (-1);
	}
	return (0);
}
