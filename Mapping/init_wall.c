/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_wall.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvamart <alvamart@student.42madrid.com>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-12-10 18:14:08 by alvamart          #+#    #+#             */
/*   Updated: 2024-12-10 18:14:08 by alvamart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Headers/so_long.h"

void	ft_wall_start(t_mlx *mlx, t_map *map)
{
	t_wall	*wall;

	wall = malloc(sizeof(t_wall) * map->n_collects);
	if (!wall)
	{
		perror("Error\nmalloc failed\n");
		exit(1);
	}
	ft_localization_wall(mlx, wall);
	map->wall = wall;
}

void	ft_localization_wall(t_mlx *mlx, t_collectible *collec)
{
	int		x;
	int		y;
	int		index;
	void	*wall_img;

	x = 0;
	index = 0;
	wall_img = mlx_xpm_file_to_image(mlx->mlx_ptr, COLLEC_PATH, 32, 32);
	while (mlx->map.matriz[x])
	{
		y = 0;
		while (mlx->map.matriz[x][y])
		{
			if (mlx->map.matriz[x][y] == '1')
			{
				collec[index].x = x;
				collec[index].y = y;
				collec[index].is_catched = 1;
				collec[index].img = wall_img;
				index++;
			}
			y++;
		}
		x++;
	}
}
