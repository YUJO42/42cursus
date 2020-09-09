SRCS = 	./src/ft_strlen.s	\
		./src/ft_strcpy.s	\
		./src/ft_strcmp.s 	\
		./src/ft_write.s	\
		./src/ft_read.s 	\
		./src/ft_strdup.s	\

OBJS = $(SRCS:.s=.o)

NAME = libasm.a

NASM = nasm -f macho64

RM = rm -rf

OBJ_FILES = $(OBJS)


.s.o	:
		$(NASM) $<

all		: $(NAME)

$(NAME)	: $(OBJ_FILES)
	ar rcs $(NAME) $(OBJ_FILES)

clean	:
	$(RM) $(OBJS) $(OBJS_B)

fclean : clean
	$(RM) $(NAME)

re 		: fclean all

test	:	re
			$(CC) -o libasm_tester libasm_tester.c -L. -lasm
			./libasm_tester

.PHONY : all clean fclean re bonus
