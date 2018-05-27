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
# include "msg.h"

# define MAX 128
# define BUFF 2048
# define WELCOME	"Welcome to my amazing irc.\r\n"

typedef struct  s_serv t_serv;
typedef struct	s_user t_user;
typedef struct	s_channel t_channel;

struct	s_channel
{
	int	id;
	char	*name;
	char	*creator;
	t_user	*members[MAX];
	t_channel	*next;
};

struct	s_user
{
	int	fd;
	char	*nick;
	char	*ip;
	int	port;
	t_user	*next;
};

struct s_serv
{
	int	port;
	struct  protoent	*pe;
	struct  sockaddr_in	s_in;
	int	s_in_size;
	int	ssd;
	int	sd;
	int	sd_size;
	int	cfd;
	int	cfdl[MAX];
	int	statut;
	char	buff[BUFF];
	t_user	*user;
	t_channel	*channel;
	fd_set	rset;
};

int	client_process(t_serv *serv);
int	handle_packet(t_serv *serv);
int	run_process(t_serv *serv);
int	handle_connect(t_serv *serv);
t_user	*add_user(t_serv *, t_user *);
int	send_to_channel(t_serv *serv, t_user *user, char *msg, char *bb);
int	count_user(t_user *i);
int	send_to_all(t_user *user, char *m);
int	send_to_users(t_user *user, char *m);
t_user	*del_user(int port, t_user *elem);
int 	send_to(int fd, char *msg);
int	manage_client(t_serv *serv, t_user *user, char *msg);
t_user	*get_user_by_id(t_user *i, int fd);
t_channel	*leave_channel(t_serv *serv, t_user *user, char *name);
t_channel	*join_channel(t_serv *serv, t_user *user, char *name);
t_channel	*add_channel(t_serv *serveur, t_user *elem, char *name);
int	send_welcome(int fd);
int	handle_nick(t_serv *serv, t_user *user, char **tab);
t_channel	*get_channel_by_name(t_channel *i, char *name);
int	count_channel(t_channel *i);
int	channel_user_count(t_channel *chan);
t_channel       *create_channel(t_serv *serveur, char *name, t_user *creator);
t_channel	*del_channel(int id, t_channel *elem);


#endif	/* !CLIENT_H_ */
