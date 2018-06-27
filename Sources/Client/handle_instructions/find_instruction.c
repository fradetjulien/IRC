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
	i < 10) {
		i++;
	}
	if (i > 9)
		return (-1);
	return (i);
}
