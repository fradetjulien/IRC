/*
** EPITECH PROJECT, 2018
** PSU_myirc_2017
** File description:
** is_caract.c
*/

#include "../../../Includes/library.h"

int		is_caract(char c)
{
	if (c == '\0')
		return (-1);
	else if ((c > 64 && c < 91) ||
		(c > 96 && c < 123))
		return (1);
	return (0);
}
