/*
** EPITECH PROJECT, 2018
** 
** File description:
** 
*/

#include "server.h"

int		calc_clt(t_serv *serv, int i)
{
	int	len = 0;
	t_user 	*user;

	if ((len = read(serv->sd, serv->buff, BUFF)) == 0)
	{
		printf("FD : %d\n", serv->sd);
		printf("Succesfully disconnected\n");
    	if (close(serv->sd) == -1)
		return (0);
		serv->user = del_user(serv->cfdl[i], serv->user);
		serv->cfdl[i] = 0;
	}
	else if (len < 0)
		printf("Client disconnected\n");
	else
	{
		serv->buff[len] = 0;
		send_to_users(serv->user, serv->buff);
		if ((user = get_user_by_id(serv->user, i)) != NULL)
			manage_client(serv, user, serv->buff);
		else
			printf("UnKnown client msg: %s\n", serv->buff);
	}
	return (1);
}

int		client_process(t_serv *serv)
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
