##
## EPITECH PROJECT, 2022
## Makefile 
## File description:
## Makefile
##

CC	=	gcc

PTH	=	src/

SRC	=	$(PTH)main.c	\
		$(PTH)commande.c	\
		$(PTH)fonction_lib.c	\
		$(PTH)separator.c	\
		$(PTH)separ_str_normal.c	\
		$(PTH)doc_for_cd.c	\
		$(PTH)doc_concat_check.c	\
		$(PTH)doc_for_free.c	\
		$(PTH)doc_find_opt_my_env.c	\
		$(PTH)str_array_strcp_scp.c	\
		$(PTH)tabcpy_setenv.c

OBJ	=	$(SRC:.c=.o)

NAME	=	mysh

CFLAGS  =	-iquote ./includes/ -Wextra -Wall -g

all:    $(NAME)

$(NAME):	$(OBJ)
	$(CC) $(SRC) -o $(NAME) $(CFLAGS)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)
	rm -f *~
	rm -f *o
	rm -f include/*~
	rm -f src/*~
re:	fclean all

.PHONY: all clean fclean re
