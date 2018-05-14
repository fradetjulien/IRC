/*
** EPITECH PROJECT, 2018
** 
** File description:
** 
*/

#include "client.h"

t_client	*init_client(int fd)
{
	t_client	*ret;

	if ((ret = malloc(sizeof(t_client))) == NULL)
		return (NULL);
	ret->fd = fd;
	ret->statut = 0;
	ret->user = "";
	ret->pass = "";
	return (ret);
		
}
