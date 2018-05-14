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
	t_serveur	serveur;

	serveur.port = get_port(ac, av);
	if (serveur.port == -1) {
		flag_help(av[0]);
	}
	else {
		init_serveur(&serveur);
	}
	return (0);
}
