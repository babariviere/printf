NAME=libftprintf.a

CONV_NAME=s.c upper_s.c upper_u.c\
		  ll_base.c upper_x.c x.c d.c flags_pad.c\
		  o.c p.c u.c upper_o.c upper_d.c c.c upper_c.c\
		  b.c
BUF_NAME=new.c del.c realloc.c putc.c putstr.c
FT_NAME=ft_memalloc.c ft_memcpy.c ft_strlen.c\
		ft_strncpy.c ft_memset.c ft_strncpy.c\
		ft_strdup.c ft_putchar.c ft_putstr.c\
		ft_strnew.c ft_wcharcpy.c ft_atoi.c\
		ft_numlen.c ft_iswhitespace.c ft_strndup.c\
		ft_realloc.c ft_memmove.c
SRC_NAME=printf.c do_conv.c flags.c padding.c\
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
