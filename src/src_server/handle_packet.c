/*
** EPITECH PROJECT, 2018
** 
** File description:
** 
*/

#include "server.h"

int	put_cfd(t_serv *serv)
{
	int	i = -1;
	int	f = 0;

	while (++i < MAX && f == 0)
	{
		if (serv->cfdl[i] == 0)
		{
			serv->cfdl[i] = serv->cfd;
			return (serv->cfd);
			f = 1;
		}
		else
			i++;
	}
}

int	handle_packet(t_serv *serv)
{
	//create user in list
	if ((serv->cfd = accept(serv->ssd, (struct sockaddr *)&serv->s_in,
				(socklen_t*)&serv->s_in_size)) == -1)
		return (0);
	printf("New client connected on fd : %d\n", put_cfd(serv));
	if ((serv->user = add_user(serv, serv->user)) == NULL)
		return (0);
	printf("there is %d user connected.\n", count_user(serv->user));
	//send(serv->cfd, WELCOME, strlen(WELCOME), 0);
	return (1);
}
