/*
** EPITECH PROJECT, 2018
** PSU_myirc_2017
** File description:
** display_instructions.c
*/

#include "../../../Includes/client.h"
#include "../../../Includes/library.h"

void		display_instructions(void)
{
	my_putstr("Here are the commands that you can execute :\n"
	"\t/server $host[:$port]: connects to a server\n"
	"\t/nick $nickname: defines the user’s nickname in the server\n"
	"\t/list [$string]: lists the server’s available channels.\n"
	"\tOnly display the channels that contain the $string string"
	"when specified)\n"
	"\t/join $channel: joins a server’s channel\n"
	"\t/part $channel: leaves a channel\n"
	"\t/users: lists the nicknames of the users that are connected"
	"to the server\n"
	"\t/names $channel: lists the nicknames of the users connected"
	" to the channel\n"
	"\t$message: sends a message to all of the users that"
	"are connected"
	" to the channel\n"
	"\t/msg $nickname $message: sends a message to a specific"
	"user\n"
	"\t/msg $channel $nickname $file: sends a file to a user\n"
	"\t/accept_file $nickname: accepts the reception"
	"of a file coming from one of the channel’s users\n");
}
