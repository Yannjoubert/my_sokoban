##
## EPITECH PROJECT, 2020
## Makefile
## File description:
## Makefile
##

CC	=	gcc

SRC		=	main.c \
			error.c	\
			read_file.c	\
			sokoban.c	\
			move_funct.c \
			check_coord.c \
			my_str_to_word_array.c

OBJ		=	$(SRC:.c=.o)

NAME	=	my_sokoban

LIBMY 	= 	-L./lib/my/ -lmy

UTN		= 	unit_test

UTS		=	read_file.c \
			tests/test_read_file.c

UTFLAGS	=	-l criterion --coverage

CFLAGS	=	-I ./include -lncurses -W -Wall -Werror -Wextra -g3

all: 	$(NAME)

tests_run:
	$(CC) -o $(UTN) $(UTS) $(UTFLAGS) $(CFLAGS)
	./$(UTN)

build_lib:
	make -C lib/my/ all

$(NAME): build_lib
	$(CC) -o $(NAME) $(SRC) $(CFLAGS) $(LIBMY)

clean:
	make -C lib/my/ clean
	rm -f $(OBJ)
	rm -f *.gc*

fclean: clean
	make -C lib/my/ fclean
	rm -f $(NAME)
	rm -f libmy.a
	rm -f $(UTN)

re: fclean all
