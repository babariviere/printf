NAME=libftprintf.a

CONV_NAME=undefined.c # s.c
BUF_NAME=new.c del.c realloc.c putc.c putstr.c
FT_NAME=ft_memalloc.c ft_memcpy.c ft_strlen.c\
		ft_strncpy.c ft_memset.c ft_strncpy.c
SRC_NAME=printf.c do_conv.c\
		 $(addprefix conv/, $(CONV_NAME))\
		 $(addprefix buf/, $(BUF_NAME))\
		 $(addprefix ft/, $(FT_NAME))
SRC=$(addprefix src/, $(SRC_NAME))
OBJ=$(patsubst src/%.c, obj/%.o, $(SRC))

CC=clang
CFLAGS=-Wall -Werror -Wextra -Iinclude

all: $(NAME)

$(NAME): $(OBJ)
	@printf "==> archiving $@\n" $@
	@ar rcs $@ $(OBJ)

obj/%.o: src/%.c
	@mkdir -p $(shell dirname $@)
	@printf "==> compiling %s\n" $@
	@$(CC) $(CFLAGS) -o $@ -c $<

clean:
	@rm -rf obj

fclean: clean
	@rm -f $(NAME)

re: fclean all
