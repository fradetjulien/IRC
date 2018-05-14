/*
** EPITECH PROJECT, 2018
** my_irc
** File description:
** serveur.c
*/

#include "serveur.h"
#include "common.h"

int			main(int ac, char **av)
{
	t_serveur	*serveur;

	serveur = init_serveur(ac, av);
	if (serveur == NULL) {
		flag_help(av[0]);
		return (1);
	}
	else {
		run_processus(serveur);
	}
	if (close(serveur->fd) == -1)
		return (-1);
	free(serveur);
	return (0);
}
