# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yujo <yujo@student.42seoul.kr>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/21 15:16:41 by yujo              #+#    #+#              #
#    Updated: 2020/09/02 17:15:15 by yujo             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = ./ft_memset.c    \
       ./ft_strrchr.c	\
       ./ft_bzero.c	    \
       ./ft_strnstr.c	\
       ./ft_memcpy.c	\
       ./ft_strncmp.c	\
       ./ft_memccpy.c	\
       ./ft_atoi.c      \
       ./ft_memmove.c	\
       ./ft_isalpha.c	\
       ./ft_memchr.c 	\
       ./ft_isdigit.c	\
       ./ft_memcmp.c    \
       ./ft_isalnum.c	\
       ./ft_strlen.c    \
       ./ft_isascii.c	\
       ./ft_strlcpy.c	\
       ./ft_isprint.c	\
       ./ft_strlcat.c	\
       ./ft_toupper.c	\
       ./ft_strchr.c    \
       ./ft_tolower.c	\
       ./ft_calloc.c    \
       ./ft_strdup.c    \
       ./ft_substr.c    \
       ./ft_strtrim.c   \
       ./ft_split.c     \
       ./ft_itoa.c      \
       ./ft_strmapi.c   \
       ./ft_putchar_fd.c\
       ./ft_putstr_fd.c \
       ./ft_putendl_fd.c\
       ./ft_putnbr_fd.c \

SRCS_B =	./ft_lstnew.c        \
       		./ft_lstadd_front.c  \
       		./ft_lstsize.c       \
       		./ft_lstlast.c       \
       		./ft_lstadd_back.c   \
       		./ft_lstdelone.c     \
       		./ft_lstclear.c      \
       		./ft_lstiter.c       \
       		./ft_lstmap.c        \

OBJS = $(SRCS:.c=.o)

OBJS_B = $(SRCS_B:.c=.o)

NAME = libft.a

CC = gcc

CFLAGS = -Wall -Werror -Wextra -I .

RM = rm -rf

ifdef WITH_BONUS
	OBJ_FILES = $(OBJS) $(OBJS_B)
else
	OBJ_FILES = $(OBJS)
endif

all 	:	$(NAME)

$(NAME)	:	$(OBJ_FILES)
		ar rc $(NAME) $(OBJ_FILES)

bonus :
	make WITH_BONUS=1 all

clean :
		$(RM) $(OBJS) $(OBJS_B)

fclean : clean
		$(RM) $(NAME)

re : fclean all

.PHONY : all clean fclean re bonus
