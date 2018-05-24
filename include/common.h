/*
** EPITECH PROJECT, 2018
** my_irc
** File description:
** common.h
*/

#ifndef COMMON_H_
# define COMMON_H_

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#ifndef READ_SIZE
# define READ_SIZE (128)
#endif /* !READ_SIZE */

# define BUFFERSIZE 512

typedef struct	s_buffer
{
	unsigned int	size;
	unsigned int	begin;
	unsigned int	end;
	char		*circular_buffer;
}		t_buffer;

int		is_num(char *port);
int		is_numbis(char *host);
int		write_into_buffer(t_buffer *circular_buffer, char *cmd);
char		*get_next_line(const int fd);
char		*my_epur_str(char *str);
char		**str_to_wordtab(char *str, char delimitor);
void		flag_help(char *binary);
t_buffer	*create_buffer(t_buffer *circular_buffer);

#endif /* !COMMON_H_ */
