#include "../Headers/so_long.h"

void	ft_move(t_mlx *mlx, int key, void *img_background)
{
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, img_background,
		(mlx->player.x * 32), (mlx->player.y * 32));
	if (key == KEY_W && mlx->map.matriz[mlx->player.y - 1][mlx->player.x] != '1'
   		&& (mlx->map.matriz[mlx->player.y - 1][mlx->player.x] != 'E' || mlx->map.n_collects == 0))
   		mlx->player.y -= 1;
 	else if (key == KEY_S && mlx->map.matriz[mlx->player.y + 1][mlx->player.x] != '1'
		&& (mlx->map.matriz[mlx->player.y + 1][mlx->player.x] != 'E' || mlx->map.n_collects == 0))
		mlx->player.y += 1;
	else if (key == KEY_A && mlx->map.matriz[mlx->player.y][mlx->player.x - 1] != '1'
		&& (mlx->map.matriz[mlx->player.y][mlx->player.x - 1] != 'E' || mlx->map.n_collects == 0))
		mlx->player.x -= 1;
	else if (key == KEY_D && mlx->map.matriz[mlx->player.y][mlx->player.x + 1] != '1'
		&& (mlx->map.matriz[mlx->player.y][mlx->player.x + 1] != 'E' || mlx->map.n_collects == 0))
		mlx->player.x += 1;
	if (mlx->map.matriz[mlx->player.y][mlx->player.x + 1] == 'C')
		ft_delete_collect(mlx, mlx->player, mlx->map.collectibles);
	ft_change_player_texture(mlx, key);
	ft_printf("You moved %d times.\n", ++mlx->moves);
	mlx_do_sync(mlx->mlx_ptr);
	ft_win_game(mlx);
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
	else if (keycode == KEY_W || keycode == KEY_S
		|| keycode == KEY_A || keycode == KEY_D)
		ft_move(mlx, keycode, img_background);
	return (0);
}

void	ft_render_map(t_mlx *mlx)
{
	mlx_hook(mlx->win_ptr, 17, 1L << 2, ft_exit_fail, mlx);
	mlx_key_hook(mlx->win_ptr, ft_key_hook, mlx);
}
