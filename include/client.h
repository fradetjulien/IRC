/*
** EPITECH PROJECT, 2018
** my_irc
** File description:
** client.h
*/

#ifndef CLIENT_H_
# define CLIENT_H_

typedef struct		s_client
{
	int		port;
	int		fd;
	int		connected;
	char		*IP;
}			t_client;

#endif /* !CLIENT_H_ */
