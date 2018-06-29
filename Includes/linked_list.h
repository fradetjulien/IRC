/*
** EPITECH PROJECT, 2018
** PSU_myirc_2017
** File description:
** linked_list.h
*/

#ifndef LINKED_LIST_H_
# define LINKED_LIST_H_

#include <stdlib.h>

typedef struct			s_element
{
	int			len;
	struct s_element	*next;
	struct s_element	*prev;
}t_element;

typedef struct		s_list
{
	int		len;
	t_element	*head;
	t_element	*tail;
}t_list;

/* Handle Linked list */
t_list			*init_list(void);
void			delete_list(t_list *mylist);

#endif /* !LINKED_LIST_H_ */
