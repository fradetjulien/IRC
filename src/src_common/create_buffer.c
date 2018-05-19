/*
** EPITECH PROJECT, 2018
** my_irc
** File description:
** create_buffer.c
*/

#include "common.h"

t_buffer		*create_buffer(t_buffer *circular_buffer)
{
	if ((memset(circular_buffer, 0, sizeof(t_buffer))) == NULL)
		return (NULL);
	circular_buffer = malloc(sizeof(char *) * BUFFERSIZE);
	if (circular_buffer == NULL)
		return (NULL);
	circular_buffer->size = BUFFERSIZE;
	circular_buffer->begin = (unsigned int)circular_buffer + sizeof(t_buffer);
	circular_buffer->end = (unsigned int)circular_buffer + BUFFERSIZE;
	return (circular_buffer);
}
