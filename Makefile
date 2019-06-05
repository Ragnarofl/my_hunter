## EPITECH PROJECT, 2018
## Makefile
## File description:
## Simon-Perraud
##

CC		=	gcc

CFLAGS	=	-Wall -Wextra -W -I include/ -g3

##CFLAGS	+=	-I~/.graph_programming/include/SFML/

LIB		=	 -L./lib/my -lmy	\
			-lcsfml-audio		\
			-lcsfml-graphics	\
			-lcsfml-network		\
			-lcsfml-window		\
			-lcsfml-system

SRC		=	main.c		\
			clock.c		\
			create.c	\
			list.c		\
			title.c		\
			buttons.c	\
			text.c		\
			file.c		\
			score.c		\
			duck.c		\
			game.c

OBJ		=	$(SRC:.c=.o)

NAME	=	my_hunter

all: $(NAME)

$(NAME):	$(OBJ)
	make -C lib/my all
	$(CC) $(OBJ) $(CFLAGS) $(LIB) -o $(NAME)
	rm -f $(OBJ)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
