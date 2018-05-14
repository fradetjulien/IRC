/*
** EPITECH PROJECT, 2018
** my_irc
** File description:
** init_client.c
*/

#include "client.h"

void		init_client(t_client *client)
{
	client.under_way = 1;
	client.connected = 0;
}
