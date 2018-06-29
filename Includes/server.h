/*
** EPITECH PROJECT, 2018
** PSU_myirc_2017
** File description:
** server.h
*/

#ifndef SERVER_H_
# define SERVER_H_

#include <unistd.h>
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

typedef struct			t_socket
{
	int			fd;
	struct sockaddr_in	s;
	socklen_t		len;
}t_socket;

typedef struct			s_server
{
	struct protoent		*protocol;
	int			port;
	bool			alive;
	struct timeval		*time;
	fd_set			read;
	fd_set			write;
	t_list			*clients;
	t_list			*channel;
	t_socket		*socket;
}t_server;

/* Handle Server */
int		init_server(t_server *myserver, const char *port);
int		launch_server(t_server *myserver);
void		help_server(char *binary);

/* Handle Socket */
int		init_socket(t_server *myserver, const char *protocol);
int		bind_socket(t_server *myserver);
int		listen_socket(t_server *myserver);
int		close_socket(t_server *myserver);

/* Handle Fd Set */
void		init_fds(t_server *server);
int		check_fds(t_server *myserver);

/* Handle Arguments */
int		is_port(char *port);

#endif /* !SERVER_H_ */
