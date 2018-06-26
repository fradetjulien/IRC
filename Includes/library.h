/*
** EPITECH PROJECT, 2018
** PSU_myirc_2017
** File description:
** library.h
*/

#ifndef LIBRARY_H_
# define LIBRARY_H_

# define READ_SIZE (128)

#include <unistd.h>
#include <stdlib.h>
#include <string.h>

char		**str_to_wordtab(char *str, char delimitor);
char		*get_next_line(const int fd);
char		*epur_str(char *str);
int		my_putstr(char *str);
int		my_putchar(char c);

#endif /* !LIBRARY_H_ */
