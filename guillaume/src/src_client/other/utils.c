/*
** EPITECH PROJECT, 2018
** 
** File description:
** 
*/

#include "server.h"

char*	cat(char *dest, char *src)
{
	char	*ret;
	int	c = -1;
	int	i = -1;

	if ((ret = malloc(strlen(dest) + strlen(src))) == NULL)
		return (NULL);
	while (dest[++c])
		ret[c] = dest[c];
	while (src[++i])
		ret[++c] = src[i];
	ret[++c] = 0;
	return (ret);
}

char	*get_msg(int fd)
{
	int	len = -1;
	char	buff[1024];
	char	*ret;
	
	len = read(fd, buff, 1023);
	buff[len] = 0;
	if ((ret = malloc(strlen(buff) + 1)) == NULL)
		return (NULL);
	strcpy(ret, buff);
	return (ret);
}

void	send_msg(int fd, char *msg)
{
	write(fd, msg, strlen(msg));
}
