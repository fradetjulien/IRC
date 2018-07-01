##
## EPITECH PROJECT, 2018
## PSU_zappy_2017
## File description:
## Makefile
##

CC			= gcc -g

RM			= rm -f

CFLAGS			+= -Wextra -Wall -I ../Includes/

NAME_SERVER		= ../../server

SRC_SERVER		=	handle_server/server.c 					\
				handle_server/init_server.c				\
				handle_server/help_server.c				\
				handle_server/launch_server.c				\
				handle_socket/init_socket.c				\
				handle_socket/bind_socket.c				\
				handle_socket/listen_socket.c				\
				handle_socket/close_socket.c				\
				handle_fdset/init_fds.c					\
				handle_fdset/check_fds.c				\
				handle_clients/init_client.c				\
				handle_clients/socket_client.c				\
				handle_instructions/read_instruction.c			\
				handle_instructions/parse_instructions.c		\
				handle_instructions/init_instructions.c			\
				handle_instructions/find_instruction.c			\
				handle_instructions/send_instruction.c			\
				handle_instructions/instructions/delete_client.c	\
				../Common/is_port.c					\
				../Common/library/str_to_wordtab.c			\
				../Common/library/get_next_line.c			\
				../Common/library/epur_str.c				\
				../Common/library/my_putchar.c				\
				../Common/library/my_putstr.c				\
				../Common/library/is_num.c				\
				../Common/library/is_caract.c				\
				../Common/library/is_special.c				\
				../Common/linked_list/init_list.c			\
				../Common/linked_list/delete_list.c

OBJ_SERVER		= $(SRC_SERVER:.c=.o)

$(NAME_SERVER): $(OBJ_SERVER)
	$(CC) -o $(NAME_SERVER) $(CFLAGS) $(OBJ_SERVER)

all: $(NAME_SERVER)

clean:
	$(RM) $(OBJ_SERVER)

fclean:
	$(RM) $(OBJ_SERVER)
	$(RM) $(NAME_SERVER)

re: fclean all

.PHONY: all clean fclean re server client
