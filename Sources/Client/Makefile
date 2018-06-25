##
## EPITECH PROJECT, 2018
## PSU_zappy_2017
## File description:
## Makefile
##

CC			= gcc -g

RM			= rm -f

CFLAGS			+= -Wextra -Wall -I ../Includes/

NAME_CLIENT		= ../zappy_ai

SRC_CLIENT		=	handle_client/client.c 			\
				handle_client/init_client.c 		\
				handle_client/help_client.c		\
				handle_client/launch_client.c		\
				handle_server/wait_connection.c		\
				handle_instructions/read_instruction.c	\
				handle_arguments/is_writearguments.c	\
				handle_arguments/is_hostname.c		\
				handle_arguments/is_port.c		\
				../Common/library/str_to_wordtab.c	\
				../Common/library/get_next_line.c	\
				../Common/library/epur_str.c

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
