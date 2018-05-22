/*
** EPITECH PROJECT, 2018
** my_irc
** File description:
** write_into_buffer.c
*/

#include "common.h"

int		write_into_buffer(t_buffer *buffer, char *cmd)
{
	int	i = -1;

	while (i++ != strlen(cmd) && ((buffer->end + i) % buffer->size) != buffer->begin)
		buffer->circular_buffer[(buffer->end + i) % buffer->size] = cmd[i];
	buffer->end = (buffer->end + i) % buffer->size;
	return (0);
}
