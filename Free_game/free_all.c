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

/*
static void	ft_free_collect(t_collectible *collectibles, int n_collects)
{
	int		i;

	i = 0;
	while (i < n_collects)
	{
        ft_printf("Checking collectible %d at position: (%d, %d), address: %p\n", i, collectibles[i].x, collectibles[i].y, (void *)collectibles[i].img);
		i++;
	}
	free(collectibles);
}

static void	ft_free_wall(t_wall *wall, int n_wall)
{
	int	i;

	i = 0;
	while (i < n_wall)
	{
		free(wall[i].img);
		i++;
	}
	free(wall);
}*/

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
	ft_free_player(&mlx->player);
	free(mlx->map.collectibles[0].img);
	free(mlx->map.collectibles);
	free(mlx->map.wall[0].img);
	free(mlx->map.wall);
	exit(0);
}
