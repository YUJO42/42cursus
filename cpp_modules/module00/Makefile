# BASIC ========================================================================
NAME 		= yellowpages

# SRCS
SRCS_DIR	= SRCS/
SRCS		= Yellowpages.cpp Contact.cpp

# INCLUDES
INCS_DIR	= INCS/
INCS		= Yellowpages.hpp

# FLAGS
INCLUDES	= -I.$(addprefix $(INCS_DIR), $(INCS))
FLAGS 		= -Wall -Wextra -Werror $(INCLUDES)

# OBJS
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

.PHONY: all clean fclean re
