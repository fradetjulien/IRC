/*
** EPITECH PROJECT, 2018
** PSU_myirc_2017
** File description:
** init_list.c
*/

#include "../../../Includes/linked_list.h"

t_list		*init_list(void)
{
	t_list	*new_list = malloc(sizeof(t_list));

	if (new_list == NULL)
		return (NULL);
	else {
		new_list->len = 0;
		new_list->head = NULL;
		new_list->tail = NULL;
	}
	return (new_list);
}
