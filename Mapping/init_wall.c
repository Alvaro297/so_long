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

	wall = malloc(sizeof(t_wall) * map->n_wall);
	if (!wall)
	{
		perror("Error\nmalloc failed\n");
		exit(1);
	}
	ft_localization_wall(mlx, wall);
	map->wall = wall;
}

void	ft_localization_wall(t_mlx *mlx, t_wall *wall)
{
	int		x;
	int		y;
	int		index;
	void	*wall_img;

	x = 0;
	index = 0;
	wall_img = mlx_xpm_file_to_image(mlx->mlx_ptr, COLLEC_PATH,
			(int *)32, (int *)32);
	while (mlx->map.matriz[x])
	{
		y = 0;
		while (mlx->map.matriz[x][y])
		{
			if (mlx->map.matriz[x][y] == '1')
			{
				wall[index].x = x;
				wall[index].y = y;
				wall[index].img = wall_img;
				index++;
			}
			y++;
		}
		x++;
	}
}
