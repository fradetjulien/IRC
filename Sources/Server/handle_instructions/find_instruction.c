/*
** EPITECH PROJECT, 2018
** PSU_myirc_2017
** File description:
** find_instruction.c
*/

#include "../../../Includes/server.h"

int		find_instruction(t_server *myserver, t_instructions *ptr)
{
	int	i = 0;

	while ((strcmp(ptr->real_instruct[i], myserver->command[0]) != 0)
	&& (i < 11)) {
		i++;
	}
	if (i > 10)
		return (-1);
	return (i);
}
