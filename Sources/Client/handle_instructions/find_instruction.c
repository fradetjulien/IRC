/*
** EPITECH PROJECT, 2018
** PSU_myirc_2017
** File description:
** find_instruction.c
*/

#include "../../../Includes/client.h"

int		find_instruction(t_client *Newclient, t_instructions *ptr)
{
	int	i = 0;

	while ((strcmp(ptr->real_instruct[i], Newclient->command[0]) != 0) &&
	i < 11) {
		i++;
	}
	if (strncmp(ptr->real_instruct[9], Newclient->command[0], 1) == 0)
		return (9);
	else if (i > 10)
		return (-1);
	return (i);
}
