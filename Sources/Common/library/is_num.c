/*
** EPITECH PROJECT, 2018
** PSU_myirc_2017
** File description:
** is_num.c
*/

#include "../../../Includes/library.h"

int		is_num(char c)
{
	if (c == '\0')
		return (-1);
	else if (c > 47 && c < 58)
		return (1);
	return (0);
}
