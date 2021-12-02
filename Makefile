NAME = 		fractol
SRC = 		main.c \
			parser.c \
			draw.c \
			utils.c \
			fractols.c \
			colour.c \
			hooks.c \
			actions.c \
			menu.c
SRC_DIR =	src
OBJ_DIR	= 	$(SRC_DIR)/obj
INCL = 		-I$(SRC_DIR)/incl
C_FLAGS = 	-Wall -Wextra -Werror -Ofast #-g
OBJ = 		$(SRC:%.c=$(OBJ_DIR)/%.o)

all: $(NAME)

bonus: all

$(NAME): $(OBJ)
	$(MAKE) -C libft
	$(MAKE) -C mlx
	$(CC) -o $@ $^ $(C_FLAGS) -Lmlx -Llibft -lmlx -lft \
					-framework OpenGL -framework AppKit

$(OBJ_DIR)/%.o:$(SRC_DIR)/%.c
	@mkdir -p $(@D)
	$(CC) $< $(C_FLAGS) $(INCL) -Imlx -Ilibft -c -o $@

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	$(MAKE) fclean -C libft
	$(MAKE) clean -C mlx
	rm -f $(NAME)

re: clean all
