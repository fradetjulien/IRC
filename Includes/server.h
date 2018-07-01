/*
** EPITECH PROJECT, 2018
** PSU_myirc_2017
** File description:
** server.h
*/

#ifndef SERVER_H_
# define SERVER_H_

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/time.h>
#include <sys/select.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <errno.h>
#include <stdbool.h>
#include "linked_list.h"

# define SOCKET_ERROR	-1
# define MAX_CLIENTS	10

typedef struct			t_socket
{
	int			fd;
	int			fd_max;
	struct sockaddr_in	s;
	socklen_t		len;
}t_socket;

typedef struct			s_client
{
	char			*nickname;
	bool			connected;
	bool			chatting;
	t_socket		*socket;
}t_client;

typedef struct			s_server
{
	struct protoent		*protocol;
	struct timeval		time;
	int			port;
	bool			alive;
	fd_set			read;
	fd_set			write;
	int			nb_client;
	t_client		*client;
	int			pos;
	char			*received;
	char			**command;
	t_list			*clients;
	t_list			*channel;
	t_socket		*socket;
}t_server;

typedef struct			s_instructions
{
	char			*real_instruct[12];
	int			(*_instruct[12])(t_server *myserver);
}t_instructions;

/* Handle Server */
int		init_server(t_server *myserver, const char *port);
int		launch_server(t_server *myserver);
void		help_server(char *binary);

/* Handle Socket */
int		init_socket(t_server *myserver, const char *protocol);
int		bind_socket(t_server *myserver);
int		listen_socket(t_server *myserver);
int		close_socket(t_server *myserver);

/* Handle Client */
int		init_client(t_client *New_client);
int		socket_client(t_server *server);

/* Handle Fd Set */
void		init_fds(t_server *server);
int		check_fds(t_server *myserver);

/* Handle Instruction */
void		init_instructions(t_instructions *ptr);
int		read_instruction(int fd, t_server *myserver);
int		send_instruction(t_server *myserver, int fd);
int		parse_instruction(t_server *myserver);
int		find_instruction(t_server *myserver, t_instructions *ptr);

/* Instructions */
int		delete_client(t_server *myserver);
int		print_yo(t_server *myserver);

/* Handle Arguments */
int		is_port(char *port);

#endif /* !SERVER_H_ */
