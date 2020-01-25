NAME = pathfinder

CFLAGS = -std=c11 -Wall -Wextra -Werror -Wpedantic

INC = pathfinder.h

INCS = $(addprefix inc/, $(INC))

LIB = libmx
LIBA := $(LIB)/libmx.a

SRC = main.c \
	mx_file_size.c \
	mx_err_handling.c \
	mx_atoi.c \
	mx_check_line.c \
	mx_check_digit.c \
	mx_get_strarr.c \
	mx_get_index.c \
	mx_pf_count_word.c \
	mx_check_unique_island.c \
	mx_del_intarr.c \
	mx_print_intarr.c \
	mx_matrix_adjacency.c \

SRCS = $(addprefix src/, $(SRC))

OBJ = $(SRC:%.c=%.o)

all: install

install:
	@make install -sC $(LIB)
	@clang $(CFLAGS) -c $(SRCS) -I $(INCS)
	@clang $(CFLAGS) $(OBJ) $(LIBA) -o $(NAME)
	@mkdir -p obj
	@mv $(OBJ) obj

uninstall: clean
	@rm -rf $(NAME)
	@make uninstall -sC $(LIB)

clean:
	@make clean -sC $(LIB)
	@rm -rf $(OBJ)
	@rm -rf obj

reinstall: uninstall install

test:
	@clang $(CFLAGS) -c $(SRCS) -I $(INCS)
	@clang $(CFLAGS) $(OBJ) $(LIBA) -o $(NAME)
	@mkdir -p obj
	@mv $(OBJ) obj
