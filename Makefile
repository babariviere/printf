NAME=libftprintf.a

CONV_NAME=undefined.c # s.c
BUF_NAME=new.c delete.c realloc.c putc.c putstr.c
SRC_NAME=printf.c $(addprefix conv/, $(CONV_NAME))\
		 $(addprefix buf/, $(BUF_NAME))
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
