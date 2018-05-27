/*
** EPITECH PROJECT, 2018
** my_irc
** File description:
** client.h
*/

#ifndef CLIENT_H_
# define CLIENT_H_

#include <stdlib.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <sys/types.h>
#include <sys/select.h>
#include <sys/ioctl.h>
#include <sys/time.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <stdio.h>
#include "common.h"

typedef struct			s_client
{
	struct protoent		*protocol;
	struct sockaddr_in	s;
	fd_set			read;
	fd_set			write;
	int			port;
	int			fd;
	char			*IP;
	char			*cmd;
	int			actif;
	int			passif;
}				t_client;

void			display_cmd();
void			display_prompt();
void			help_client(char *binary);
void			list_cmd(char **cmd_client);
int			loop_client(t_client *client);
int			parse_cmd(char **cmd, t_client *client);
int			init_socket(t_client *client, const char *protocol);
int			close_socket(t_client *client);
int			connect_socket(t_client *client, int port, in_addr_t addr);
int			connection_server(t_client *client, char **cmd);
int			quit_server(t_client *client, char **cmd);
int			send_to_server(t_client *client, char **cmd);
int			send_message(t_client *client);
int			read_from_server(t_client *client);
int			parsing(t_client *client, char *line, char **cmd);
int			check_fd(t_client *client, char *line);
char			**get_cmd(t_client *client, char *line, char **cmd);
t_client		*init_client(t_client *client);

#endif /* !CLIENT_H_ */
