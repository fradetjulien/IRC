/*
** EPITECH PROJECT, 2018
** PSU_myirc_2017
** File description:
** help_client.c
*/

#include "../../../Includes/client.h"
#include "../../../Includes/library.h"

int		help_client(char *binary)
{
	if (write(1, "USAGE : ", 8) == -1) {
		return (-1);
	}
	if (my_putstr(binary) == -1) {
		return (-1);
	}
	if (write(1, "\n", 2) == -1) {
		return (-1);
	}
	return (0);
}
