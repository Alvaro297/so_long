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

void	ft_free_all(t_mlx *mlx)
{
	int	i;

	i = 0;
	while (i < mlx->map.height)
		free(mlx->map.matriz[i++]);
	free(mlx->map.matriz);
	i = 0;
	ft_free_collect(mlx->map.collectibles);
	ft_free_wall(mlx->map.wall);
	free(mlx->map.wall);
	ft_free_player(&mlx->player);
	mlx_destroy_window(mlx->mlx_ptr, mlx->win_ptr);
	exit(0);
}

void	ft_free_player(t_player *player)
{
	free(player->img_up);
	free(player->img_down);
	free(player->img_left);
	free(player->img_right);
}

void	ft_free_collect(t_collectible *collectibles)
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

void	ft_free_wall(t_wall *wall)
{
	int	i;

	i = 0;
	while (i < wall->x)
	{
		free(wall[i].img);
		i++;
	}
}