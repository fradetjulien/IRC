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
# include "common.h"

# define MAX 1024
# define BUFF 2048
# define WELCOME	"Welcome to my amazing irc.\r\n"

typedef struct  s_serv t_serv;
typedef struct s_user t_user;
typedef struct s_channel t_channel;

struct s_channel
{
	int id;
	char *name;
	int members[MAX];
	t_channel *next;
};

struct s_user
{
	int fd;
	char *nick;
	char *ip;
	int  port;
	t_user *next;
};

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
	t_user			*user;
	t_channel		*channel;
	fd_set rset;
};

int client_process(t_serv *serv);
int handle_packet(t_serv *serv);
int run_process(t_serv *serv);
int handle_connect(t_serv *serv);


t_user		*add_user(t_serv *, t_user *);
int			count_user(t_user *i);
int		send_to_all(t_user *user, char *m);
int		send_to_users(t_user *user, char *m);
t_user			*del_user(int port, t_user *elem);
int		manage_client(t_serv *serv, t_user *user, char *msg);
t_user			*get_user_by_id(t_user *i, int fd);

#endif	/* !CLIENT_H_ */
