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

void	ft_free_player(t_mlx *mlx, t_player *player)
{
	if (player->img_up)
		mlx_destroy_image(mlx->mlx_ptr, player->img_up);
	if (player->img_down)
		mlx_destroy_image(mlx->mlx_ptr, player->img_down);
	if (player->img_left)
		mlx_destroy_image(mlx->mlx_ptr, player->img_left);
	if (player->img_right)
		mlx_destroy_image(mlx->mlx_ptr, player->img_right);
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
	ft_free_map(&mlx->map);
	ft_free_player(mlx, &mlx->player);
	mlx_destroy_image(mlx->mlx_ptr, mlx->map.collectibles[0].img);
	free(mlx->map.collectibles);
	if (mlx->map.exit.img)
		mlx_destroy_image(mlx->mlx_ptr, mlx->map.exit.img);
	if (mlx->map.exit.img_out)
		mlx_destroy_image(mlx->mlx_ptr, mlx->map.exit.img_out);
	mlx_destroy_image(mlx->mlx_ptr, mlx->map.wall[0].img);
	free(mlx->map.wall);
	if (mlx->win_ptr)
		mlx_destroy_window(mlx->mlx_ptr, mlx->win_ptr);
	if (mlx->mlx_ptr)
	{
		mlx_destroy_display(mlx->mlx_ptr);
		free(mlx->mlx_ptr);
	}
	exit(0);
}

void	ft_free_all_exit(t_mlx *mlx)
{
	ft_free_map(&mlx->map);
	ft_free_player(mlx, &mlx->player);
	mlx_destroy_image(mlx->mlx_ptr, mlx->map.collectibles[0].img);
	free(mlx->map.collectibles);
	if (mlx->map.exit.img)
		mlx_destroy_image(mlx->mlx_ptr, mlx->map.exit.img);
	if (mlx->map.exit.img_out)
		mlx_destroy_image(mlx->mlx_ptr, mlx->map.exit.img_out);
	mlx_destroy_image(mlx->mlx_ptr, mlx->map.wall[0].img);
	free(mlx->map.wall);
	if (mlx->win_ptr)
		mlx_destroy_window(mlx->mlx_ptr, mlx->win_ptr);
	if (mlx->mlx_ptr)
	{
		mlx_destroy_display(mlx->mlx_ptr);
		free(mlx->mlx_ptr);
	}
	exit(0);
}