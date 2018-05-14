/*
** EPITECH PROJECT, 2018
** my_irc
** File description:
** client.c
*/

int			main(int ac, char **av)
{
	t_client	client;

	init_client(&client);
	loop_client(&client);
	return (0);
}
