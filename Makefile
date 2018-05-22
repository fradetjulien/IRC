##
## EPITECH PROJECT, 2018
## 
## File description:
## 
##


SRC_CTL	= display_cmd.c		\
	  client.c		\
	  help_client.c		\
	  init_client.c		\
	  loop_client.c		\
	  display_prompt.c	\
	  fct_socket.c		\
	  other_socket.c	\
	  list_cmd.c		\
	  parse_cmd.c		\
	  send_message.c	\
	  connection_server.c	\
	  send_to_server.c	\
	  quit_server.c

SRC_SRV	= handle_client.c	\
	  handle_connect.c	\
	  handle_packet.c	\
	  main.c		\
	  run_process.c

SRC_COM	= flag_help.c		\
	  is_num.c		\
	  my_epur_str.c		\
	  my_str_to_wordtab.c	\
	  get_next_line.c	\
	  create_buffer.c	\
	  write_into_buffer.c

OBJ_CTL	= $(addprefix src/src_client/, $(SRC_CTL:.c=.o))

OBJ_SRV	= $(addprefix src/src_server/, $(SRC_SRV:.c=.o))

OBJ_COM	= $(addprefix src/src_common/, $(SRC_COM:.c=.o))

LDFLAGS = -lm -g

CFLAGS	= -I./include/ -g

RM 	= rm -f

CC	= gcc

NAME_SRV	= server

NAME_CTL	= client

all:	$(NAME_SRV) $(NAME_CTL)

$(NAME_CTL): $(OBJ_CTL) $(OBJ_COM)
	$(CC) -o $(NAME_CTL) $(OBJ_CTL) $(OBJ_COM) $(LDFLAGS) $(CFLAGS)

$(NAME_SRV): $(OBJ_SRV) $(OBJ_COM)
	$(CC) -o $(NAME_SRV) $(OBJ_SRV) $(OBJ_COM) $(LDFLAGS) $(CFLAGS)

clean:
	$(RM) $(OBJ_CTL)
	$(RM) $(OBJ_SRV)

fclean:
	$(RM) $(OBJ_CTL)
	$(RM) $(OBJ_SRV)
	$(RM) $(OBJ_COM)
	$(RM) $(NAME_CTL)
	$(RM) $(NAME_SRV)

re: fclean all

.PHONY: all clean fclean re
