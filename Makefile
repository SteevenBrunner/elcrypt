##
## Makefile for Makefile in /home/brunne_s/rendu/elcrypt
## 
## Made by Steeven Brunner
## Login   <brunne_s@epitech.net>
## 
## Started on  Sat Mar 14 11:00:38 2015 Steeven Brunner
## Last update Sat Mar 14 18:19:04 2015 Steeven Brunner
##

NAME	=	elcrypt

SRC	=	main.c \
		parsing.c \
		decrypt.c

OBJ	=	$(SRC:.c=.o)

CFLAGS	=	-W -Wall -ansi -pedantic

$(NAME): $(OBJ)
	cc $(CFLAGS) $(OBJ) -o $(NAME)

all:	$(NAME)

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)

re:	fclean all
