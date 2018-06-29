/*
** EPITECH PROJECT, 2018
** PSU_myirc_2017
** File description:
** help_server.c
*/

#include "../../../Includes/server.h"
#include "../../../Includes/library.h"

void		help_server(char *binary)
{
	write(0, "USAGE : ", 9);
	my_putstr(binary);
	write(0, " port\n", 8);
}
