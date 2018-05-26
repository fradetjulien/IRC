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

int		is_num(char *port);
int		is_numbis(char *host);
char		*get_next_line(const int fd);
char		*my_epur_str(char *str);
char		**str_to_wordtab(char *str, char delimitor);
void		flag_help(char *binary);

#endif /* !COMMON_H_ */
