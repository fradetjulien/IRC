/*
** EPITECH PROJECT, 2018
** my_irc
** File description:
** is_num.c
*/

#include "common.h"

int		is_numbis(char *host)
{
	int	i = 0;

	if (host == NULL)
		return (-1);
	while (host && host[i] != '\0') {
		if ((host[i] < 48 || host[i] > 57) &&
		    host[i] != '.')
			return (-1);
		i++;
	}
	return (0);
}

int		is_num(char *port)
{
	int	i = 0;

	if (port == NULL)
		return (-1);
	while (port && port[i] != '\0') {
		if (port[i] < 48 ||
		    port[i] > 57)
			return (-1);
		i++;
	}
	return (0);
}
