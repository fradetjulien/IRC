/*
** EPITECH PROJECT, 2018
** my_irc
** File description:
** init_serveur.c
*/

#include "serveur.h"

t_serveur		*init_serveur(int ac, char **av)
{
	t_serveur	*serveur;

	serveur = malloc(sizeof(t_serveur));
	if (serveur == NULL)
		return (NULL);
	serveur->port = get_port(ac, av);
	if (serveur->port == -1)
		return (NULL);
	serveur->s_in.sin_family = AF_INET;
	serveur->s_in.sin_port = htons(serveur->port);
	serveur->s_in.sin_addr.s_addr = INADDR_ANY;
	serveur->statut = 1;
	if ((handle_connection(serveur)) == 0)
		return (NULL);
	return (serveur);
}
