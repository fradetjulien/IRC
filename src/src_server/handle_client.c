/*
** EPITECH PROJECT, 2018
** 
** File description:
** 
*/

#include "server.h"

int close_co(t_serv *serv, int i)
{
	printf("Succesfully disconnected\n");
	if (close(serv->sd) == -1)
		return (0);
	serv->user = del_user(serv->cfdl[i], serv->user);
	serv->cfdl[i] = 0;
}

int	calc_clt(t_serv *serv, int i)
{
	int	len = 0;
	t_user 	*user;

	if ((len = read(serv->sd, serv->buff, BUFF)) == 0)
		close_co(serv, i);
	else if (len == 0)
		printf("Client disconnected\n");
	else {
		serv->buff[len] = 0;
		if ((user = get_user_by_id(serv->user, serv->cfdl[i])) != NULL)
			len = manage_client(serv, user, serv->buff);
		else
			printf("UnKnown client %d msg: %s\n",
			serv->cfdl[i], serv->buff);
	}
	if (len == -1)
		close_co(serv, i);
	return (1);
}

int	client_process(t_serv *serv)
{
	int	i = -1;

	while (++i < MAX) {
		serv->sd = serv->cfdl[i];
		if (FD_ISSET(serv->sd, &serv->rset) &&
		calc_clt(serv, i) == 0) {
			return (0);
		}
	}
	return (1);
}
