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
				handle_server/wait_connection.c

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
