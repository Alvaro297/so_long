#include "../Headers/so_long.h"

void	ft_move(t_mlx *mlx, int key, int direction, void *img_background)
{
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, img_background,
		(mlx->player.x * 32), (mlx->player.y * 32));
	if (key == 'a' && mlx->map.matriz[mlx->player.x][mlx->player.y-1] != '1'
		&& (mlx->map.matriz[mlx->player.x][mlx->player.y-1] != 'E'
		|| mlx->map.n_collects == 0))
	{
		/* code */
	}
	
}

int		ft_key_hook(int keycode, t_mlx *mlx)
{
	int		img_width;
	int		img_height;
	void	*img_background;
	
	img_background = mlx_xpm_file_to_image(mlx -> mlx_ptr, GRASS_PATH,
			&img_width, &img_height);
	if (keycode == ESC)
		ft_exit_fail(mlx);
	else if (keycode == KEY_A)
		ft_move(mlx, KEY_A, -1, img_background);
	else if (keycode == KEY_D)
		ft_move(mlx, KEY_D, 1, img_background);
	else if (keycode == KEY_W)
		ft_move(mlx, KEY_W, -1, img_background);
	else if (keycode == KEY_S)
		ft_move(mlx, KEY_S, 1, img_background);
	return (0);
}

void	ft_render_map(t_mlx *mlx)
{
	mlx_hook(mlx->win_ptr, 17, 1L << 2, ft_exit_fail, mlx);
	mlx_key_hook(mlx->win_ptr, ft_key_hook, mlx);
}
