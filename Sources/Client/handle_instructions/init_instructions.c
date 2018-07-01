/*
** EPITECH PROJECT, 2018
** PSU_myirc_2017
** File description:
** init_instructions.c
*/

#include "../../../Includes/client.h"

void		following_init(t_instructions *ptr)
{
	ptr->_instruct[0] = &connection_server;
	ptr->_instruct[1] = &nickname;
	ptr->_instruct[2] = &list_channel;
	ptr->_instruct[3] = &is_channel;
	ptr->_instruct[4] = &is_channel;
	ptr->_instruct[5] = &is_connected;
	ptr->_instruct[6] = &is_channel;
	ptr->_instruct[7] = &send_msg;
	ptr->_instruct[8] = &nickname;
	ptr->_instruct[9] = &channel_message;
	ptr->_instruct[10] = &quit_server;
	ptr->_instruct[11] = &quit;
	ptr->_instruct[12] = NULL;
}

void		init_instructions(t_instructions *ptr)
{
	ptr->real_instruct[0] = "/server";
	ptr->real_instruct[1] = "/nick";
	ptr->real_instruct[2] = "/list";
	ptr->real_instruct[3] = "/join";
	ptr->real_instruct[4] = "/part";
	ptr->real_instruct[5] = "/users";
	ptr->real_instruct[6] = "/names";
	ptr->real_instruct[7] = "/msg";
	ptr->real_instruct[8] = "/accept_file";
	ptr->real_instruct[9] = "$";
	ptr->real_instruct[10] = "/quit";
	ptr->real_instruct[11] = "exit";
	ptr->real_instruct[12] = NULL;
	following_init(ptr);
}
