/*
** EPITECH PROJECT, 2018
** 
** File description:
** 
*/

#ifndef CLIENT_H_
# define CLIENT_H_

# include <sys/types.h>
# include <sys/socket.h>
# include <sys/time.h>
# include <netdb.h>
# include <netinet/in.h>
# include <arpa/inet.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <errno.h>
# include <stdbool.h>
# include "com.h"

# define MAX 1024
# define BUFF 2048
# define WELCOME	"Welcome to my amazing irc.\r\n"

typedef struct  s_serv t_serv;

struct s_serv
{
	int port;
	struct  protoent *pe;
	struct  sockaddr_in s_in;
	int s_in_size;
	int ssd;
	int sd;
	int sd_size;
	int cfd;
	int cfdl[MAX];
	int statut;
	char buff[BUFF];
	fd_set rset;
};

int client_process(t_serv *serv);
int handle_packet(t_serv *serv);
int run_process(t_serv *serv);
int handle_connect(t_serv *serv);

#endif	/* !CLIENT_H_ */
