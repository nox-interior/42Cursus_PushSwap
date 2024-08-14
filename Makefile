NAME			= push_swap

# Directories
LIBFT			= ./libft/libft.a
INC				= inc/
SRC_DIR			= src/
OBJ_DIR			= obj/

# Compiler and Flags
CC				= gcc
CFLAGS			= -Wall -Wextra -Werror -I
RM				= rm -f

# Source Files
OPERATIONS_DIR	= $(SRC_DIR)operations/push.c \
				  $(SRC_DIR)operations/reverse_rotate.c \
				  $(SRC_DIR)operations/rotate.c \
				  $(SRC_DIR)operations/swap.c
					
ALGORITHM_DIR	= $(SRC_DIR)algorithm/01_free.c \
				  $(SRC_DIR)algorithm/02_small_sort.c \
				  $(SRC_DIR)algorithm/03_assign_index.c \
				  $(SRC_DIR)algorithm/04_error_check.c \
				  $(SRC_DIR)algorithm/05_init_stack.c \
				  $(SRC_DIR)algorithm/06_big_sort_push_to_b.c \
				  $(SRC_DIR)algorithm/07_big_sort_assign_position.c \
				  $(SRC_DIR)algorithm/08_big_sort_find_target.c \
				  $(SRC_DIR)algorithm/09_big_sort_moves.c \
				  $(SRC_DIR)algorithm/10_big_sort_optimal_move.c \
				  $(SRC_DIR)algorithm/11_big_sort_adjust_and_sort.c \
				  $(SRC_DIR)algorithm/main.c

# Concatenate all source files
SRC 			= $(OPERATIONS_DIR) $(ALGORITHM_DIR)

# Generate object files
OBJ 			= $(SRC:$(SRC_DIR)%.c=$(OBJ_DIR)%.o)

# Build rules
all:			$(NAME)
	
$(LIBFT):
	@make -C ./libft

$(NAME): 		$(OBJ) $(LIBFT)
	@$(CC) $(CFLAGS) $(INC) $(OBJ) $(LIBFT) -o $(NAME)

# Compile object files from source files
$(OBJ_DIR)%.o:	$(SRC_DIR)%.c
	@mkdir -p $(@D)
	@$(CC) $(CFLAGS) $(INC) -c $< -o $@
					
clean:
	@$(RM) -r $(OBJ_DIR)
	@make clean -C ./libft

fclean: 		clean
	@$(RM) $(NAME)
	@$(RM) $(LIBFT)

re: 			fclean all

# Phony targets represent actions not files
.PHONY: 		all clean fclean re