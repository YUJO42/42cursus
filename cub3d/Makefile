# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yujo <yujo@student.42seoul.kr>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/09/02 16:48:45 by yujo              #+#    #+#              #
#    Updated: 2020/09/02 16:48:45 by yujo             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS =	./srcs/do_end.c					\
		./srcs/do_key.c					\
		./srcs/get_next_line.c			\
		./srcs/get_next_line_utils.c	\
		./srcs/init.c					\
		./srcs/main.c					\
		./srcs/map_check.c				\
		./srcs/parse.c					\
		./srcs/parse_2.c				\
		./srcs/render.c					\
		./srcs/render_2.c				\
		./srcs/save_bmp.c				\
		./srcs/sprite.c					\

OBJS =	$(SRCS:.c=.o)

INCLUDES = ./includes

CC = gcc

CFLAGS = -Wall -Werror -Wextra

XMLFLAGS = -I /usr/local/include -L /usr/local/lib -lmlx -framework OpenGL -framework Appkit -L ./libft -lft

NAME = cub3D

RM = rm -rf

.c.o :
		$(CC) $(CFLAGS) -c $< -o $(<:.c=.o) -I $(INCLUDES)

all : $(NAME)

$(NAME) : $(OBJS)
		$(CC) $(CFLAGS) $(XMLFLAGS) $(OBJS) -o $(NAME)

clean :
		$(RM) $(NAME)

fclean : clean
		$(RM) $(OBJS)

re : fclean all

bonus : all

.PHONY : all clean fclean re bonus
