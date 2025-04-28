##
## EPITECH PROJECT, 2025
## B-CCP-400-LIL-4-1-panoramix-ewan.tirlemont
## File description:
## Makefile
##

CC = gcc
CFLAGS = -Wall -Wextra -Werror -Iinclude -pthread
NAME = panoramix
SRC =	src/main.c 					\
		src/Panoramix/panoramix.c	\
		src/Panoramix/druid.c 		\
		src/Panoramix/villager.c 	\
		src/Utils/utils.c
OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
