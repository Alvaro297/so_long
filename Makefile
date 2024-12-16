CC = gcc
CFLAGS = -Wall -Wextra -Werror -I$(INCDIR) -I$(MLXDIR)
NAME = so_long

# Directorios
SRCDIRS = Endgame Free_game Init_game Mapping Rendering Draw_images libft
INCDIR = includes
MLXDIR = minilibx-linux

# Archivos fuente
SRCS = $(foreach dir, $(SRCDIRS), $(wildcard $(dir)/*.c)) main.c

# Archivos objeto
OBJS = $(SRCS:.c=.o)

FT_PRINTF_DIR = ./libft/ft_printf_so_long
FT_PRINTF = $(FT_PRINTF_DIR)/libftprintf.a

# Librerías
MLX = $(MLXDIR)/libmlx_Linux.a
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