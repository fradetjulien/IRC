/*
** EPITECH PROJECT, 2018
** PSU_myirc_2017
** File description:
** my_putstr.c
*/

#include "../../../Includes/library.h"

int		my_putstr(char *str)
{
	int	i = 0;

	if (str == NULL)
		return (-1);
	while (str && str[i] != '\0') {
		if (my_putchar(str[i]) == -1)
			return (-1);
		i++;
	}
	return (0);
}
