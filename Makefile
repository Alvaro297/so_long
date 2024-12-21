CC = gcc
CFLAGS = -Wall -Wextra -Werror -I$(INCDIR) -I$(MLXDIR)
NAME = so_long

# Directorios
SRCDIRS = Endgame Free_game Init_game Rendering Draw_images  Validating libft
INCDIR = includes
MLXDIR = minilibx-linux

# Archivos fuente
SRCS = $(wildcard Endgame/*.c) \
		$(wildcard Free_game/*.c) \
		$(wildcard Init_game/*.c) \
		$(wildcard Rendering/*.c) \
		$(wildcard Draw_images/*.c) \
		$(wildcard Validating/*.c) \
		$(wildcard libft/*.c) \
		init_all.c \
		init_mapping.c \
		init_wall.c \
		draw_images.c \
		ft_exit_start.c \
		main.c


# Archivos objeto
OBJS = $(SRCS:.c=.o)

FT_PRINTF_DIR = ./libft/ft_printf_so_long
FT_PRINTF = $(FT_PRINTF_DIR)/libftprintf.a

# Librerías
MLX = $(MLXDIR)/libmlx.a
LIBS = -L$(MLXDIR) -lmlx_Linux -L/usr/lib -lXext -lX11 -lm -lbsd

# Reglas
all: $(NAME)

$(NAME): $(OBJS) $(FT_PRINTF)
	$(CC) $(CFLAGS) $(OBJS) $(MLX) $(LIBS) $(FT_PRINTF) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(FT_PRINTF):
	make -C $(FT_PRINTF_DIR)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re