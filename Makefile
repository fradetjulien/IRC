##
## EPITECH PROJECT, 2018
## my_irc
## File description:
## Makefile
##

CC	= gcc -g

DIR_SERVEUR	= ./src/serveur

DIR_CLIENT	= ./src/client

DIR_COMMON	= ./src/common

SRC_SERVEUR	= $(DIR_SERVEUR)/serveur.c	\
		  $(DIR_SERVEUR)/get_port.c

SRC_CLIENT	= $(DIR_CLIENT)/client.c	\

SRC_COMMON	= $(DIR_COMMON)/flag_help.c	\
		  $(DIR_COMMON)/is_num.c

OBJ_SERVEUR	= $(SRC_SERVEUR:.c=.o)

OBJ_CLIENT	= $(SRC_CLIENT:.c=.o)

OBJ_COMMON	= $(SRC_COMMON:.c=.o)

RM	= rm -f

CFLAGS	= -Wextra -Wall -Werror -fpic -shared

CFLAGS += -I include/

NAME	= myirc

serveur	= serveur

client	= client

$(serveur): $(OBJ_SERVEUR) $(OBJ_COMMON)
	$(CC) $(CFLAGS) -o $(serveur) $(OBJ_SERVEUR) $(OBJ_COMMON)

$(client): $(OBJ_CLIENT) $(OBJ_COMMON)
	$(CC) $(CFLAGS) -o $(client) $(OBJ_CLIENT) $(OBJ_COMMON)

all: $(serveur) $(client)

clean:
	$(RM) $(OBJ_CLIENT) $(OBJ_SERVEUR) $(OBJ_COMMON)

fclean: clean
	$(RM) $(serveur) $(client)

re: fclean all

.PHONY: all clean fclean re
