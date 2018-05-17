/*
** EPITECH PROJECT, 2018
** my_irc
** File description:
** display_cmd.c
*/

#include "client.h"

void		display_cmd()
{
	printf("Here are the commands that you can execute :\n");
	printf("\t/server $host[:$port]: connects to a server\n");
	printf("\t/nick $nickname: defines the user’s nickname in the server\n");
	printf("\t/list [$string]: lists the server’s available channels.\n");
	printf("\tOnly display the channels that contain the $string string (when specified)\n");
	printf("\t/join $channel: joins a server’s channel\n");
	printf("\t/part $channel: leaves a channel\n");
	printf("\t/users: lists the nicknames of the users that are connected to the server\n");
	printf("\t/names $channel: lists the nicknames of the users connected to the channel\n");
	printf("\t$message: sends a message to all of the users that are connected to the channel\n");
	printf("\t/msg $nickname $message: sends a message to a specific user\n");
	printf("\t/msg $channel $nickname $file: sends a file to a user\n");
	printf("\t/accept_file $nickname: accepts the reception of a file coming "
	       "from one of the channel’s users\n");
}
