##
## EPITECH PROJECT, 2022
## B-CPE-110-LYN-1-1-BSQ-vivien.boitard
## File description:
## Makefile
##

SRC	=	$(wildcard src/*.c)

NAME	=	my_sokoban

CFLAGS	=	-Wall -Wextra -I./include -g3

LDLIBS	=	-L./src/lib/my -lmy

NCURSES	=	-lncurses

CC	=	gcc

all:	$(NAME)

$(NAME):	$(SRC)
	make -C src/lib/my
	$(CC) -o $(NAME) $(SRC) $(NCURSES) $(CFLAGS) $(LDLIBS)

clean:
	make clean -C src/lib/my
	find . -type f -name "vgcore.*" -delete

fclean:	clean
	make clean -C src/lib/my
	rm -f $(NAME)

re:	fclean all
