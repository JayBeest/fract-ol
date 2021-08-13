NAME = fractol
OBJ_C = fractol.c
HEADER_FILES = fractol.h libft.h
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
	rm -f a.out

re: fclean make
