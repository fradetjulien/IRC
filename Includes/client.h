/*
** EPITECH PROJECT, 2018
** PSU_myirc_2017
** File description:
** client.h
*/

#ifndef CLIENT_H_
# define CLIENT_H_

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <sys/select.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netinet/ip.h>
#include <netdb.h>
#include <arpa/inet.h>

# define LOCALHOST	"127.0.0.1"
# define BUFF_SIZE	4096
# define SOCKET_ERROR	-1
# define LEN_NICKNAME	9
# define LEN_CHANNEL	20

typedef struct			s_socket
{
	int			fd;
	struct sockaddr_in	s;
	socklen_t		len;
}t_socket;

typedef struct			s_client
{
	struct protoent		*protocol;
	bool			connected;
	char			**command;
	char			*port;
	char			*host;
	char			*answer;
	fd_set			read;
	fd_set			write;
	t_socket		*socket;
}t_client;

typedef struct			s_instructions
{
	char			*real_instruct[10];
	int			(*_instruct[10])(t_client *Newclient);
}t_instructions;

/* Handle Client */
int		init_client(t_client *Newclient);
int		launch_client(t_client *Newclient);
int		delete_client(t_client *Exclient);
int		help_client(char *binary);
void		prompt(void);

/* Handle FD_SET */
void		init_fds(int fd, fd_set *r, fd_set *w, struct timeval *t);
int		check_fds(t_client *NewClient);

/* Handle Socket */
int		init_socket(t_client *Newclient, const char *protocol);
int		close_socket(t_client *Newclient);
int		connect_socket(t_client *Newclient);

/* Handle Server */
int		wait_connection(t_client *Newclient);
int		connection_server(t_client *Newclient);

/* Handle Instructions */
void		init_instructions(t_instructions *ptr);
void		display_instructions(void);
int		read_instruction(int fd, t_client *Newclient);
int		send_instruction(t_client *Newclient, int fd);
int		parse_instruction(t_client *Newclient);
int		find_instruction(t_client *Newclient, t_instructions *ptr);

/* Instructions */
int		nickname(t_client *Newclient);
int		is_channel(t_client *Newclient);
int		list_channel(t_client *Newclient);
int		is_connected(t_client *Newclient);
int		send_msg(t_client *Newclient);

/* Is this a real Instruction ? */
bool		is_nickname(char *nickname);
bool		is_achannel(char *channel);

/* Handle Arguments */
int		is_writearguments(t_client *Newclient);
int		is_hostname(char *host);
int		is_port(char *port);

#endif /* !CLIENT_H_ */
