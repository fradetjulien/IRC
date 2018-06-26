/*
** EPITECH PROJECT, 2018
** PSU_myirc_2017
** File description:
** help_client.c
*/

#include "../../../Includes/client.h"
#include "../../../Includes/library.h"

void		help_client(char *binary)
{
	write(1, "USAGE : ", 8);
	my_putstr(binary);
	write(1, "\n", 2);
}
