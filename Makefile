NAME = fractol
OBJ_C = fractol.c
HEADER_FILES = fractol.h
CFLAGS = -Wall -Wextra -Werror
OBJ = $(OBJ_C:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(OBJ) -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME)

%.o:%.c $(HEADER_FILES)
	$(CC) $(CFLAGS) -Imlx -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f a.out

re: fclean make
