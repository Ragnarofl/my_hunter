##
## EPITECH PROJECT 2018
## Makefile
## File description:
## Makefile
##

CC		=	gcc

CFLAGS	=	-Wall -Wextra -W -Werror

SRC		=	my_putchar.c				\
			my_put_nbr.c				\
			my_swap.c					\
			my_sort_int_array.c			\
			my_show_word_array.c		\
			my_isneg.c					\
			my_getnbr.c					\
			my_strlen.c					\
			my_nbrlen.c					\
			my_is_prime.c				\
			my_find_prime_sup.c			\
			my_putstr.c					\
			my_showstr.c				\
			my_compute_square_root.c	\
			my_str_isnum.c				\
			my_str_isalpha.c			\
			my_str_islower.c			\
			my_str_isupper.c			\
			my_str_isprintable.c		\
			my_showmem.c				\
			my_compute_power_rec.c		\
			my_strcmp.c					\
			my_strncmp.c				\
			my_strcat.c					\
			my_strncat.c				\
			my_strcpy.c					\
			my_strncpy.c				\
			my_revstr.c					\
			my_strcapitalize.c			\
			my_strlowcase.c				\
			my_strupcase.c				\
			my_strstr.c					\
			my_malloc.c					\
			my_itoa.c					\
			../printf/my_printf.c		\
			../printf/my_dprintf.c		\
			../printf/formats.c			\
			../printf/formaters.c		\
			../printf/formats_base.c	\
			../printf/my_putnbr_base.c	\
			../printf/expr.c			\
			../printf/flags.c			\
			../printf/padding.c

OBJ		=	*.o

NAME	=	libmy.a

all: $(NAME)

$(NAME): $(OBJ)
		gcc -c $(SRC)
		ar rc $(NAME) $(OBJ)
		rm -f $(OBJ)

clean:	$(OBJ)
		rm -f $(OBJ)

fclean: clean
		rm -f $(NAME)

re: fclean all
