##
## EPITECH PROJECT, 2018
## 
## File description:
## 
##


SRC_CTL	= main.c	\
	  client.c	\
	  utils.c	\
	  struct.c

SRC_SRV	= handle_client.c	\
	  handle_connect.c	\
	  handle_packet.c	\
	  main.c		\
	  run_process.c

OBJ_CTL	= $(addprefix src_client/, $(SRC_CTL:.c=.o))

OBJ_SRV	= $(addprefix src_server/, $(SRC_SRV:.c=.o))

LDFLAGS = -lm -g

CFLAGS	= -I./include/ -g

RM 	= rm -f

CC	= gcc

NAME_SRV	= server

NAME_CTL	= client

all:	$(NAME_SRV) $(NAME_CTL)

$(NAME_CTL): $(OBJ_CTL)
	$(CC) -o $(NAME_CTL) $(OBJ_CTL) $(LDFLAGS) $(CFLAGS)

$(NAME_SRV): $(OBJ_SRV)
	$(CC) -o $(NAME_SRV) $(OBJ_SRV) $(LDFLAGS) $(CFLAGS)

clean:
	$(RM) $(OBJ_CTL)
	$(RM) $(OBJ_SRV)

fclean:
	$(RM) $(OBJ_CTL)
	$(RM) $(OBJ_SRV)
	$(RM) $(NAME_CTL)
	$(RM) $(NAME_SRV)

re: fclean all

.PHONY: all clean fclean re
