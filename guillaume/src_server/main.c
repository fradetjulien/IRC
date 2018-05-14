/*
** EPITECH PROJECT, 2018
** 
** File description:
** 
*/

#include "server.h"

t_serv	*init_serv(int ac, char **av)
{
   t_serv	*serv;

   if ((serv = malloc(sizeof(t_serv))) == NULL)
      return (NULL);
   serv->port = get_port(ac, av);
   if (serv->port == -1)
	   return (NULL);
   serv->s_in.sin_family = AF_INET;
   serv->s_in.sin_port = htons(serv->port);
   serv->s_in.sin_addr.s_addr = INADDR_ANY;
   serv->statut = 1;
   //init cmd command func
   if ((handle_connect(serv)) == 0)
      return (NULL);
   return (serv);
}

int main(int ac, char **av)
{
   t_serv	*s;

   if ((s = init_serv(ac, av)) == NULL)
	   return (1);
   if (run_process(s) == 0)
	   return (1);
   if (close(s->ssd) == -1)
	   return(1);
   free(s);
   return (0);
}
