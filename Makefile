##
## EPITECH PROJECT, 2018
## PSU_myirc_2017
## File description:
## Makefile
##

all:
	@(cd ./Sources/Client/ && $(MAKE))
	@(cd ./Sources/Server/ && $(MAKE))

server:
	@(cd ./Sources/Server/ && $(MAKE))

client:
	@(cd ./Sources/Client/ && $(MAKE))

clean:
	cd ./Sources/Server/ && ($(MAKE) clean)
	cd ./Sources/Client/ && ($(MAKE) clean)
fclean:
	cd ./Sources/Server/ && ($(MAKE) fclean)
	cd ./Sources/Client/ && ($(MAKE) fclean)

re: fclean all

.PHONY: all clean fclean re server client
