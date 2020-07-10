# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yujo <yujo@student.42seoul.kr>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/07/11 03:16:49 by yujo              #+#    #+#              #
#    Updated: 2020/07/11 06:18:37 by yujo             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	:= gnl
SRCS	:= main.c get_next_line.c get_next_line_utils.c
SRCS	:= main.c get_next_line_bonus.c get_next_line_utils_bonus.c
OBJS	:= $(SRCS:.c=.o)
CC		:= gcc
FLAGS	:= -Wall -Werror -Wextra -g3 -D BUFFER_SIZE=48

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(OBJS) -o $@

%.o: %.c
	$(CC) $(FLAGS) -o $@ -c $<

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re:     fclean all

.PHONY: all clean fclean re
