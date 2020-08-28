# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yujo <yujo@student.42seoul.kr>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/04/07 20:50:35 by yujo              #+#    #+#              #
#    Updated: 2020/04/09 20:42:41 by yujo             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

TARGET = libft.a
SRCS = ft_strlen.c ft_atoi.c ft_toupper.c ft_tolower.c ft_strdup.c\
	   ft_memset.c ft_bzero.c ft_memcpy.c ft_isalpha.c ft_isdigit.c ft_isalnum.c\
	   ft_isascii.c ft_isprint.c ft_itoa.c ft_calloc.c ft_strncmp.c ft_strlcpy.c\
	   ft_strlcat.c ft_memccpy.c ft_memmove.c ft_memchr.c ft_memcmp.c ft_strchr.c\
	   ft_strrchr.c ft_strnstr.c ft_strjoin.c ft_substr.c ft_strtrim.c ft_split.c\
	   ft_strmapi.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c
BSRCS = ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c\
		ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c
OBJS = ${SRCS:.c=.o}
BOBJS = ${BSRCS:.c=.o}
CC = gcc
RM = rm -f
CFLAGS = -Wall -Wextra -Werror
INC = libft.h
SO = libft.so

%.o : %.c ${INC}
		${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

$(TARGET): ${OBJS}
		ar rcs $@ ${OBJS}

all: ${TARGET}

bonus: ${BOBJS} ${OBJS}
		ar rcs ${TARGET} ${OBJS} ${BOBJS}

clean:
		${RM} ${OBJS} ${BOBJS}

fclean:	clean
		${RM} ${TARGET} ${TEST}

re: fclean all
