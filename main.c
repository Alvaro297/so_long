#include "minilibx-linux/mlx.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct	s_vars {
	void	*mlx;
	void	*win;
}				t_vars;

void print_t_vars(t_vars *vars)
{
	printf("mlx: %p, win: %p\n", vars->mlx, vars->win);
}

int	key_hook(int keycode, t_vars *vars)
{
	printf("codigo de key %i\n", keycode);
	if (keycode == 65307)
	{
		mlx_destroy_window(vars->mlx ,vars->win);
		exit(0);
	}
	print_t_vars(vars);
	printf("Hello from key_hook!\n");
	return (0);
}

int	mouse_hook(int button, int x, int y, t_vars *vars)
{
	printf("Mouse button: %i, Position: (%d, %d)\n", button, x, y);
	print_t_vars(vars);
	printf("Hello from mouse_hook!\n");
	return (0);
}

int	main(void)
{
	t_vars	vars;

	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, 640, 480, "Hello world!");
	mlx_key_hook(vars.win, key_hook, &vars);
	mlx_mouse_hook(vars.win, mouse_hook, &vars);
	mlx_loop(vars.mlx);
}
