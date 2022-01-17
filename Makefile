##
## EPITECH PROJECT, 2021
## LibLinkedList
## File description:
## Makefile of the project
##

SRC			=	src/list.c	\
				src/list2.c
OBJ			=	$(SRC:.c=.o)
TST			=	tests/test_lists.c
TST_OBJ		=	$(SRC:.c=.o) $(TST:.c=.o)

NAME		=	liblinkedlist.a

CPPFLAGS 	+=	-iquote include
CFLAGS		+=	-Wall -Wextra -Wpedantic
LDFLAGS 	+=	-Llib/my
LDLIBS		+=	-lmy

CC			=	gcc
AR			=	ar

all:	$(NAME)

$(NAME):	$(OBJ)
	$(AR) rc $(NAME) $(OBJ)

clean:
	@find . \( -name "#*#" -o -name "*~" -o -name "*.o" \
	-o -name "*.gcda" -o -name "*.gcno" -o -name "vgcore.*" \) -delete

fclean:	clean
	@rm -f $(NAME)
	@rm -f $(NAME).test
	@make fclean -C lib/my

build_lib:
	@make -C lib/my

tests_run:	LDLIBS	+=	-lcriterion
tests_run:	CFLAGS	+=	--coverage
tests_run:	clean	$(TST_OBJ)	build_lib
	$(CC) $(TST_OBJ) -o $(NAME).test $(LDFLAGS) $(LDLIBS) --coverage
	./$(NAME).test
	gcovr --exclude tests/
	gcovr --exclude tests/ --branches

re:	fclean all

.PHONY: all clean fclean build_lib tests_run re $(NAME)
