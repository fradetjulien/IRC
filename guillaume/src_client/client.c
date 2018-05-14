/*
** EPITECH PROJECT, 2018
** 
** File description:
** 
*/

#include "client.h"

void	calc_rep(t_client *client)
{
	char	*msg = get_msg(client->fd);

	msg[strlen(msg) - 2] = 0;
	printf("Recv: %s\n", msg);
	if (strcmp("xxx Wrong Password", msg) == 0)
		client->statut = 0;
	else if (strncmp(msg, "257 ", 4) == 0)
		printf("%s\n", msg + 4);
	else if (strncmp(msg, "221 ", 4) == 0)
	{
		printf("Succesfull disconnect, exiting...\n");
		exit(EXIT_SUCCESS);
	}
}

int	begin_client(t_client *client)
{
	char sendline[100];
	
	if (client->statut == 0)
		printf("Enter USERNAME :\nUSER :");
	if (client->statut == 1)
		printf("Enter PASSWORD :\nPASS :");
	if (client->statut == 2)
		printf("- %s > ", client->user);
	bzero(sendline, 100);
	fgets(sendline,100,stdin);
	sendline[strlen(sendline) - 1] = 0;
	if (client->statut == 0)
	{
		dprintf(client->fd, "USER %s\r\n", sendline);
		client->statut++;
		client->user = strdup(sendline);
	}
	else if (client->statut == 1)
	{
		dprintf(client->fd, "PASS %s\r\n", sendline);
		client->statut++;
	}
	else if (client->statut == 2)
		dprintf(client->fd, "%s\r\n", sendline);
	calc_rep(client);
}
