/*
** EPITECH PROJECT, 2018
** PSU_myirc_2017
** File description:
** init_instructions.c
*/

#include "../../../Includes/server.h"

void		real_instructions(t_instructions *ptr)
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
	ptr->real_instruct[11] = NULL;
}

void		fct_instructions(t_instructions *ptr)
{
	ptr->_instruct[0] = &print_yo;
	ptr->_instruct[1] = &print_yo;
	ptr->_instruct[2] = &print_yo;
	ptr->_instruct[3] = &print_yo;
	ptr->_instruct[4] = &print_yo;
	ptr->_instruct[5] = &print_yo;
	ptr->_instruct[6] = &print_yo;
	ptr->_instruct[7] = &print_yo;
	ptr->_instruct[8] = &print_yo;
	ptr->_instruct[9] = &print_yo;
	ptr->_instruct[10] = &delete_client;
	ptr->_instruct[11] = NULL;

}

void		init_instructions(t_instructions *ptr)
{
	real_instructions(ptr);
	fct_instructions(ptr);
}
