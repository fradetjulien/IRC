/*
** EPITECH PROJECT, 2018
** 
** File description:
** 
*/

#include "client.h"

int	main(int ac, char **av)
{
	int			sockfd;
	char			*recvline[100];
	struct sockaddr_in	servaddr;
	t_client		*client;

	if (ac != 3)
		return (84);
	if ((sockfd = socket(AF_INET,SOCK_STREAM,0)) < 0)
		return (84);
	bzero(&servaddr,sizeof servaddr);
	servaddr.sin_family = AF_INET;
	servaddr.sin_port = htons(atoi(av[2]));
	if (inet_pton(AF_INET, av[1],&(servaddr.sin_addr)) <= 0
	    || (connect(sockfd,(struct sockaddr *)&servaddr,sizeof(servaddr))) == -1)
	{
		fprintf(stderr, "Impossible to connect to server %s:%s\n", av[1], av[2]);
		return (84);
	}
	usleep(300000);
	if ((client = init_client(sockfd)) == NULL)
		return (0);
	while(1)
		begin_client(client);
}
