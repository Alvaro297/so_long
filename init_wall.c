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

#include "Headers/so_long.h"

static void	ft_localization_wall(t_mlx *mlx, t_wall *wall, int x, int y)
{
	int		img_height;
	int		img_width;
	int		index;
	void	*wall_img;

	index = 0;
	wall_img = mlx_xpm_file_to_image(mlx->mlx_ptr, WALL_PATH,
			&img_width, &img_height);
	while (mlx->map.matriz[x])
	{
		y = 0;
		while (mlx->map.matriz[x][y])
		{
			if (mlx->map.matriz[x][y] == '1')
			{
				wall[index].height = x;
				wall[index].width = y;
				wall[index].img = wall_img;
				index++;
			}
			y++;
		}
		x++;
	}
}


void	ft_wall_start(t_mlx *mlx, t_map *map)
{
	t_wall	*wall;

	wall = malloc(sizeof(t_wall) * map->n_wall);
	if (!wall)
	{
		perror("Error\nmalloc failed\n");
		free(wall);
		exit(1);
	}
	ft_localization_wall(mlx, wall, 0, 0);
	mlx->map.wall = wall;
}
