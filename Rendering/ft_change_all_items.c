/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_change_all_items.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvamart <alvamart@student.42madrid.com>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-12-14 17:32:01 by alvamart          #+#    #+#             */
/*   Updated: 2024-12-14 17:32:01 by alvamart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Headers/so_long.h"

static void	ft_print_exit(t_mlx *mlx)
{
	if (mlx->map.n_collects == 0)
	{
		mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr,
			mlx->map.exit.img_out, (mlx->map.exit.width * TILE_SIZE),
			(mlx->map.exit.height * TILE_SIZE));
	}
}

void	ft_delete_collect(t_mlx *mlx)
{
	int	i;
	int	j;

	i = 0;
	while (i < mlx->map.n_collects)
	{
		if (mlx->map.collectibles[i].x == mlx->player.x
			&& mlx->map.collectibles[i].y == mlx->player.y)
		{
			j = i;
			while (j < mlx->map.n_collects - 1)
			{
				mlx->map.collectibles[j] = mlx->map.collectibles[j];
				j++;
			}
			mlx->map.n_collects--;
			ft_print_exit(mlx);
			return ;
		}
		i++;
	}
}

void	ft_change_player_texture(t_mlx *mlx, t_player player, int key)
{
	if (key == KY_W)
	{
		mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr,
			player.img_down, (mlx->player.y * 32), (mlx->player.x * 32));
	}
	else if (key == KY_S)
	{
		mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr,
			player.img_up, (mlx->player.y * 32), (mlx->player.x * 32));
	}
	else if (key == KY_A)
	{
		mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr,
			player.img_left, (mlx->player.y * 32), (mlx->player.x * 32));
	}
	else if (key == KY_D)
	{
		mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr,
			player.img_right, (mlx->player.y * 32), (mlx->player.x * 32));
	}
}
