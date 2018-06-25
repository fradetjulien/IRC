/*
** EPITECH PROJECT, 2018
** PSU_myirc_2017
** File description:
** is_hostname.c
*/

#include "../../../Includes/client.h"

int		is_hostname(char *host)
{
	int	i = 0;

	if (host == NULL) {
		return (-1);
	}
	while (host && host[i] != '\0') {
		if ((host[i] < 48 || host[i] > 57) && host[i] != '.') {
			return (-1);
		}
		i++;
	}
	return (0);
}
