##
## EPITECH PROJECT, 2018
## PSU_zappy_2017
## File description:
## Makefile
##

CC			= gcc -g

RM			= rm -f

CFLAGS			+= -Wextra -Wall -I ../Includes/

NAME_CLIENT		= ../../client

SRC_CLIENT		=	handle_client/client.c 					\
				handle_client/init_client.c 				\
				handle_client/help_client.c				\
				handle_client/launch_client.c				\
				handle_client/delete_client.c				\
				handle_server/wait_connection.c				\
				handle_server/connection_server.c			\
				handle_instructions/init_instructions.c			\
				handle_instructions/parse_instruction.c			\
				handle_instructions/read_instruction.c			\
				handle_instructions/send_instruction.c			\
				handle_instructions/display.c				\
				handle_instructions/find_instruction.c			\
				handle_instructions/instructions/nickname.c		\
				handle_instructions/instructions/is_channel.c		\
				handle_instructions/instructions/list_channel.c		\
				handle_instructions/instructions/is_connected.c		\
				handle_instructions/instructions/send_msg.c		\
				handle_instructions/instructions/channel_message.c	\
				handle_instructions/instructions/quit.c			\
				handle_socket/close_socket.c				\
				handle_socket/init_socket.c				\
				handle_socket/connect_socket.c				\
				handle_fdset/init_fds.c					\
				handle_fdset/check_fds.c				\
				handle_arguments/is_writearguments.c			\
				handle_arguments/is_hostname.c				\
				handle_arguments/prompt.c				\
				handle_arguments/counter_args.c				\
				../Common/is_port.c					\
				../Common/library/str_to_wordtab.c			\
				../Common/library/get_next_line.c			\
				../Common/library/epur_str.c				\
				../Common/library/my_putchar.c				\
				../Common/library/my_putstr.c				\
				../Common/library/is_num.c				\
				../Common/library/is_caract.c				\
				../Common/library/is_special.c

OBJ_CLIENT	     = $(SRC_CLIENT:.c=.o)

$(NAME_CLIENT): $(OBJ_CLIENT)
	$(CC) -o $(NAME_CLIENT) $(CFLAGS) $(OBJ_CLIENT)

all: $(NAME_CLIENT)

clean:
	$(RM) $(OBJ_CLIENT)

fclean:
	$(RM) $(OBJ_CLIENT)
	$(RM) $(NAME_CLIENT)

re: fclean all

.PHONY: all clean fclean re server client
