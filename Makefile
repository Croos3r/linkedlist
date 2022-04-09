##
## EPITECH PROJECT, 2022
##
## File description:
## Makefile of the project
##

SRC_DIR			=	src
SRC				=	$(wildcard $(SRC_DIR)/*.c)
OBJ				=	$(SRC:.c=.o)
TST_DIR			=	tests
TST				=	$(wildcard $(TST_DIR)/*.c)
TST_OBJ			=	$(SRC:.c=.o) $(TST:.c=.o)
LIB_DIR			=
LIBS			=
LIBS_ARCHIVES	=	$(LIBS:%=$(LIB_DIR)/lib%.a)

NAME			=	linkedlist
ARCHIVE			=	$(NAME:%=lib%.a)
TST_BINARY		= 	$(ARCHIVE).test

CPPFLAGS		+= 	-Wall -Wextra -iquote "include"
CFLAGS			+=
LDFLAGS			+= 	-L $(LIB_DIR)
LDLIBS			+= 	$(addprefix -l, $(LIBS))

CC				=	gcc
AR				=	ar

# Build targets:

all: $(ARCHIVE)

$(ARCHIVE): $(OBJ)
	$(AR) rc $(ARCHIVE) $(OBJ)

$(TST_BINARY): LIBS		+=	criterion gcov
$(TST_BINARY): CFLAGS 	+=	-ftest-coverage -fprofile-arcs
$(TST_BINARY): $(TST_OBJ) $(LIBS_ARCHIVES)
	$(CC) $(TST_OBJ) -o $(TST_BINARY) $(LDFLAGS) $(LDLIBS)

$(LIBS_ARCHIVES): $(LIB_DIR)
	$(MAKE) -C $(@:$(LIB_DIR)/lib%.a=$(LIB_DIR)/%)

re:	fclean all

# Tests and debug:

tests_run: $(TST_BINARY)
	./$(TST_BINARY)
	gcovr --exclude $(TST_DIR)
	gcovr --exclude $(TST_DIR) --branches

debug: $(DEBUG_ARCHIVE)
	valgrind ./$(DEBUG_ARCHIVE) $(ARGS)

# Cleaning targets:

clean:
	$(RM) $(OBJ) $(TST_OBJ)

fclean: clean
	$(RM) $(ARCHIVE) $(TST_BINARY)

aclean: fclean
	find . \( -ARCHIVE "#*#" -o -ARCHIVE "*~" -o -ARCHIVE "*.gcda" \
	-o -ARCHIVE "*.gcno" -o -ARCHIVE "vgcore.*" \) -delete

# Makefile's safety:

.PHONY: all clean fclean aclean build_lib tests_run re debug
