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
#include <unistd.h>

typedef struct			s_serveur
{
	struct protoent		protocol;
	struct sockaddr_in	serveur_addr;
	int			port;
	int			fd;
}				t_serveur;

int			get_port(int ac, char **av);

#endif /* !SERVEUR_H_ */
