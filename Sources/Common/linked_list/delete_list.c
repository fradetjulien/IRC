/*
** EPITECH PROJECT, 2018
** PSU_myirc_2017
** File description:
** delete_list.c
*/

#include "../../../Includes/linked_list.h"

void		delete_elements(t_element *elem)
{
	while (elem != NULL) {
		free(elem);
		if (elem->next != NULL)
			elem = elem->next;
	}
	free(elem);
}

void		delete_list(t_list *mylist)
{
	if (mylist != NULL)
		delete_elements(mylist->head);
	free(mylist);
}
