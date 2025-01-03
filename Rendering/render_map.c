/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvamart <alvamart@student.42madrid.com>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-12-14 17:18:32 by alvamart          #+#    #+#             */
/*   Updated: 2024-12-14 17:18:32 by alvamart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Headers/so_long.h"

static void	ft_has_moved(t_mlx *mlx, int key)
{
	if (mlx->map.matriz[mlx->player.x - 1][mlx->player.y] != '1' &&
		key == KY_W && (mlx->map.matriz[mlx->player.x - 1][mlx->player.y] != 'E'
		|| mlx->map.n_collects == 0))
		ft_printf("Movements: %d\n", ++mlx->moves);
	else if (mlx->map.matriz[mlx->player.x + 1][mlx->player.y] != '1' &&
		key == KY_S && (mlx->map.matriz[mlx->player.x + 1][mlx->player.y] != 'E'
		|| mlx->map.n_collects == 0))
		ft_printf("Movements: %d\n", ++mlx->moves);
	else if (mlx->map.matriz[mlx->player.x][mlx->player.y - 1] != '1' &&
		key == KY_A && (mlx->map.matriz[mlx->player.x][mlx->player.y - 1] != 'E'
		|| mlx->map.n_collects == 0))
		ft_printf("Movements: %d\n", ++mlx->moves);
	else if (mlx->map.matriz[mlx->player.x][mlx->player.y + 1] != '1' &&
		key == KY_D && (mlx->map.matriz[mlx->player.x][mlx->player.y + 1] != 'E'
		|| mlx->map.n_collects == 0))
		ft_printf("Movements: %d\n", ++mlx->moves);
}

void	ft_move(t_mlx *mlx, t_player player, int key, void *img_background)
{
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, img_background,
		(mlx->player.y * TILE_SIZE), (mlx->player.x * TILE_SIZE));
	ft_has_moved(mlx, key);
	if (mlx->map.matriz[mlx->player.x - 1][mlx->player.y] != '1' &&
		key == KY_W && (mlx->map.matriz[mlx->player.x - 1][mlx->player.y] != 'E'
		|| mlx->map.n_collects == 0))
		mlx->player.x -= 1;
	else if (mlx->map.matriz[mlx->player.x + 1][mlx->player.y] != '1' &&
		key == KY_S && (mlx->map.matriz[mlx->player.x + 1][mlx->player.y] != 'E'
		|| mlx->map.n_collects == 0))
		mlx->player.x += 1;
	else if (mlx->map.matriz[mlx->player.x][mlx->player.y - 1] != '1' &&
		key == KY_A && (mlx->map.matriz[mlx->player.x][mlx->player.y - 1] != 'E'
		|| mlx->map.n_collects == 0))
		mlx->player.y -= 1;
	else if (mlx->map.matriz[mlx->player.x][mlx->player.y + 1] != '1' &&
		key == KY_D && (mlx->map.matriz[mlx->player.x][mlx->player.y + 1] != 'E'
		|| mlx->map.n_collects == 0))
		mlx->player.y += 1;
	mlx_destroy_image(mlx->mlx_ptr, img_background);
	if (mlx->map.matriz[mlx->player.x][mlx->player.y] == 'C')
		ft_delete_collect(mlx);
	mlx_do_sync(mlx->mlx_ptr);
	ft_validate_win_lose_game(mlx);
	ft_change_player_texture(mlx, player, key);
}

int	ft_key_hook(int keycode, t_mlx *mlx)
{
	int		img_width;
	int		img_height;
	void	*img_background;

	img_background = mlx_xpm_file_to_image(mlx -> mlx_ptr, GRASS_PATH,
			&img_width, &img_height);
	if (keycode == ESC)
	{
		mlx_destroy_image(mlx->mlx_ptr, img_background);
		ft_exit_fail(mlx);
	}
	else if (keycode == KY_W || keycode == KY_UP)
		ft_move(mlx, mlx->player, KY_W, img_background);
	else if (keycode == KY_S || keycode == KY_DOWN)
		ft_move(mlx, mlx->player, KY_S, img_background);
	else if (keycode == KY_A || keycode == KY_LEFT)
		ft_move(mlx, mlx->player, KY_A, img_background);
	else if (keycode == KY_D || keycode == KY_RIGHT)
		ft_move(mlx, mlx->player, KY_D, img_background);
	return (0);
}

void	ft_render_map(t_mlx *mlx)
{
	mlx_hook(mlx->win_ptr, 17, 1L << 2, ft_exit_fail, mlx);
	mlx_key_hook(mlx->win_ptr, ft_key_hook, mlx);
}
