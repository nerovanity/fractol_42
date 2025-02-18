CC = cc
FLAGS = -Wall -Wextra -Werror
SRCS = fractol.c \
		fractol_utils.c \
		libft1.c \
		close_mlx.c \
		fractol_utils2.c \
		mandelbrot.c \
		Julia.c
OBJECTS = $(SRCS:.c=.o)
NAME = fractol
HEADER = fractol.h

all : $(NAME)

$(NAME): $(OBJECTS)
	$(CC) $(FLAGS) $(OBJECTS) -Lmlx_linux -lmlx_Linux -L/home/ihamani/.local/lib -Imlx_linux -lXext -lX11 -lm -lz -o $(NAME)

%.o: %.c $(HEADER)
	$(CC) $(FLAGS) -I/home/ihamani/.local/include -Imlx_linux -O3 -c $< -o $@

clean:
	rm -rf $(OBJECTS)

fclean: clean
	rm -rf $(NAME)

re: fclean  all

.PHONY: fclean clean re