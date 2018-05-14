/*
** EPITECH PROJECT, 2018
** 
** File description:
** 
*/

#ifndef CLIENT_H_
# define CLIENT_H_

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netdb.h>
#include "com.h"

typedef struct	s_client
{
	int	fd;
	int	statut;
	char	*user;
	char	*pass;
}		t_client;

int	begin_client(t_client *);
char	*get_msg(int);
void	send_msg(int, char *);
t_client	*init_client(int);


#endif	/* !CLIENT_H_ */
