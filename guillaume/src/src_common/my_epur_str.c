/*
** EPITECH PROJECT, 2018
** my_irc
** File description:
** my_epur_str.c
*/

#include "common.h"

void		check_for_tab(char *str)
{
	int	i = -1;

	while (str[++i] != '\0') {
		if (str[i] == '\t')
			str[i] = ' ';
	}
}

void		epur_area(char *str, int i)
{
	int	k = i;

	while (str[k] == ' ') {
		k++;
	}
	while (str[k] != '\0') {
		str[i++] = str[k++];
	}
	str[i] = 0;
}

char		*my_epur_str(char *str)
{
	int	i = 0;

	if (str == NULL)
		return (NULL);
	check_for_tab(str);
	epur_area(str, i);
	while (str[i] != '\0') {
		if (str[i] == ' ' && str[i + 1] != 0)
			epur_area(str, i + 1);
		i++;
	}
	if (str[i - 1] == ' ')
		i--;
	str[i] = '\0';
	return (str);
}
