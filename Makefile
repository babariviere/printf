NAME=libftprintf.a

SRC_NAME=printf.c
SRC=$(addprefix src/, $(SRC_NAME))
OBJ=$(patsubst src/%.c, obj/%.o, $(SRC))

CC=clang
CFLAGS=-Wall -Werror -Wextra -Iinclude

all: $(NAME)

$(NAME): $(OBJ)
	@ar rcs $@ $<

obj/%.o: src/%.c
	@mkdir -p $(shell dirname $@)
	@printf "==> compiling %s\n", $@
	@$(CC) $(CFLAGS) -o $@ -c $<
