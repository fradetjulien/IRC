/*
** EPITECH PROJECT, 2018
** PSU_myirc_2017
** File description:
** my_putchar.c
*/

#include "../../../Includes/library.h"

int		my_putchar(char c)
{
	if (write(1, &c, 1) == -1)
		return (-1);
	return (0);
}
