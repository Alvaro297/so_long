#include "../Headers/so_long.h"

void	ft_move(t_mlx *mlx, int key, int direction)
{
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, mlx->map,
		(mlx->player.x * 32), (mlx->player.y * 32));
}

int		ft_key_hook(int keycode, t_mlx *mlx)
{
	if (keycode == ESC)
		ft_exit_fail(mlx);
	else if (keycode == KEY_A)
		ft_move(mlx, KEY_A, -1);
	else if (keycode == KEY_D)
		ft_move(mlx, KEY_D, 1);
	else if (keycode == KEY_W)
		ft_move(mlx, KEY_W, -1);
	else if (keycode == KEY_S)
		ft_move(mlx, KEY_S, 1);
	return (0);
}

void	ft_render_map(t_mlx *mlx)
{
	mlx_hook(mlx->win_ptr, 17, 1L << 2, ft_exit_fail, mlx);
	mlx_key_hook(mlx->win_ptr, ft_key_hook, mlx);
}
