/*
** EPITECH PROJECT, 2018
** PSU_myirc_2017
** File description:
** counter_args.c
*/

#include "../../../Includes/client.h"

int		counter_args(char **command)
{
	int	i = 0;

	while (command && command[i] != NULL)
		i++;
	return (i);
}
