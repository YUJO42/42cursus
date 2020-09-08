SRCS = 	./srcs/ft_strlen.s	\
		./srcs/ft_strcpy.s	\
		./srcs/ft_strcmp.s 	\
		./srcs/ft_write.s	\
		./srcs/ft_read.s 	\
		./srcs/ft_strdup.s	\

OBJS = $(SRCS:.s=.o)

NAME = libasm.a

NASM = nasm -f macho64

RM = rm -rf

OBJ_FILES = $(OBJS)


.s.o :
		$(NASM) $<

all : $(NAME)

$(NAME) : $(OBJ_FILES)
	ar rcs $(NAME) $(OBJ_FILES)

clean :
	$(RM) $(OBJS) $(OBJS_B)

fclean : clean
	$(RM) $(NAME)

re : fclean all

.PHONY : all clean fclean re bonus
