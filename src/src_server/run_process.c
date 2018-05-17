/*
** EPITECH PROJECT, 2018
** 
** File description:
** 
*/

#include "server.h"

void	reset_connect(t_serv *serv)
{
	int	i = -1;

	FD_ZERO(&serv->rset);
	FD_SET(serv->ssd, &serv->rset);
	serv->sd_size = serv->ssd;
	while (++i < MAX)
	{
		serv->sd = serv->cfdl[i];
		if (serv->sd > 0)
			FD_SET(serv->sd, &serv->rset);
		if (serv->sd > serv->sd_size)
			serv->sd_size = serv->sd;
	}
}

int run_process(t_serv *serv)
{
	while (serv->statut == 1)
	{
		reset_connect(serv);
		if (select(serv->sd_size + 1, &serv->rset, NULL, NULL, NULL) == -1)
			return (0);
		if (FD_ISSET(serv->ssd, &serv->rset))
		{
			if (handle_packet(serv) == 0)
				return (0);
		}
		if (client_process(serv) == 0)
			return (0);
	}
	return (1);
}
