C = clang

NAME = libftprintf.a
LIBFT = libft
LIBFT_LIB = libft.a

SRCS = ./ft_printf.c\
		ft_printf_utils.c\
		ft_printf_parser.c\
		ft_printf_word.c\
		ft_printf_number.c

OBJS = $(SRCS:.c=.o)

CC = gcc
CFLAGS = -Wall -Wextra -Werror

$(NAME):
	gcc $(CFLAGS) -c $(SRCS) -I ./
	ar rc $(NAME) $(OBJS)

all:
	$(NAME)

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all
