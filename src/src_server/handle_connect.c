/*
** EPITECH PROJECT, 2018
** my_irc
** File description:
** handle_connect.c
*/

#include "server.h"

int		handle_connect(t_serv *serv)
{
	int	i = -1;
	int	sock = 0;

	while (++i < MAX - 1)
		serv->cfdl[i] = 0;
	if ((serv->pe = getprotobyname("TCP")) == NULL)
		return (0);
	if ((serv->ssd = socket(AF_INET, SOCK_STREAM, serv->pe->p_proto)) == -1)
		return (0);
	if (setsockopt(serv->ssd, SOL_SOCKET, SO_REUSEADDR, (char *)&sock, 
		sizeof(sock)) == -1)
		return (0);
	if (bind(serv->ssd, (const struct sockaddr*)&serv->s_in, 
		 sizeof(serv->s_in)) == -1)
		return (0);
	if (listen(serv->ssd, 42) == -1)
		return (0);
	serv->s_in_size = sizeof(serv->s_in);
	return (1);
}
