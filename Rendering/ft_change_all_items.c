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

void	ft_delete_collect(t_mlx *mlx, t_player player, t_collectible *collec)
{
	t_collectible	*tmp;
	t_collectible	*prev;

	tmp = mlx->map.collectibles;
	prev = mlx->map.collectibles;
	while (tmp)
	{
		if (tmp->x == player.x && tmp->y == player.y)
		{
			if (tmp == mlx->map.collectibles)
				mlx->map.collectibles = tmp->next;
			else
				prev->next = tmp->next;
			free(tmp);
			mlx->map.n_collects--;
			return ;
		}
		prev = tmp;
		tmp = tmp->next;
	}
}

void	ft_change_player_texture(t_mlx *mlx, t_player player, int key)
{
	if (key == KEY_W)
	{
		mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr,
			player.img_up, (player.x * 32), (player.y * 32));
	}
	else if (key == KEY_S)
	{
		mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr,
			player.img_down, (player.x * 32), (player.y * 32));
	}
	else if (key == KEY_A)
	{
		mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr,
			player.img_left, (player.x * 32), (player.y * 32));
	}
	else if (key == KEY_D)
	{
		mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr,
			player.img_right, (player.x * 32), (player.y * 32));
	}
}
