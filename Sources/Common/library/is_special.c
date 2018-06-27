/*
** EPITECH PROJECT, 2018
** PSU_myirc_2017
** File description:
** is_special.c
*/

#include "../../../Includes/library.h"

int			is_special(char c)
{
	int		i = 0;
	const char	*special = "-_[]\\`^{}";

	if (c == '\0')
		return (-1);
	while (i < 10) {
		if (c == special[i])
			return (1);
		i++;
	}
	return (-1);
}
