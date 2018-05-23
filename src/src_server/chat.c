#include "server.h"

int		send_to_users(t_user *user, char *m)
{
	if (user == NULL)
		return (1);
	while (user->next != NULL)
	{
		printf("port: %d\n", user->fd);
		send(user->fd, m, strlen(m), 0);
		user = user->next;
	}
	send(user->fd, m, strlen(m), 0);
	return (1);
}