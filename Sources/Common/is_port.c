/*
** EPITECH PROJECT, 2018
** PSU_myirc_2017
** File description:
** is_port.c
*/

#include "../../Includes/client.h"

int		is_port(char *port)
{
	int	i = 0;

	if (port == NULL) {
		return (-1);
	}
	while (port && port[i] != '\0') {
		if (port[i] < 48 || port[i] > 57) {
			return (-1);
		}
		i++;
	}
	return (0);
}
