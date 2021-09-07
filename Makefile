NAME = fractol
OBJ_C = main.c utils.c fractols.c menu.c hooks.c draw.c parser.c actions.c colour.c
HEADER_FILES = main.h datatypes.h libft.h utils.h fractols.h menu.h hooks.h draw.h parser.h actions.h colour.h
CFLAGS = -g -Wall -Wextra -Werror
SRCS_PATH = ./srcs/

OBJ = $(OBJ_C:%.c=$(SRCS_PATH)%.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(MAKE) -C ./libft
	$(CC) -o $@ $^ $(CFLAGS) -Lmlx -Llibft -lmlx -lft -framework OpenGL -framework AppKit

%.o:%.c $(HEADER_FILES)
	$(CC) -o $@ $< $(CFLAGS) -Imlx -Ilibft -c

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
