/*
** EPITECH PROJECT, 2018
** my_irc
** File description:
** list_cmd.c
*/

#include "client.h"

void		list_cmd(char **cmd_client)
{
	cmd_client[0] = "/server";
	cmd_client[1] = "/nick";
	cmd_client[2] = "/list";
	cmd_client[3] = "/join";
	cmd_client[4] = "/part";
	cmd_client[5] = "/users";
	cmd_client[6] = "/names";
	cmd_client[7] = "/msg";
	cmd_client[8] = "/accept_file";
	cmd_client[9] = "/quit";
	cmd_client[10] = NULL;
}
