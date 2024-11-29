NAME = so_long

SRCS = main.c

OBJS = $(SRCS:.c=.o)

CC = gcc
CFLAGS = -Wall -Wextra -Werror -Iincludes -Iminilibx-linux

MLX = minilibx-linux/libmlx_Linux.a
LIBS = -Lminilibx-linux -lmlx_Linux -L/usr/lib -lXext -lX11 -lm -lbsd

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(MLX) $(LIBS) -o $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all