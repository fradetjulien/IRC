/*
** EPITECH PROJECT, 2018
** my_irc
** File description:
** get_port.c
*/

#include "serveur.h"
#include "common.h"

int		get_port(int ac, char **av)
{
	if (ac > 2 || ac <= 1) {
 		return (-1);
	}
	else {
		if (is_num(av[1]) == 0) {
			return (atoi(av[1]));
		}
	}
	return (-1);
}
