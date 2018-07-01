/*
** EPITECH PROJECT, 2018
** PSU_myirc_2017
** File description:
** parse_instructions.c
*/

#include "../../../Includes/server.h"

int			parse_instruction(t_server *myserver)
{
	t_instructions	instruct;
	int		is_real = 0;

	init_instructions(&instruct);
	is_real = find_instruction(myserver, &instruct);
	if (is_real == -1)
		return (-1);
	instruct._instruct[is_real](myserver);
	return (0);
}
