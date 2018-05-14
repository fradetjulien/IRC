/*
** EPITECH PROJECT, 2018
** my_irc
** File description:
** handle_client.c
*/

#include "serveur.h"

int		calc_clt(t_serveur *serveur, int i)
{
	int	len = 0;

	if ((len = read(serveur->sd, serveur->buff, BUFF)) == 0) {
		printf("Succesfully disconnected\n");
		if (close(serveur->sd) == -1)
			return (-1);
		serveur->cfdl[i] = 0;
	}
	else if (len < 0) {
		printf("Client disconnected\n");
	}
	else {
		serveur->buff[len] = 0;
		printf("User %d send : %s\n", i, serveur->buff);
		send(serveur->cfdl[i], serveur->buff, strlen(serveur->buff), 0);
	}
	return (0);
}

int		client_processus(t_serveur *serveur)
{
	int	i = -1;

	while (++i < MAX) {
		serveur->sd = serveur->cfdl[i];
		if (FD_ISSET(serveur->sd, &serveur->rset)) {
			if (calc_clt(serveur, i) == 0)
				return (-1);
		}
	}
	return (0);
}
