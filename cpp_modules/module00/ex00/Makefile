NAME 		= megaphone

SRCS_DIR	= ./
SRCS		= megaphone.cpp

FLAGS 		= -Wall -Wextra -Werror

OBJS_DIR 	= OBJS/
OBJ 		= $(SRCS:.cpp=.o)
OBJS		= $(addprefix $(OBJS_DIR), $(OBJ))
# ==============================================================================

# CPP ==========================================================================
$(OBJS_DIR)%.o: $(SRCS_DIR)%.cpp
	@mkdir -p $(OBJS_DIR)
	@echo "Compiling: $<"
	@clang++ $(FLAGS) -c $< -o $@

$(NAME): $(OBJS)
	@clang++ $(FLAGS) $(OBJS) -o $(NAME)

all: $(NAME)

clean:
	@echo "Cleaning: $(OBJS_DIR)"
	@rm -rf $(OBJS_DIR)

fclean: clean
	@echo "Cleaning: $(NAME)"
	@rm -f $(NAME)

re: fclean all
# ==============================================================================

# TEST =========================================================================
test: $(NAME)
	@/bin/echo
	@/bin/echo "Original  < shhhhh... I think the students are asleep..."
	@/bin/echo "Expected  : SHHHHH... I THINK THE STUDENTS ARE ASLEEP..."
	@/bin/echo -n "Megaphone : "
	@./$(NAME) "shhhhh... I think the students are asleep..."
	@/bin/echo
	@/bin/echo "Original  < Damnit \" ! \" \"Sorry students, I thought this thing was off.\""
	@/bin/echo "Expected  : DAMNIT ! SORRY STUDENTS, I THOUGHT THIS THING WAS OFF."
	@/bin/echo -n "Megaphone : "
	@./$(NAME) Damnit " ! " "Sorry students, I thought this thing was off."
	@/bin/echo
	@/bin/echo "Original  < (null)"
	@/bin/echo "Expected  : * LOUD AND UNBEARABLE FEEDBACK NOISE *"
	@/bin/echo -n "Megaphone : "
	@./$(NAME)
	@/bin/echo
# ==============================================================================

.PHONY: all clean fclean re test
