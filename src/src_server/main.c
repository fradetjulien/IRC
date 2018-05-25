/*
** EPITECH PROJECT, 2018
** my_irc
** File description:
** main.c
*/

#include "server.h"

t_serv		*init_serv(int ac, char **av)
{
	t_serv	*serv;

	if ((serv = malloc(sizeof(t_serv))) == NULL)
		return (NULL);
	if (av[1] == NULL) {
		flag_help(av[0]);
		return (NULL);
	}
	serv->port = atoi(av[1]);
	serv->s_in.sin_family = AF_INET;
	serv->s_in.sin_port = htons(serv->port);
	serv->s_in.sin_addr.s_addr = INADDR_ANY;
	serv->statut = 1;
	serv->channel = NULL;
	serv->user = NULL;
	if ((handle_connect(serv)) == 0)
		return (NULL);
	return (serv);
}

int		main(int ac, char **av)
{
	t_serv	*s;

	if ((s = init_serv(ac, av)) == NULL)
		return (1);
	if (run_process(s) == 0)
		return (1);
	if (close(s->ssd) == -1)
		return(1);
	free(s);
	return (0);
}
