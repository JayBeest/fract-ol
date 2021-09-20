NAME = fractol
OBJ_C = main.c \
		parser.c \
		draw.c \
		utils.c \
		fractols.c \
		colour.c \
		hooks.c \
		actions.c \
		menu.c
C_FLAGS = -g -Wall -Wextra -Werror
SRCS_PATH = ./srcs/

OBJ = $(OBJ_C:%.c=$(SRCS_PATH)%.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(MAKE) -C ./libft
	$(MAKE) -C ./mlx
	$(CC) -o $@ $^ $(C_FLAGS) -Lmlx -Llibft -lmlx -lft \
					-framework OpenGL -framework AppKit

%.o: %.c
	$(CC) -o $@ $< $(C_FLAGS) -Imlx -Ilibft -c

clean:
	rm -f $(OBJ)

fclean: clean
	$(MAKE) fclean -C ./libft
	$(MAKE) clean -C ./mlx
	rm -f $(NAME)

re: clean all
