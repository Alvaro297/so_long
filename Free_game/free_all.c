/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvamart <alvamart@student.42madrid.com>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-12-14 18:21:13 by alvamart          #+#    #+#             */
/*   Updated: 2024-12-14 18:21:13 by alvamart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Headers/so_long.h"

void	ft_free_player(t_player *player)
{
	free(player->img_up);
	free(player->img_down);
	free(player->img_left);
	free(player->img_right);
}

static void	ft_free_collect(t_collectible *collectibles)
{
	t_collectible	*tmp;

	while (collectibles)
	{
		tmp = collectibles->next;
		free(collectibles->img);
		free(collectibles);
		collectibles = tmp;
	}
}

static void	ft_free_wall(t_wall *wall)
{
	int	i;

	i = 0;
	while (i < wall->x)
	{
		free(wall[i].img);
		i++;
	}
}

void	ft_free_map(t_map *map)
{
	int	i;

	i = 0;
	while (i < map->height)
		free(map->matriz[i++]);
	free(map->matriz);
}

void	ft_free_all(t_mlx *mlx)
{
	if (mlx->win_ptr)
		mlx_destroy_window(mlx->mlx_ptr, mlx->win_ptr);
	if (mlx->mlx_ptr)
	{
		mlx_destroy_display(mlx->mlx_ptr);
		free(mlx->mlx_ptr);
	}
	ft_free_map(&mlx->map);
	ft_free_collect(mlx->map.collectibles);
	ft_free_wall(mlx->map.wall);
	free(mlx->map.wall);
	ft_free_player(&mlx->player);
	mlx_destroy_window(mlx->mlx_ptr, mlx->win_ptr);
	exit(0);
}
