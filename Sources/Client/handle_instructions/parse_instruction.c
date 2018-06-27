/*
** EPITECH PROJECT, 2018
** PSU_myirc_2017
** File description:
** parse_instruction.c
*/

#include "../../../Includes/client.h"

int			parse_instruction(t_client *Newclient)
{
	t_instructions	instruct;
	int		is_real = 0;

	init_instructions(&instruct);
	is_real = find_instruction(Newclient, &instruct);
	if (is_real == -1)
		return (-1);
	instruct._instruct[is_real](Newclient);
	return (0);
}
