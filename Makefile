CC = cc
FLAGS = -Wall -Wextra -Werror
SRCS = Mandatory/fractol.c \
		Mandatory/fractol_utils.c \
		Mandatory/libft1.c \
		Mandatory/close_mlx.c \
		Mandatory/fractol_utils2.c \
		Mandatory/mandelbrot.c \
		Mandatory/Julia.c
BON = Bonus/fractol_bonus.c \
		Bonus/fractol_bonus_utils.c \
		Bonus/libft1.c \
		Bonus/close_mlx.c \
		Bonus/fractol_bonus_utils2.c \
		Bonus/mandelbrot.c \
		Bonus/Julia.c \
		Bonus/burning_ship.c \
		Bonus/events.c
OBJECTS = $(SRCS:.c=.o)
OBJECTS_BON = $(BON:.c=.o)
NAME = fractol
NAME_BON = fractol_bonus
HEADER = Mandatory/fractol.h
HEADER_BON = Bonus/fractol_bonus.h

all : $(NAME)

bonus : $(NAME_BON)

$(NAME): $(OBJECTS)
	$(CC) $(FLAGS) $(OBJECTS) -Lmlx_linux -lmlx_Linux -L/home/ihamani/.local/lib -Imlx_linux -lXext -lX11 -lm -lz -o $(NAME)

$(NAME_BON): $(OBJECTS_BON)
	$(CC) $(FLAGS) $(OBJECTS_BON) -Lmlx_linux -lmlx_Linux -L/home/ihamani/.local/lib -Imlx_linux -lXext -lX11 -lm -lz -o $(NAME_BON)

Mandatory/%.o: Mandatory/%.c $(HEADER)
	$(CC) $(FLAGS) -I/home/ihamani/.local/include -Imlx_linux -O3 -c $< -o $@

Bonus/%.o: Bonus/%.c $(HEADER_BON)
	$(CC) $(FLAGS) -I/home/ihamani/.local/include -Imlx_linux -O3 -c $< -o $@

clean:
	rm -rf $(OBJECTS) $(OBJECTS_BON)

fclean: clean
	rm -rf $(NAME) $(NAME_BON)

re: fclean  all

.PHONY: fclean clean re