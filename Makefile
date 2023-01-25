NAME = libftprintf.a
SRC = ft_printf ft_hexadecimal ft_print_address ft_printf ft_putnbr\
ft_unsigned_decimal ft_words\

RM = rm -f
CC = cc

CFLAGS = -Wall -Werror -Wextra

all:$(NAME)

$(NAME): $(SRC:=.o)
			ar rc $(NAME) $(SRC:=.o)
clean:
	$(RM)	$(SRC:=.o)
fclean: clean
		$(RM)	$(NAME)
re:	fclean	$(NAME)