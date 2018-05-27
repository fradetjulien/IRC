/*
** EPITECH PROJECT, 2018
** 
** File description:
** 
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/select.h>
#include <sys/ioctl.h>
#include <sys/socket.h>
#include <sys/time.h>
#include <netdb.h>
#include <netinet/in.h>
#include <errno.h>
#include "server.h"

t_serv	*init_serv(int ac, char **av)
{
	t_serv	*serv;

	if ((serv = malloc(sizeof(t_serv))) == NULL)
		return (NULL);
	serv->port = atoi(av[1]);
	serv->s_in.sin_family = AF_INET;
	serv->s_in.sin_port = htons(serv->port);
	serv->s_in.sin_addr.s_addr = INADDR_ANY;
	serv->statut = 1;
	serv->channel = NULL;
	serv->user = NULL;
	//init cmd command func
	if ((handle_connect(serv)) == 0)
		return (NULL);
	return (serv);
}

int	main(int ac, char **av)
{
	t_serv	*s;

   if (ac != 2 || is_num(av[1]) == -1)
   {
      printf("USAGE: sudo ./server <port>\n");
      return (-84);
   }
	if ((s = init_serv(ac, av)) == NULL)
		return (-84);
	if (run_process(s) == 0)
		return (-84);
	if (close(s->ssd) == -1)
		return(-84);
	free(s);
	return (0);
}
