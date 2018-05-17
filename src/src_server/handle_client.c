/*
** EPITECH PROJECT, 2018
** my_irc
** File description:
** handle_client.c
*/

#include "server.h"

int	calc_clt(t_serv *serv, int i)
{
	int	len = 0;

	if ((len = read(serv->sd, serv->buff, BUFF)) == 0)
	{
		printf("Succesfully disconnected\n");
    	if (close(serv->sd) == -1)
		return (0);
      	serv->cfdl[i] = 0;
	}
	else if (len < 0)
		printf("Client disconnected\n");
	else
	{
		serv->buff[len] = 0;
		printf("user %d send : %s\n", i, serv->buff);
		send(serv->cfdl[i], serv->buff, strlen(serv->buff), 0);
	}
	return (1);
}

int	client_process(t_serv *serv)
{
	int	i = -1;

	while (++i < MAX)
	{
		serv->sd = serv->cfdl[i];
		if (FD_ISSET(serv->sd, &serv->rset))
		{
			if (calc_clt(serv, i) == 0)
				return (0);
		}
	}
	return (1);
}
