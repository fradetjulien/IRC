/*
** EPITECH PROJECT, 2018
** PSU_myirc_2017
** File description:
** init_fds.c
*/

#include "../../../Includes/client.h"

void		init_fds(int fd, fd_set *read, fd_set *write, struct timeval *t)
{
	FD_ZERO(read);
	FD_ZERO(write);
	FD_SET(0, read);
	FD_SET(0, write);
	FD_SET(fd, read);
	FD_SET(fd, write);
	t->tv_sec = 0;
	t->tv_usec = 50;
}
