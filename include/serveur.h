/*
** EPITECH PROJECT, 2018
** my_irc
** File description:
** serveur.h
*/

#ifndef SERVEUR_H_
# define SERVEUR_H_

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

# define MAX 1024
# define BUFF 2048
# define WELCOME	"Welcome to my IRC.\r\n"

typedef struct			s_serveur
{
	struct protoent		*protocol;
	struct sockaddr_in	s_in;
	int			port;
	int			fd;
	int			sd;
	int			s_in_size;
	int			statut;
	int			sd_size;
	int			cfd;
	int			cfdl[MAX];
	char			buff[BUFF];
	fd_set			rset;
}				t_serveur;

int			get_port(int ac, char **av);
int			run_processus(t_serveur *serveur);
int			handle_packet(t_serveur *serveur);
int			handle_connection(t_serveur *serveur);
int			client_processus(t_serveur *serveur);
t_serveur		*init_serveur(int ac, char **av);

#endif /* !SERVEUR_H_ */
