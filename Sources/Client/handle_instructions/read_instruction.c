/*
** EPITECH PROJECT, 2018
** PSU_myirc_2017
** File description:
** read_instruction.c
*/

#include "../../../Includes/client.h"
#include "../../../Includes/library.h"

int		read_instruction(int fd, t_client *Newclient)
{
	char	*instruction = NULL;

	instruction = get_next_line(fd);
	if (instruction == NULL)
		return (-1);
	if (instruction[0] == '\0')
		return (1);
	instruction = epur_str(instruction);
	Newclient->answer = strdup(instruction);
	Newclient->command = str_to_wordtab(instruction, ' ');
	if (Newclient->command == NULL)
		return (-1);
	free(instruction);
	return (0);
}
